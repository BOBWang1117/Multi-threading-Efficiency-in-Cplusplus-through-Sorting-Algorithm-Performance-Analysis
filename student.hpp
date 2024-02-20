#include <iostream>
#include <vector>
#ifndef STUDENT_HPP
#define STUDENT_HPP

struct StudentInfo
{
    int sid;
    char studentID[32];
    char name[64];
    bool gender;    // 0 is mail, 1 is femail
};

class Student{
public:
    Student(std::vector<StudentInfo>& s);
    ~Student();
    bool addStudent(int sid,char name[],bool gender);
    bool deleteStudent();
    bool updateStudent();
    bool findStudent();
    void printStudentInfo();

private:
   std::vector<StudentInfo> student;
};

#endif