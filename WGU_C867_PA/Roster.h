#ifndef ROSTER_H
#define ROSTER_H



#include <string>
#include "Degree.h"
#include "Student.h"

class Roster
{
public:
	void Parse(const string studentData[]);
	void Add(string studentID, string firstName, string lastName, string email, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	void Remove(string studentID);
	void PrintAll();
	void PrintAvgDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegree(DegreeProgram degreeProgram);
	~Roster();
private:
	const int ROSTER_MAX = 5;
	int ROSTER_SIZE = 0;
	Student* classRosterArray[5];
};

#endif // !ROSTER_H