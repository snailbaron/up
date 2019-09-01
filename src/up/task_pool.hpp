#pragma once

#include <functional>
#include <vector>

enum class TaskState {
    Running,
    Success,
    Fail,
};

class TaskPool {
public:
    void add(std::function<TaskState(double)>&& task);
    void update(double delta);

private:
    std::vector<std::function<TaskState(double)>> _tasks;
};
