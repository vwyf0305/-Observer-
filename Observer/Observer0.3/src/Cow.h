#include<vector>
#include<iostream>
#include<mutex>
#include<memory>

#ifndef COW_H
#define COW_H

class Cow
{
   private:
     //std::vector<int> arr_;
     std::shared_ptr<std::vector<int>> arr_;
     mutable std::mutex mutex_;
   public:
     Cow(): arr_(new std::vector<int>()) {}
      
     void read() const;
     void append(int x);

      
};


#endif