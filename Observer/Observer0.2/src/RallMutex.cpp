#include"RallMutex.h"
#include<pthread.h>

using namespace rall_test;

RallMutex::RallMutex()
{
    pthread_mutex_init(&mutex_, nullptr);
}
    
RallMutex::~RallMutex()
{
    pthread_mutex_destroy(&mutex_);
}

void RallMutex::lock()
{
    pthread_mutex_lock(&mutex_);
}

void RallMutex::unlock()
{
    pthread_mutex_unlock(&mutex_);
}