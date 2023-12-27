#pragma once

#include <iostream>
#include <string>
#include <array>
#include "Degree.h"


class Student
{
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    std::array<int, 3> daysInCourse;
    std::string degreeProgram;

public:
    std::string getStudentID() const { return studentID; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getEmailAddress() const { return emailAddress; }
    int getAge() const { return age; }
    const std::array<int, 3>& getDaysInCourse() const {
        return daysInCourse;}
    std::string getDegreeProgram() const { return degreeProgram; }


    void setStudentID(std::string studentIDs);
    void setFirstName(std::string firstNames);
    void setLastName(std::string lastNames);
    void setEmailAddress(std::string emailAddresss);
    void setAge(int ages);
    void setDaysInCourse(int daysInCourses[3]);
    void setDegreeProgram(std::string degreePrograms);
    void print() const;


    // Constructor and Destructor
    Student();
    Student(std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int age, std::array <int, 3> dayInCourse,
        std::string degreeProgram);

    ~Student();



};

