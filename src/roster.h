#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <array>
#include "degree.h"
#include "student.h"

class roster {
public:
    int indexx;
    std::array <Student*, 10> classRosterArray {nullptr};
    roster() {
        indexx = 0;
    }

    void add(std::string studentID, std::string firstname, std::string lastname, std::string emailaddress, int age, std::array<int, 3> daysleftoncourse, DegreeProgram degreeprogram);

    void remove(std::string studentID);

    void printAll();

    void printAverageDaysInCourse(std::string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeprogram);
    
    ~roster();
};
#endif