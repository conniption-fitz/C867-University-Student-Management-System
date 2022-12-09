#include <iostream>
#include <string>
#include "Degree.h"
#include "Roster.h"
#include "Student.h"
using namespace std; 

int main() {

	int i = 0;
	Roster classRoster;

	//studentData table
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Victoria,Fitzgerald,vdehave@wgu.edu,29,20,13,34,SOFTWARE"
	};

	//submission header
	cout << "C867 - Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 000559078" << endl;
	cout << "Victoria Fitzgerald" << endl;

	// parse studentData 
	classRoster.Parse(studentData);
		
	// print full roster
	cout << endl << endl << "Printing full roster:" << endl;
	classRoster.PrintAll();

	// print invalid emails
	cout << endl << endl << "Printing invalid email addresses:" << endl;
	classRoster.PrintInvalidEmails();
	
	// print by degree program - SOFTWARE
	cout << endl << endl << "Printing by degree - SOFTWARE:" << endl;
	classRoster.PrintByDegree(SOFTWARE);

	// print average days
	cout << endl << endl << "Printing average days in course:" << endl;
	classRoster.PrintAvgDaysInCourse("A1");
	classRoster.PrintAvgDaysInCourse("A2");
	classRoster.PrintAvgDaysInCourse("A3");
	classRoster.PrintAvgDaysInCourse("A4");
	classRoster.PrintAvgDaysInCourse("A5");

	// remove student - A3
	cout << endl << endl << "Removing student A3:" << endl;
	classRoster.Remove("A3");
	
	cout << endl << endl << "Printing full roster:" << endl;
	classRoster.PrintAll();
	
	cout << endl << endl << "Removing student A3:" << endl;
	classRoster.Remove("A3");
	
	return 0;
}