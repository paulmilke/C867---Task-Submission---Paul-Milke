#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>
#include "degree.h"
using namespace std; 


//ALL ACCESSOR FUNCTIONS 

Student::Student(string id, string fName, string lName, string email, int age, int days[], int numElem, DegreeProgram pType)
{
	SetStudentID(id); 
	SetFirstName(fName);
	SetLastName(lName); 
	SetEmail(email); 
	SetAge(age); 
	SetDaysInCourse(days, numElem);
	SetProgramType(pType); 
	return; 
}

Student::~Student() {
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
	daysPtr = daysInCourse; 
	return daysPtr; 
}


DegreeProgram Student::GetProgramType() {
	return programType; 
}

/*************************************/

//ALL MUTATOR FUNCTIONS
void Student::SetStudentID(string newStudentID) {
	studentID = newStudentID; 
	return; 
}

void Student::SetFirstName(string newFirstName) {
	firstName = newFirstName; 
	return; 
}

void Student::SetLastName(string newLastName) {
	lastName = newLastName; 
	return; 
}

void Student::SetEmail(string newEmail) {
	email = newEmail; 
}

void Student::SetAge(int newAge) {
	age = newAge; 
	return; 
}


void Student::SetDaysInCourse(int array[], int elements) {
	daysInCourse[0] = array[0]; 
	daysInCourse[1] = array[1]; 
	daysInCourse[2] = array[2]; 
	return; 
}

void Student::SetProgramType(DegreeProgram newProgramType) {
	programType = newProgramType; 
	return; 
}


//PRINT FUNCTION
void Student::Print() {
	cout << GetStudentID() << "\t";
	cout << "First Name: " << GetFirstName() << "\t" << "Last Name: " << GetLastName() << "\t";
	cout << "Age: " << age << "\t\t"; 
	cout << "daysInCourse: {" << GetDaysInCourse()[0] << ", "<< GetDaysInCourse()[1] << ", " << GetDaysInCourse()[2] << "} ";
	switch (GetProgramType()) {
	case SECURITY:
		cout << "Degree Program: Security" << endl;
		break;

	case NETWORK:
		cout << "Degree Program: Network" << endl;
		break;

	case SOFTWARE:
		cout << "Degree Program: Software" << endl;
		break;
	} 
	return; 
}
