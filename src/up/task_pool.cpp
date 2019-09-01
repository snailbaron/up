#include "task_pool.hpp"

#include <cstddef>
#include <utility>

void TaskPool::add(std::function<TaskState(double)>&& task)
{
    _tasks.push_back(std::move(task));
}

void TaskPool::update(double delta)
{
    for (size_t i = 0; i < _tasks.size(); ) {
        auto state = _tasks.at(i)(delta);
        if (state == TaskState::Running) {
            i++;
        } else {
            std::swap(_tasks[i], _tasks.back());
            _tasks.resize(_tasks.size() - 1);
        }
    }
}
