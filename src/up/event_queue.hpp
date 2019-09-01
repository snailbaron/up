#pragma once

#include <functional>
#include <map>
#include <memory>
#include <typeindex>
#include <utility>
#include <vector>
#include <tuple>

class BaseSingleTypeEventQueue {
public:
    virtual ~BaseSingleTypeEventQueue() {}
    virtual void send() = 0;
};

template <class Event>
class SingleTypeEventQueue : public BaseSingleTypeEventQueue {
public:
    void subscribe(std::function<void(const Event&)>&& reaction)
    {
        _reactions.push_back(std::move(reaction));
    }

    void push(Event&& event)
    {
        _events.push_back(std::move(event));
    }

    void send() override
    {
        for (const auto& event : _events) {
            for (const auto& reaction : _reactions) {
                reaction(event);
            }
        }
        _events.clear();
    }

private:
    std::vector<Event> _events;
    std::vector<std::function<void(const Event&)>> _reactions;
};

class EventQueue {
public:
    template <class Event>
    void subscribe(std::function<void(const Event&)>&& reaction)
    {
        queue<Event>().subscribe(std::move(reaction));
    }

    template <class Event>
    void push(Event&& event)
    {
        queue<Event>().push(std::move(event));
    }

    void send()
    {
        for (const auto& [typeIndex, queue] : _queues) {
            queue->send();
        }
    }

private:
    template <class Event>
    SingleTypeEventQueue<Event>& queue()
    {
        using Queue = SingleTypeEventQueue<Event>;

        auto typeIndex = std::type_index{typeid(Event)};
        auto it = _queues.find(typeIndex);
        if (it == _queues.end()) {
            std::tie(it, std::ignore) =
                _queues.insert({typeIndex, std::make_unique<Queue>()});
        }
        return *static_cast<Queue*>(it->second.get());
    }

    std::map<std::type_index, std::unique_ptr<BaseSingleTypeEventQueue>>
        _queues;
};
