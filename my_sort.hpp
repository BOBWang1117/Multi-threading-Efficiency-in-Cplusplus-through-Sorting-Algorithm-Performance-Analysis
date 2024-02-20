#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include "student.hpp"
#ifndef MY_SORT_HPP
#define MY_SORT_HPP

struct Operation {
    Operation(int operation) { this->operation = operation; }
    bool operator () (const StudentInfo& a, const StudentInfo& b) 
    {
        switch (this->operation)
        {
        case 1:
            return a.sid < b.sid;
        case 2:
            return strcmp(a.studentID,b.studentID) < 0;
        case 3:
            return strcmp(a.name,b.name) < 0;
        case 4:
            if(a.gender != b.gender)    return a.gender < b.gender;
            else    return a.sid < b.sid;

        default:
            std::cout<<"Operation Number Invalid"<<std::endl;
            return -1;
        }
    }

    int operation;
};

class MySort{
public:
    MySort(std::vector<StudentInfo>* task_sf, int operation);
    ~MySort();

    //Sorting Algorithm
    void STDsort();

    //print vector<StudentInfo>
    void mySortPrint();
private:
    int operation;
    std::vector<StudentInfo>* task_sf;
};

#endif

// https://studiofreya.com/cpp/cpp-std-sort-predicate-with-templates/