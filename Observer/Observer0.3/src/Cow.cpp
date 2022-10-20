#include<vector>
#include<iostream>
#include<mutex>
#include<memory>
#include"Cow.h"

void Cow::read() const
{
    decltype(arr_) new_arr_; 
    const std::lock_guard<std::mutex> guard(mutex_);
    new_arr_ = arr_; // 引用计数+1
    for(auto i:*new_arr_)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

void Cow::append(int x)
{
    const std::lock_guard<std::mutex> guard(mutex_);
    if(!arr_.unique())
    {
        arr_.reset(new std::vector<int>(*arr_) );
    }
    arr_->push_back(x);
    // 判断是否有人在用arr_
}

//读时共享，写时复制