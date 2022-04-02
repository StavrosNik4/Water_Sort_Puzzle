#ifndef DATA_STRUCTURES_TIMER_H
#define DATA_STRUCTURES_TIMER_H

#include <chrono>


class Timer {


private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;

public:
    void start();
    void stop();
    double getDuration();
    double getSec();
};


#endif //DATA_STRUCTURES_TIMER_H