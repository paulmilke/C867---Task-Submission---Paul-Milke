// student_data_assessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <vector>
#include <sstream>
using namespace std;

void PrintPersonalInfo() {
    cout << "Scripting and Programming - Applications - C867" << endl; 
    cout << "Language: C++" << endl; 
    cout << "Student ID: 001310021" << endl;
    cout << "Name: Paul Milke" << endl << endl;
    return; 
}

int main()
{

    PrintPersonalInfo(); 

    Roster classRoster; 
    classRoster.PrintAll();
    cout << endl; 

    classRoster.PrintInvalidEmails();
    cout << endl; 

    cout << "Displaying average days in course per student: " << endl << endl; 
    int i = 0; 
    string studentIDs[] = { "A1", "A2", "A3", "A4", "A5" };

    for (i = 0; i < 5; ++i) {
        classRoster.PrintAverageDaysInCourse(studentIDs[i]); 
    }
    cout << endl; 

    classRoster.PrintByDegreeProgram(SOFTWARE);
    cout << endl; 

    classRoster.Remove("A3"); 

    classRoster.PrintAll(); 
    cout << endl;

    classRoster.Remove("A3");

    return 0; 
}

 