#ifndef STUDENT_H
#define STUDENT_H

#include "Degree.h"
#include <string>
using namespace std;

class Student {
public:
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void SetDegree(DegreeProgram degree);
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegree();
	void Print();
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	int daysInCourse[3];
	DegreeProgram degree; 
};

#endif // !STUDENT_H
