#include"Observer.h"
#include<mutex>

void Observable::notify()
{
    const std::lock_guard<std::mutex> guard(mutex_);
    for(auto iter=observers_->begin(); iter!=observers_->end(); )
    {
        auto p = iter->lock();
        if(p)
        {
            p->update();
            iter++;
        }
        /*
        else
        {
            iter = observers_->erase(iter);
        }
        */
    }
    
}

void Observable::register_(const std::weak_ptr<Observer> &observer)
{
    const std::lock_guard<std::mutex> guard(mutex_);
    if(!observers_.unique())
    {
        observers_.reset(new ObserverList(*observers_));
    }
    observers_->push_back(observer);
    auto p = observer.lock();
    if(p)
    {
        // p->variable_pointer = std::shared_ptr<Observable>(this); // FATAL
        p->variable_pointer = shared_from_this();
    }

}

void Observable::unregister()
{
    const std::lock_guard<std::mutex> guard(mutex_);
    if(!observers_.unique())
    {
        observers_.reset(new ObserverList(*observers_));
    }
    for(auto iter=observers_->begin(); iter!=observers_->end();)
    {
        if(iter->expired())
        {
            iter = observers_->erase(iter);
        }
    }
}

/*
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
*/

/*
Observer::~Observer()
{
    auto p = variable_pointer.lock();
    if(p)
    {
        p->unregister();
    }
}
 */