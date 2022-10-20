#include<iostream>
#include<vector>
#include<mutex>

#ifndef OBSERVER_h
#define OBSERVER_h

class Observable;
class Observer;



class Observable
{
    public:
        void notify();  // 通知所有观察者刷新
        void register_(Observer* observer); // 注册函数
        void unregister_(Observer* observer);
    
    private:
        std::vector<Observer*> observers;
        mutable std::mutex mutex_;
}; // 被观察者

class Observer
{
    public:
        // explicit Observer(Observable *observable): variable_pointer(observable) {}
        virtual void update() = 0;
    
        Observable *variable_pointer;
        ~Observer()
        {
            variable_pointer->unregister_(this);
        }
}; // 观察者

 













# endif