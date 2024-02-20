#include "my_thread.hpp"
#include "my_sort.hpp"

std::mutex m;
MyThread::MyThread(std::vector<StudentInfo> sf, const int num_thread, int operation)
{
    this->sf = sf;
    this->thread_num = num_thread;
    this->operation = operation;
}

MyThread::~MyThread()
{
    std::cout<<"here!"<<std::endl;
    for(auto& t: threadVector)
    {
        if(t.joinable())
            t.join();
    }
}

void task(const std::vector<StudentInfo>& sf, int begin, int end, int operation, std::queue<std::vector<StudentInfo>>* q_sf)
{
    //The first step: deep copy the range of whole array
    std::vector<StudentInfo> task_sf;
    task_sf.assign(sf.begin()+begin, sf.begin()+end);

    //The second step: Sort the array
    // Call my_sort.cpp file
    MySort mysort(&task_sf, operation);
    mysort.STDsort();
    // mysort.mySortPrint();

    //The last step: push the sorted array into queue
    m.lock();
    (*q_sf).push(task_sf);
    m.unlock();
}

void MyThread::create()
{
    int batchsize = this->sf.size() / thread_num;
    for(int i=0; i<this->thread_num; i++)
    {
        int begin = batchsize*i;
        int end = -1;
        if(i != thread_num-1)
            end = batchsize*(i+1);
        else
            end = this->sf.size();
        std::thread th(&task, this->sf, begin, end, this->operation, &this->q_sf);
        this->threadVector.push_back(std::move(th));
    }

    // threads join
    for(auto& t: threadVector)
    {
        if(t.joinable())
            t.join();
    }
}

void MyThread::merge()
{
    this->sf.erase(sf.begin(), sf.end());
    while(q_sf.size() != 1)
    {
        std::vector<StudentInfo> dst;
        std::vector<StudentInfo> v1 = q_sf.front();
        q_sf.pop();
        std::vector<StudentInfo> v2 = q_sf.front();
        q_sf.pop();
        std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst), Operation(this->operation));
        q_sf.push(dst);
    }
    sf = q_sf.front();
}

std::vector<StudentInfo> MyThread::getVector()
{
    return this->sf;
}

void MyThread::test()
{
    // std::cout<<std::endl;
    this->sf[0].sid=111;
    for(int i=0; i<this->sf.size(); i++)
    {
        std::cout<<this->sf[i].sid <<" "
                <<this->sf[i].studentID <<" "
                <<this->sf[i].name <<" "
                <<this->sf[i].gender <<" "
                <<std::endl;
    }
}
