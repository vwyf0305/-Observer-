#include<iostream>
#include<vector>
#include<mutex>
#include<memory>

#ifndef OBSERVER_h
#define OBSERVER_h

class Observable;
class Observer;

using ObserverList = std::vector<std::weak_ptr<Observer>>;

class Observable:public std::enable_shared_from_this<Observable>
{
    public:
        Observable(): observers_(new ObserverList){};
        void notify();  // 通知所有观察者刷新
        void register_(const std::weak_ptr<Observer> &observer); // 注册函数
        // void unregister_(const std::shared_ptr<Observer> &observer);
        void unregister();

    private:
        //ObserverList observers;             // shared_ptr的引用计数至少为1
        std::shared_ptr<ObserverList> observers_;
        mutable std::mutex mutex_;
};  

class Observer
{
    public:
        // explicit Observer(Observable *observable): variable_pointer(observable) {}
        virtual void update() = 0;
    
        std::weak_ptr<Observable> variable_pointer;
        virtual ~Observer() {}

}; // 观察者

 













# endif