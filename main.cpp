#include <iostream>
#include <windows.h>
#include <vector>
#include <thread>
#include <queue>
#include <chrono>

#include "my_sort.hpp"
#include "student.hpp"
#include "load_file.hpp"
#include "my_thread.hpp"

// #define PATH "./thread/test.txt"
#define PATH "./thread/dataset/students.txt"
#define THREAD_NUM 8
#define OPERATION 3
/***
 *  struct:    StudentInfo
 *  operation 1: sid (int)
 *  operation 2: studentID char[32]
 *  operation 3: name char[64]
 *  operation 4: gender bool   // 0 is male, 1 is female
***/
bool testing(std::vector<StudentInfo> testVec)
{
    for(int i=0; i<testVec.size()-1; i++)
    {
        switch (OPERATION)
        {
        case 1:
            if(testVec[i].sid > testVec[i+1].sid)   return false;
            break;
        case 2:
            if(strcmp(testVec[i].studentID, testVec[i+1].studentID) > 0)   return false;
            break;
        case 3:
            if(strcmp(testVec[i].name, testVec[i+1].name) > 0)   return false;
            break;
        case 4:
            if(testVec[i].gender > testVec[i+1].gender)   return false;
            break;
        
        default:
            std::cout<<"Invalid Operation"<<std::endl;
            return -1;
        }
    }

    return true;
}

int main()
{
    std::vector<StudentInfo> sf;
    std::queue<std::vector<StudentInfo>> q_sf;

    // Load file into memory
    std::cout<<"Step 1: Loading File"<<std::endl;
    MyReadFile readFile(PATH);
    readFile.fileOpen();
    sf = readFile.dataProcessing();
    readFile.fileClose();

    /***
    *   Test student infomation has successfully loading into memory
    *   std::cout<< "***Orignal Data***" << std::endl;
    *   Student student(sf);
    *   student.printStudentInfo();
    *   std::cout<< std::endl;
    ***/

    // Muti-threads
    std::cout<<"Step 2: Muti-Threading"<<std::endl;
    MyThread myThread(sf, THREAD_NUM, OPERATION);
    sf.erase(sf.begin(), sf.end());     //clear memory

    // calculate time-consuming
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    auto t1 = high_resolution_clock::now();
    myThread.create();
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n"<<std::endl;

    // test the result is correct
    std::cout<<"Step 3: Merging Files"<<std::endl;
    myThread.merge();
    sf = myThread.getVector();
    bool result = testing(sf);
    if(result)
        std::cout<<"All Correct!"<<std::endl;
    else
    {
        std::cout<<"Anything Wrong: check all program!"<<std::endl;
        return -1;
    }

    std::cout<< "***EXIT***" << std::endl;

    return 0;
}




// sf.clear();         // Free sf memory




// while(!q_sf.empty())
//     {
//         std::cout<<std::endl;
//         std::vector<StudentInfo> s = q_sf.front();
//         if(s.size() == 0)
//             std::cout<<"None"<<std::endl;
//         for(int i=0; i<s.size(); i++)
//         {
//             std::cout<<s[i].sid <<" "
//                     <<s[i].studentID <<" "
//                     <<s[i].name <<" "
//                     <<s[i].gender <<" "
//                     <<std::endl;
//         }
//         q_sf.pop();
// }