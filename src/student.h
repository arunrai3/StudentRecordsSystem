#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <array>
#include "degree.h"

class Student {
public:
    //Constructor
    Student(std::string studentID, std::string firstname, std::string lastname, std::string emailaddress, int age, std::array<int,3> daysleftoncourse, DegreeProgram degreeprogram);

    //Get methods
    std::string getStudentID() const;
    std::string getFirstname() const;
    std::string getLastname() const;
    int getAge() const;
    std::string getEmailaddress() const;
    DegreeProgram getDegreeprogram() const;
    std::array<int, 3> getDaysleftonallcourses() const;
    int getDaysleftonfirstcourse() const;
    int getDaysleftonsecondcourse() const;
    int getDaysleftonthirdcourse() const;


    //Set methods
    void setStudentID(std::string studentID);
    void setFirstname(std::string firstname);
    void setLastname(std::string lastname);
    void setAge(int age);
    void setEmailaddress(std::string emailaddress);
    void setDegreeprogram(DegreeProgram degreeprogram);
    void setDaysleftonallcourses(int daysclassone, int daysclasstwo, int daysclassthree);
    void setDaysleftonfirstcourse(int days);
    void setDaysleftonsecondcourse(int days);
    void setDaysleftonthirdcourse(int days);

    //Printmethods
    void PrintstudentID();
    void Printfirstname();
    void Printlastname();
    void PrintAge();
    void Printemailaddress();
    void Printdegreeprogram();
    void Printdaysleftonallcourses();
    void Printdaysleftonfirstcourse();
    void Printdaysleftonsecondcourse();
    void Printdaysleftonthirdcourse();
    void Printeverything();
    
//Variables only used within the class
private:
    std::string studentID_;
    std::string firstname_;
    std::string lastname_;
    std::string emailaddress_;
    int age_;
    std::array<int, 3> daysleftoncourse_;
    DegreeProgram degreeprogram_;
};
#endif