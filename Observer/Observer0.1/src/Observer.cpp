#include"Observer.h"

void Observable::notify()
{
    for(auto observer: observers)
    {
        observer->update();
    }
    
}

void Observable::register_(Observer* observer)
{
    observers.push_back(observer);
}