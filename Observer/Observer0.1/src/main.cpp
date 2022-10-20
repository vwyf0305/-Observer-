#include<iostream>
#include<vector>
#include<functional>
#include<initializer_list>
#include"Observer.h"

class Data:public Observable
{
    private:
        std::vector<int> data_;
    public:
        explicit Data() = default;
        explicit Data(const std::vector<int> &newData)
        : data_(newData) {}
        explicit Data(const std::vector<int> &&newData)
        : data_(newData) {}
       
        inline std::vector<int> returnData() const
        {
            return data_;
        }
        
        void update(const std::vector<int> &data)
        {
            data_ = data;
            notify();
        }
        void update(std::vector<int> &&data)
        {
            data_ = data;
            notify();
            data.clear();
        }
};

class Observer1:public Observer
{
    public:
        Observer1() = delete;
        Observer1(const Data &newData): data_class(newData) {}
        void update() override
        {
            std::cout<<"Observer1() is called.\n";
            auto _data = data_class.returnData();
            for(auto x:_data)
            {
                std::cout<<" "<<x;
            }
            std::cout<<"\n";
        }
    private:
        const Data &data_class;

};

class Observer2:public Observer
{
    public:
        Observer2() = delete;
        Observer2(const Data &newData): data_class(newData) {}
        void update() override
        {
            std::cout<<"Observer2() is called.\n";
            auto _data = data_class.returnData();
            for(auto x:_data)
            {
                std::cout<<" "<<x;
            }
            std::cout<<"\n";
        }
    private:
        const Data &data_class;

};

int main(int argc, char* argv[])
{
    Data data{std::vector<int>{1, 2, 3, 4, 5, 6}};
    Observer1 ob1{data};
    Observer2 ob2(data);
    data.register_(&ob1);
    data.register_(&ob2);
    int x{7};
    auto arr = data.returnData();
    int y{8};
    arr.push_back(x);
    data.update(arr);
    arr.push_back(y);
    data.update(arr);
}