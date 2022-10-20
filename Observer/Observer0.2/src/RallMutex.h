#include<pthread.h>

#ifndef RALLMUTEX_H
# define RALLMUTEX_h

namespace rall_test
{
    class RallMutex
    {
    private:
        pthread_mutex_t mutex_;
        inline void lock();
        inline void unlock();
    public:
        RallMutex();
        friend MutexLocKGuard;
        ~RallMutex();
    };
    
    class MutexLocKGuard
    {
    private:
        RallMutex &mutex_;
    public:
        explicit MutexLocKGuard(RallMutex &mutex_): mutex_(mutex_)
        {
            mutex_.lock();
        }
        ~MutexLocKGuard()
        {
            mutex_.unlock();
        }
    };

    
}


# endif