import numpy as np
import random

SIZE = 10000

"""
structor: sid, student ID, student name, gender
sid (string): 10-bytes length
studentID: 
"""
year = ['11','12','13','14','15','16','17','18','19','20','21','22','23','24']
month = ['01','06','09']
letterUpper = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
letterLower = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
randomList = np.random.permutation(SIZE)    # random is a list that store the random number

class Student:
    def __init__(self, size):
        self.size = size

    def sid(self,i):
        return str(randomList[i]).zfill(10)

    def studentID(self,sid):
        yearRandom = random.choice(year)
        monthRandom = random.choice(month)
        letterRandom = random.choice(letterUpper)

        firstPart = yearRandom + monthRandom + sid[8] + sid[7] + sid[6] + sid[5]
        secondPart = letterRandom + sid[1] + sid[4] + sid[3]
        thirdPart = random.choice(letterUpper) + sid[2] + random.choice(letterUpper) + random.choice(letterUpper)

        studentID = firstPart + '-' + secondPart + '-' + thirdPart

        return studentID

    def studentName(self):
        parts = np.random.randint(2,4)
        studentName = ''
        if parts == 2:
            length_1 = random.randint(2,10)
            length_2 = random.randint(5,20)
            for i in range(length_1):
                if i == 0:
                    studentName = studentName + random.choice(letterUpper)
                else:
                    studentName = studentName + random.choice(letterLower)
            studentName = studentName + ' '
            for i in range(length_2):
                if i == 0:
                    studentName = studentName + random.choice(letterUpper)
                else:
                    studentName = studentName + random.choice(letterLower)

        elif parts == 3:
            length_1 = random.randint(2,10)
            length_2 = random.randint(2,6)
            length_3 = random.randint(5,20)
            for i in range(length_1):
                if i == 0:
                    studentName = studentName + random.choice(letterUpper)
                else:
                    studentName = studentName + random.choice(letterLower)
            studentName = studentName + ' '
            for i in range(length_2):
                if i == 0:
                    studentName = studentName + random.choice(letterUpper)
                else:
                    studentName = studentName + random.choice(letterLower)
            studentName = studentName + ' '
            for i in range(length_3):
                if i == 0:
                    studentName = studentName + random.choice(letterUpper)
                else:
                    studentName = studentName + random.choice(letterLower)

        return studentName

    def gender(self):
        gender = random.randint(0,1)
        if gender == 0:
            return 0
        else:
            return 1


if __name__ == "__main__":
    fileName = 'students.txt'
    student = Student(SIZE)
    file = open(fileName,'w',encoding='utf-8')
    for i in range(0, SIZE):
        sid = student.sid(i)
        studentID = student.studentID(sid)
        studentName = student.studentName()
        gender = student.gender()
        file.write(f'{sid},{studentID},{studentName},{gender}\n')
    file.close()