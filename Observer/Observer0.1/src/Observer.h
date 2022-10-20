#include<iostream>
#include<vector>

#ifndef OBSERVER_h
#define OBSERVER_h

class Observable;
class Observer;



class Observable
{
    public:
        void notify();  // 通知所有观察者刷新
        void register_(Observer* observer); // 注册函数
    
    private:
        std::vector<Observer*> observers;
}; // 被观察者

class Observer
{
    public:
        virtual void update() = 0;
}; // 观察者

 













# endif