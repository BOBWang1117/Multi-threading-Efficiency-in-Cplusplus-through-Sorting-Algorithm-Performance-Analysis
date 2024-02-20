#include <fstream>
#include "student.hpp"
#ifndef LOAD_FILE_HPP
#define LOAD_FILE_HPP


class MyReadFile{
public:
    MyReadFile(const char* filePath);
    ~MyReadFile();
    void fileOpen();
    std::vector<StudentInfo> dataProcessing();
    void fileClose();

private:
   char filePath[255];
   std::ifstream infile;
};

#endif