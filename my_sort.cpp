#include "my_sort.hpp"

MySort::MySort(std::vector<StudentInfo>* task_sf, int operation)
{
    this->task_sf = task_sf;
    this->operation = operation;
}

MySort::~MySort()
{
    
}

void swap(StudentInfo* arg1, StudentInfo* arg2)
{
    StudentInfo temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

void MySort::STDsort()
{
    std::sort((*this->task_sf).begin(), (*this->task_sf).end(), Operation(this->operation));
}

void MySort::mySortPrint()
{
    for(int i=0; i<(*this->task_sf).size(); i++)
    {
        std::cout<<(*this->task_sf)[i].sid <<" "
                <<(*this->task_sf)[i].studentID <<" "
                <<(*this->task_sf)[i].name <<" "
                <<(*this->task_sf)[i].gender <<" "
                <<std::endl;
    }
} 

