#include "Roster.h"


std::vector<std::string> Roster::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;


}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
    int age, std::array<int, 3> daysInCourse, std::string degreeProgram) {

    Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = student;
            break;
        }
    }
}

void Roster::remove(std::string studentID) {
    bool studentFound = false;

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i]; 
            classRosterArray[i] = nullptr; 
            studentFound = true;
            std::cout << "Student with ID " << studentID << " has been removed." << std::endl;
            break;
        }
    }

    if (!studentFound) {
        std::cout << "Error: Student with ID " << studentID << " was not found." << std::endl;
    }
}

void Roster::printAll() const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) { 
            classRosterArray[i]->print(); 
        }
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            const std::array<int, 3>& daysInCourse = classRosterArray[i]->getDaysInCourse();
            int sum = daysInCourse[0] + daysInCourse[1] + daysInCourse[2];
            double average = sum / 3.0;
            std::cout << "Average days in course for student ID " << studentID << " is: " << average << std::endl;
            return; 
        }
    }
    std::cout << "Student ID " << studentID << " not found." << std::endl;
}

void Roster::printInvalidEmails() {
    std::cout << "Invalid email addresses:" << std::endl;

    bool invalidEmailFound = false;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            std::string email = classRosterArray[i]->getEmailAddress();
            if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
                std::cout << email << std::endl;
                invalidEmailFound = true;
            }
        }
    }

    if (!invalidEmailFound) {
        std::cout << "No invalid email addresses found." << std::endl;
    }
}

DegreeProgram convertToDegreeProgram(const std::string& degreeProgramStr) {
    if (degreeProgramStr == "SECURITY") return SECURITY;
    else if (degreeProgramStr == "NETWORK") return NETWORK;
    else if (degreeProgramStr == "SOFTWARE") return SOFTWARE;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            DegreeProgram studentDegreeProgram = convertToDegreeProgram(classRosterArray[i]->getDegreeProgram());
            if (studentDegreeProgram == degreeProgram) {
                classRosterArray[i]->print();
            }
        }
    }
}

std::vector<std::string> Roster::getAllStudentIDs() const {
    std::vector<std::string> studentIDs;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            studentIDs.push_back(classRosterArray[i]->getStudentID());
        }
    }
    return studentIDs;
}


