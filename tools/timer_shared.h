#ifndef _TOOLS_TIMER_SHARED_H_
#define _TOOLS_TIMER_SHARED_H_

#include <algorithm>
#include <atomic>
#include <ctime>
#include <string>

#include <boost/thread/pthread/timespec.hpp>

#include "stream.h"

namespace tools
{

struct TimerContainer
{
    TimerContainer(const std::string&str = "")
    {
        remark_ = str;
        remark_.resize(20, ' '); 
    }

    ~TimerContainer() = default;

    void AddTime(uint64_t time)
    {
        diff_time_vector_.emplace_back(time);
    }

    void MergeTime()
    {
        uint64_t nas_val = std::accumulate(diff_time_vector_.begin(), diff_time_vector_.end(), (uint64_t)0);
        nas_val /= diff_time_vector_.size();

        uint64_t diff_micro = nas_val / 1000l;
        uint64_t diff_milli = diff_micro / 1000l;
        uint64_t diff_sec = diff_milli / 1000l;
        stream << "Tag: "<< remark_ <<", times: "<< diff_time_vector_.size() <<", diff_nas: "<< nas_val;
        if (diff_micro)
            stream << ", As micro: " << diff_micro;
        if (diff_milli)
            stream << ", As milli: " << diff_milli;
        if (diff_sec)
            stream << ", As sec: " << diff_sec;
        
        stream << std::endl;
        
        diff_time_vector_.clear();
    }

private:
    std::string remark_;
    std::vector<uint64_t> diff_time_vector_; 
};

struct SharedCount
{
    SharedCount()
    {}

    ~SharedCount()
    {}

    uint32_t AddRef()  { return counter_ ++; }

    uint32_t DelRef() { return counter_ --; }

private:
    std::atomic<uint32_t> counter_{1};
};

class TimerShared
{
public:
    TimerShared(const std::string& str):
        remark_(str),
        ref_conter_(new SharedCount),
        container_(new TimerContainer(str))
    {
    }

    ~TimerShared()
    {
        // todo 自旋锁
        if (ref_conter_->DelRef() == 1)
        {
            container_->MergeTime();
            delete container_;
            delete ref_conter_;
            return;
        }
        // 如果是原始对象先被析构, 不应该加入到计算中
        if (begin_time_.tv_nsec != 0 || begin_time_.tv_sec != 0)
        {
            ::clock_gettime(CLOCK_REALTIME, &end_time_);
            container_->AddTime(
                boost::detail::to_nanoseconds_int_max(end_time_) -
                            boost::detail::to_nanoseconds_int_max(begin_time_)
            );
        }
    }

    TimerShared(const TimerShared& val)
    {
        val.ref_conter_->AddRef();
        this->ref_conter_ = val.ref_conter_;
        this->container_ = val.container_;
        ::clock_gettime(CLOCK_REALTIME, &this->begin_time_);
    }

    TimerShared& operator=(const TimerShared& val) = delete;

    void Reset()
    {
        // 不再进行计算
        memset(&begin_time_, 0, sizeof(timespec));
    }

private:
    timespec begin_time_{0};
    timespec end_time_{0};
    std::string remark_;

    SharedCount*     ref_conter_{nullptr};
    TimerContainer*  container_{nullptr};
}; 

}


#endif