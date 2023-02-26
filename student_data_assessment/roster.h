#pragma once
#include "student.h"
#include "degree.h"
#ifndef ROSTER_H
#define ROSTER_H

class Roster {
public:
	Roster();
	~Roster();
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int index);
	void Remove(string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(string StudentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);
	void ParseStudentData();

};


#endif