#pragma once

class Ticker {
public:
    Ticker(double period) : _period(period) {}

    int operator()(double delta);

private:
    double _period;
    double _currentTime = 0;
};
