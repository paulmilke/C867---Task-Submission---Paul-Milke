#pragma once
#include <string>
using namespace std; 
#include "degree.h"
#include "roster.h"
#include "student.h"

#ifndef STUDENT_H 
#define STUDENT_H


class Student {
public:
	Student(string id, string fName, string lName, string email,
		int age, int days[], int numElem, DegreeProgram pType);
	~Student();

	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDaysInCourse(); 
	DegreeProgram GetProgramType();

	void SetStudentID(string newStudentID);
	void SetFirstName(string newFirstName);
	void SetLastName(string newLastName);
	void SetEmail(string newEmail);
	void SetAge(int newAge);
	void SetDaysInCourse(int daysArray[], int numElements); 
	void SetProgramType(DegreeProgram newProgramType); 

	void Print();


private:
	string studentID; 
	string firstName; 
	string lastName; 
	string email; 
	int age; 
	int daysInCourse[3]; 
	DegreeProgram programType; 
	int* daysPtr; 

};

#endif; 

