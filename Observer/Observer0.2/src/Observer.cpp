#include"Observer.h"
#include<mutex>

void Observable::notify()
{
    const std::lock_guard<std::mutex> guard(mutex_);
    for(auto observer: observers)
    {
        observer->update();
    }
    
}

void Observable::register_(Observer* observer)
{
    const std::lock_guard<std::mutex> guard(mutex_);
    observers.push_back(observer);
    observer->variable_pointer = this;
}

void Observable::unregister_(Observer* observer)
{
    const std::lock_guard<std::mutex> guard(mutex_);
    for(auto it=observers.begin(); it!=observers.end();)
    {
        if(*it == observer)
        {
            it = observers.erase(it);
            break;
        }
        else
            it++;
    }
}