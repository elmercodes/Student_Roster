#include "Student.h"

void Student::setStudentID(std::string studentIDs) {
	studentID = studentIDs;
}
void Student::setFirstName(std::string firstNames) {
	firstName = firstNames;
}
void Student::setLastName(std::string lastNames) {
	lastName = lastNames;
}
void Student::setEmailAddress(std::string emailAddresss) {
	emailAddress = emailAddresss;
}
void Student::setAge(int ages) {
	age = ages;
}
void Student::setDaysInCourse(int daysInCourses[3]) {
	for (int i = 0; i < 3; ++i) {
		this->daysInCourse[i] = daysInCourses[i];
	}
}
void Student::setDegreeProgram(std::string degreePrograms) {
	degreeProgram = degreePrograms;
}


void Student::print() const {
	std::cout << getStudentID() << "\t"
		<< "First Name: " << getFirstName() << "\t"
		<< "Last Name: " << getLastName() << "\t"
		<< "Age: " << getAge() << "\t"
		<< "daysInCourse: {" << getDaysInCourse()[0] << ", "
		<< getDaysInCourse()[1] << ", "
		<< getDaysInCourse()[2] << "} \t"
		<< "Degree Program: " << getDegreeProgram() << std::endl;
}


Student::Student() {
	setStudentID("");
	setFirstName("");
	setLastName("");
	setEmailAddress("");
	setAge(NULL);
	int defaultDays[3] = { 0, 0, 0 };
	setDaysInCourse(defaultDays);
	setDegreeProgram("");
}


Student::Student(std::string studentID, std::string firstName, std::string lastName,
	std::string emailAddress, int age, std::array <int, 3> dayInCourse,
	std::string degreeProgram) {

	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDaysInCourse(dayInCourse.data());
	setDegreeProgram(degreeProgram);
}

Student::~Student() {}
