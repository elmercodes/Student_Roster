#include <iostream>
#include <string>
#include <array>
#include "Student.h"
#include "Degree.h"
#include "Roster.h"


int main()
{
    std::string course{ "Scripting and Programming - Applications - C867\n" };
    std::string language{ "C++\n" };
    std::string stuId{ "011559308\n" };
    std::string name{ "Elmer Flores" };

    std::cout << course << language << stuId << name << std::endl;
    std::cout << "============================================\n" << std::endl;

    Roster classRoster;

    classRoster.printAll();

    classRoster.printInvalidEmails();
    
    std::vector<std::string> studentIDs = classRoster.getAllStudentIDs();
    for (const std::string& id : studentIDs) {
        classRoster.printAverageDaysInCourse(id);
    }

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3");

    return 0;
}

