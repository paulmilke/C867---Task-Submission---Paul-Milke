#include "roster.h"
#include "student.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const int STUDENTS_SIZE = 5;
Student* classRosterArray[STUDENTS_SIZE]; 

Roster::Roster() {
    ParseStudentData(); 
    return; 
}

Roster::~Roster()
{
    cout << "Roster destructor called" << endl; 
    return;
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int index)
{

    int daysInCArray[3];
    daysInCArray[0] = daysInCourse1; 
    daysInCArray[1] = daysInCourse2; 
    daysInCArray[2] = daysInCourse3; 

    Student* studentPtr = new Student(studentID, firstName, lastName,
        emailAddress, age, daysInCArray, 3, degreeProgram);

    classRosterArray[index] = studentPtr;
    return; 
}

void Roster::Remove(string studentID)
{
    int i = 0;
    string id = "";
    cout << "Removing " << studentID << endl << endl; 

    for (i = 0; i < STUDENTS_SIZE; ++i) {
        if (classRosterArray[i] != NULL) {
            id = classRosterArray[i]->GetStudentID();
            if (id == studentID) {
                delete classRosterArray[i];
                classRosterArray[i] = NULL;
            }
        }
        else if (classRosterArray[i] == NULL) {
            cout << "The student with ID: " << studentID << " was not found" << endl; 
        }
    }
    return; 
}

void Roster::PrintAll()
{
    cout << "Displaying all students:" << endl << endl;
    int i = 0; 
    for (i = 0; i < STUDENTS_SIZE; ++i) {
        if (classRosterArray[i] != NULL) {
            classRosterArray[i]->Print();
        }
    }
    return; 
}

void Roster::PrintAverageDaysInCourse(string StudentID)
{
    int averageDays = 0;
    int i = 0; 
    int* arrayPtr = nullptr; 
    
    for (i = 0; i < STUDENTS_SIZE; ++i) {
        Student* studentPtr = classRosterArray[i];

        if (studentPtr->GetStudentID() == StudentID) {
            arrayPtr = studentPtr->GetDaysInCourse();
            averageDays = (arrayPtr[0] + arrayPtr[1] + arrayPtr[2]) / 3; 
        }
    }

    cout << "Student ID: " << StudentID << ", " << "averages " << averageDays << " days in a course." << endl; 
    return; 
}

void Roster::PrintInvalidEmails()
{
    cout << "Displaying invalid emails:" << endl << endl;
    int i = 0;

    for (i = 0; i < STUDENTS_SIZE; ++i) {
        Student* studentPtr = classRosterArray[i];
        string email = studentPtr->GetEmail();
        int j = 0;
        int countSpace = 0;
        int countPeriod = 0;
        int countAt = 0;

        for (j = 0; j < email.length(); ++j) {
            if (email.at(j) == ' ') {
                countSpace += 1; 
            }

            if (email.at(j) == '.') {
                countPeriod += 1; 
            }

            if (email.at(j) == '@') {
                countAt += 1;
            }
        } 

        if ((countSpace > 0) || (countPeriod == 0) || (countAt == 0)) {
            cout << email << endl; 
        }

    }
    return; 
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram)
{
    int i = 0; 
    string degree = ""; 

    if (degreeProgram == SECURITY) {
        degree = "SECURITY"; 
    }
    if (degreeProgram == NETWORK) {
        degree = "NETWORK";
    }
    if (degreeProgram == SOFTWARE) {
        degree = "SOFTWARE"; 
    }

    cout << "Showing students in degree program: " << degree << endl << endl;

    for (i = 0; i < STUDENTS_SIZE; ++i) {
        Student* studentPtr = classRosterArray[i]; 
        if (studentPtr->GetProgramType() == degreeProgram) {
            studentPtr->Print(); 
       }
    }
    return; 
}

void Roster::ParseStudentData() {
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Paul,Milke,pmilke@wgu.edu,26,31,50,45,SOFTWARE" };
    
    int i = 0;
    string tempString;
    vector<string> parsedData;
    

    for (i = 0; i < 5; ++i) {
        tempString = "";
        int index = i;
        parsedData.clear(); 

        istringstream studentInfo(studentData[i]);


        while (getline(studentInfo, tempString, ',')) {
            parsedData.push_back(tempString);
        }

        DegreeProgram tempProgram;
        if (parsedData.at(8) == "SECURITY") {
            tempProgram = SECURITY;
        }
        else if (parsedData.at(8) == "NETWORK") {
            tempProgram = NETWORK;
        }
        else if (parsedData.at(8) == "SOFTWARE") {
            tempProgram = SOFTWARE;
        }

        Add(parsedData.at(0), parsedData.at(1), parsedData.at(2), parsedData.at(3),
            stoi(parsedData.at(4)), stoi(parsedData.at(5)), stoi(parsedData.at(6)), stoi(parsedData.at(7)), tempProgram, index);

    }
    return; 
}
