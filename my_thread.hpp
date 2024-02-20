#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include "student.hpp"
#ifndef MY_THREAD_HPP
#define MY_THREAD_HPP


class MyThread{
public:
    MyThread(std::vector<StudentInfo> sf, const int thread_num, int operation);
    ~MyThread();
    void create();
    void test();
    void merge();
    std::vector<StudentInfo> getVector();

private:
    int thread_num;
    int operation;
    std::vector<StudentInfo> sf;
    std::vector<std::thread> threadVector;
    std::queue<std::vector<StudentInfo>> q_sf;
};

#endif