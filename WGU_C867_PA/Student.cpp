#include <iostream>
#include <string>
using namespace std;

#include "Student.h"
#include "Degree.h"

void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
	return;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::SetEmail(string email) {
	this->email = email;
	return;
}

void Student::SetAge(int age) {
	this->age = age;
	return;
}

void Student::SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse3 = daysInCourse3;
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	return;
}

void Student::SetDegree(DegreeProgram degree) {
	this->degree = degree;
	return;
}

string Student::GetStudentID() {
	return studentID;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmail() {
	return email;
}

int Student::GetAge() {
	return age;
}


int* Student::GetDaysInCourse() {
	//need to fix
	return daysInCourse;

}


DegreeProgram Student::GetDegree() {
	return degree;
}

void Student::Print() {
	//this is good
	cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge:"
		<< age << "\tDays In Course: {" << daysInCourse[0] << "," << daysInCourse[1] << "," 
		<< daysInCourse[2] << "}\tDegree Program: " << degreeProgramStrings[degree] << endl;
}

Student::Student() { //need parameters here?
	studentID = "NoID";
	firstName = "No Name";
	lastName = "No Name";
	email = "No Email";
	age = 0;
	daysInCourse1 = 0;
	daysInCourse2 = 0;
	daysInCourse3 = 0;
	degree = NO_DEGREE; 
}

Student::Student(string studentID, string firstName, string lastName, string email, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	this->degree = degree;
}