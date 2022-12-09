#include <iostream>
#include <string>
using namespace std;

#include "Roster.h"
#include "Student.h"

void Roster::Parse(const string studentData[]) {
	int i = 0;
	int j = 0;
	int start = 0;
	int end = 0;

	Student newStudent;

	string tempID;
	string tempFirstName;
	string tempLastName;
	string tempEmail;
	string tempAge;
	//string* tempDaysStr = nullptr;
	string tempDays1;
	string tempDays2;
	string tempDays3;
	string tempDegree;

	int tempAgeInt = 0;
	//int* tempDaysCourse = { 0 };
	int tempDays1Int = 0;
	int tempDays2Int = 0;
	int tempDays3Int = 0;

	DegreeProgram tempDegreeProg = NO_DEGREE;

	for (i = 0; i < 5; i++) {
		// loop through studentData array
		end = studentData[i].find(',', start);
		tempID = studentData[i].substr(start, end);
		start = end + 1;

		end = studentData[i].find(',', start);
		tempFirstName = studentData[i].substr(start, end - start);
		start = end + 1;

		end = studentData[i].find(',', start);
		tempLastName = studentData[i].substr(start, end - start);
		start = end + 1;

		end = studentData[i].find(',', start);
		tempEmail = studentData[i].substr(start, end - start);
		start = end + 1;

		end = studentData[i].find(',', start);
		tempAge = studentData[i].substr(start, end - start);
		start = end + 1;

		//this is the problem
		/*
		for (j = 0; j < 3; j++) {
			end = studentData[i].find(',', start);
			tempDaysStr[j] = studentData[i].substr(start, end - start);
			start = end + 1;
		}
		*/
		
		end = studentData[i].find(',', start);
		tempDays1 = studentData[i].substr(start, end - start);
		start = end + 1;

		end = studentData[i].find(',', start);
		tempDays2 = studentData[i].substr(start, end - start);
		start = end + 1;

		end = studentData[i].find(',', start);
		tempDays3 = studentData[i].substr(start, end - start);
		start = end + 1;
		

		end = studentData[i].find(',', start);
		tempDegree = studentData[i].substr(start, end - start);
		start = end + 1;


		//change age, days to int
		tempAgeInt = stoi(tempAge);
		
		/*
		for (j = 0; j < 3; j++) {
			tempDaysCourse[j] = stoi(tempDaysStr[j]);
		}
		*/

		tempDays1Int = stoi(tempDays1);
		tempDays2Int = stoi(tempDays2);
		tempDays3Int = stoi(tempDays3);

		//change tempDegree to DegreeProgram
		if (tempDegree == "SECURITY") {
			tempDegreeProg = SECURITY;
		}
		else if (tempDegree == "NETWORK") {
			tempDegreeProg = NETWORK;
		}
		else if (tempDegree == "SOFTWARE") {
			tempDegreeProg = SOFTWARE;
		}
		else {
			tempDegreeProg = NO_DEGREE;
		}
	
		Add(tempID, tempFirstName, tempLastName, tempEmail, tempAgeInt, tempDays1Int, tempDays2Int,
			tempDays3Int, tempDegreeProg);
	}
	
}

void Roster::Add(string studentID, string firstName, string lastName, string email, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
	classRosterArray[ROSTER_SIZE] = new Student(studentID, firstName, lastName, email,
		age, daysInCourse1, daysInCourse2, daysInCourse3, degree);

	ROSTER_SIZE++;
}

void Roster::Remove(string studentID) {
	int i = 0;
	bool foundID = false;
	
	for (i = 0; i < ROSTER_SIZE; i++) {
		Student* student = classRosterArray[i];

		if (student->GetStudentID() == studentID) {
			foundID = true;

			classRosterArray[i] = classRosterArray[ROSTER_SIZE - 1];
			
			ROSTER_SIZE--;
		}
	}

	if (foundID == false) {
		cout << "A student with this ID was not found." << endl;
	}
	return;
}
void Roster::PrintAll() {
	int i = 0;

	for (i = 0; i < ROSTER_SIZE; i++) {
		Student* student = classRosterArray[i];
		student->Print();
	}
	return;
}
void Roster::PrintAvgDaysInCourse(string studentID) {
	// loop to find studentID
	// call getDaysInCourse 
	// calculate avg
	// print
	int i = 0;
	int* tempDaysArray;
	int tempDays1 = 0;
	int tempDays2 = 0;
	int tempDays3 = 0;
	int avgDays = 0;

	for (i = 0; i < ROSTER_SIZE; i++) {
		Student* student = classRosterArray[i];

		if (student->GetStudentID() == studentID) {
			tempDaysArray = student->GetDaysInCourse();

			tempDays1 = tempDaysArray[0];
			tempDays2 = tempDaysArray[1];
			tempDays3 = tempDaysArray[2];

			// calculate average
			avgDays = (tempDays1 + tempDays2 + tempDays3) / 3;

			cout << "Student ID: " << studentID << "\tAverage Days In Course: " << avgDays << endl;
		}
	}
	return;
}
void Roster::PrintInvalidEmails() {
	// loop through roster emails
	// search for ' ', '.', '@' -- if/else
	// print emails
	int i = 0;
	string tempEmail;

	for (i = 0; i < ROSTER_SIZE; i++) {
		Student* student = classRosterArray[i];

		tempEmail = student->GetEmail();

		if (tempEmail.find(' ') != string::npos) {
			cout << tempEmail << endl;
		}
		else if (tempEmail.find('@') == string::npos) {
			cout << tempEmail << endl;
		}
		else if (tempEmail.find('.') == string::npos) {
			cout << tempEmail << endl;
		}
	}

	return;
}
void Roster::PrintByDegree(DegreeProgram degreeProgram) {
	// loop through roster degrees
	// search for degreeProgram
	// print degree students
	int i = 0;

	for (i = 0; i < ROSTER_SIZE; i++) {
		Student* student = classRosterArray[i];

		if (student->GetDegree() == degreeProgram) {
			student->Print();
		}
	}
	return;
}

Roster::~Roster()
{
	// deletes dynamically allocated memory -- classRoster?	
	return;
}
