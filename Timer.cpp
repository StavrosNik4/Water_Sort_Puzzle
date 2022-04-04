#include "Timer.h"

void Timer::start() {
    startTime = std::chrono::steady_clock::now();
}

void Timer::stop() {
    endTime = std::chrono::steady_clock::now();
}

double Timer::getDuration() {
    auto time = endTime - startTime;
    return time / std::chrono::microseconds (1);
}

double Timer::getSec()
{
    auto time = this->getDuration();
    return time/1e+6;
}