#ifndef _TOOLS_TIMER_GUARD_H_
#define _TOOLS_TIMER_GUARD_H_

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

#include <boost/thread/pthread/timespec.hpp>

namespace tools
{

class TimerGuard
{
public:
    TimerGuard(const std::string& remark = ""):
        remark_(remark)
    {
        remark_.resize(20, ' ');
        ::clock_gettime(CLOCK_REALTIME, &begin_time_);
    }

    ~TimerGuard()
    {
        ::clock_gettime(CLOCK_REALTIME, &end_time_);
        uint64_t diff_nas = boost::detail::to_nanoseconds_int_max(end_time_) -
                            boost::detail::to_nanoseconds_int_max(begin_time_);
        uint64_t diff_micro = diff_nas / 1000l;
        uint64_t diff_milli = diff_micro / 1000l;
        uint64_t diff_sec = diff_milli / 1000l;
        std::cout << "Tag: "<< remark_ <<", diff_nas: "<< diff_nas;
        if (diff_micro)
            std::cout << ", As micro: " << diff_micro;
        if (diff_milli)
            std::cout << ", As milli: " << diff_milli;
        if (diff_sec)
            std::cout << ", As sec: " << diff_sec;
        
        std::cout << std::endl;
    }

private:
    std::string remark_;

    timespec begin_time_{0};
    timespec end_time_{0};
};

}

#endif