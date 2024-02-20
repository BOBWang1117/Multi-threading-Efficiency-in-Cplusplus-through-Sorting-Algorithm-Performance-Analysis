#include <iostream>
#include <string.h>
#include "load_file.hpp"

MyReadFile::MyReadFile(const char* filePath)
{
    strcpy(this->filePath, filePath);
}

MyReadFile::~MyReadFile(){}

void MyReadFile::fileOpen()
{
    infile.open(filePath);

    if (!infile)
	{
		std::cout << "Can not open this file!" << std::endl;
		exit(-1);
	}
}

std::vector<StudentInfo> MyReadFile::dataProcessing()
{
    std::vector<StudentInfo> student;
    std::string s;
    char c [255];
    char* token;
    char *p;

    int sid;
    char studentID[32];
    char name[64];
    bool gender;

    while (getline(infile,s))
	{
        int counter = 0;
        strcpy(c,s.c_str());
        token = strtok_s(c, ",", &p);
        while( token != NULL )
        {
            if(counter == 0)    sid = std::stoi(token);
            else if(counter == 1)   strcpy(studentID, token);
            else if(counter == 2)   strcpy(name, token);
            else
            {
                if(std::stoi(token) == 0)   gender = 0;
                else                        gender = 1;
            }
            token = strtok_s(NULL, ",", &p);
            counter++;
        }

        StudentInfo studentInfo;
        studentInfo.sid = sid;
        memcpy(studentInfo.studentID, studentID, 32);
        memcpy(studentInfo.name, name, 64);
        studentInfo.gender = gender;

        student.push_back(studentInfo);
	}

    return student;
}

void MyReadFile::fileClose()
{
    infile.close();
}
