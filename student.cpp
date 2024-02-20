#include "student.hpp"

Student::Student(std::vector<StudentInfo>& student)
{
    //std::cout<<"Student begin"<<std::endl;
    this->student = student;
}

Student::~Student()
{
     //std::cout<<"Free Student"<<std::endl;
}

bool Student::addStudent(int sid, char name[], bool gender)
{
    std::cout<<"This is addStudent function"<<std::endl;

    return true;
}

bool Student::deleteStudent()
{
    std::cout<<"This is addStudent function"<<std::endl;

    return true;
}

bool Student::updateStudent()
{
    std::cout<<"This is addStudent function"<<std::endl;

    return true;
}

bool Student::findStudent()
{
    std::cout<<"This is addStudent function"<<std::endl;

    return true;
}

void Student::printStudentInfo()
{
    for(int i=0; i<student.size(); i++)
    {
        std::cout<<this->student[i].sid <<" "
                <<this->student[i].studentID <<" "
                <<this->student[i].name <<" "
                <<this->student[i].gender <<" "
                <<std::endl;
    }
}



