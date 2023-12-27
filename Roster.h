#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Student.h"
#include "Degree.h"


class Roster
{
private:
    std::string studentData[5];
    Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };


public:
    std::vector<std::string> split(const std::string& str, char delimiter);

    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
        int age, std::array<int, 3> daysInCourse, std::string degreeProgram);

    void remove(std::string studentID);

    void printAll() const;

    void printAverageDaysInCourse(std::string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);

    std::vector<std::string> getAllStudentIDs() const;


    // Constructor and Destructor
    Roster() {
        std::array<std::string, 5> studentData = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Elmer,Flores,eflo235@wgu.edu,24,35,35,35,SOFTWARE"
        };

        for (const auto& data : studentData) {
            std::vector<std::string> parsedData = split(data, ',');

            // Extract days in course as an array<int, 3>
            std::array<int, 3> daysInCourse = { std::stoi(parsedData[5]), std::stoi(parsedData[6]), std::stoi(parsedData[7]) };

            // Utilize the add function to create and add students
            add(parsedData[0], parsedData[1], parsedData[2], parsedData[3], std::stoi(parsedData[4]), daysInCourse, parsedData[8]);
        }
    }


    ~Roster() {
        for (int i = 0; i < 5; i++) {
            delete classRosterArray[i];
        }
    }
};