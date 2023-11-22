#include "student.h"
#include <iostream>
#include <array>
#include "degree.h"
#include <iomanip>


    std::string degreeProgramString[] = { "SECURITY", "NETWORK", "SOFTWARE" };
    //Constructor
    Student::Student(std::string studentID, std::string firstname, std::string lastname, std::string emailaddress, int age, std::array<int, 3> daysleftoncourse, DegreeProgram degreeprogram)  :
        studentID_(studentID), firstname_(firstname), lastname_(lastname), emailaddress_(emailaddress), age_(age), daysleftoncourse_(daysleftoncourse),
        degreeprogram_(degreeprogram) {};

    //Get methods
    std::string Student::getStudentID() const {return studentID_;}
    std::string Student::getFirstname() const {return firstname_;}
    std::string Student::getLastname() const {return lastname_;}
    int Student::getAge()const { return age_; }
    std::string Student::getEmailaddress() const {return emailaddress_;} 
    DegreeProgram Student::getDegreeprogram() const {return degreeprogram_;}
    std::array<int, 3> Student::getDaysleftonallcourses() const { return daysleftoncourse_;}
    int Student::getDaysleftonfirstcourse() const {return daysleftoncourse_[0];}
    int Student::getDaysleftonsecondcourse() const { return daysleftoncourse_[1]; }
    int Student::getDaysleftonthirdcourse() const { return daysleftoncourse_[2]; }
    

    //Set methods
    void Student::setStudentID(std::string studentID) {studentID_ = studentID;}
    void Student::setFirstname(std::string firstname) {firstname_ = firstname;}
    void Student::setLastname(std::string lastname) {lastname_ = lastname;}
    void Student::setAge(int age) { age_ = age; }
    void Student::setEmailaddress(std::string emailaddress) {emailaddress_ = emailaddress;}
    void Student::setDegreeprogram(DegreeProgram degreeprogram) {degreeprogram_ = degreeprogram;}
    void Student::setDaysleftonallcourses(int daysclassone, int daysclasstwo, int daysclassthree) { daysleftoncourse_ = {daysclassone, daysclasstwo, daysclassthree}; }
    void Student::setDaysleftonfirstcourse(int days) { daysleftoncourse_[0] = days; }
    void Student::setDaysleftonsecondcourse(int days) { daysleftoncourse_[1] = days; }
    void Student::setDaysleftonthirdcourse(int days) { daysleftoncourse_[2] = days; }
     
    //Printmethods
    void Student::PrintstudentID() {std::cout << getStudentID() << "\t"; }
    void Student::Printfirstname() {std::cout << "First Name: " << getFirstname() << "\t"; }
    void Student::Printlastname() { 
        std::string templastname = getLastname();
        if (templastname.size() > 3) {
            std::cout << "Last Name: " << getLastname() << "\t";
        }
        else {
            std::cout << "Last Name: " << getLastname() << "\t\t";
        }
    }
    void Student::PrintAge() { std::cout << "Age:" << getAge() << "\t\t"; }
    void Student::Printemailaddress() { std::cout << "Email address: " << getEmailaddress() << "\t"; }
    void Student::Printdaysleftonallcourses() {
        std::array<int, 3> days = Student::getDaysleftonallcourses();
        std::cout << "{" << days[0] << " ," << days[1] << " ," << days[2] << "}\t";
    }
    void Student::Printdegreeprogram() { std::cout << "Degree Program: " << degreeProgramString[getDegreeprogram()] << std::endl;}
    void Student::Printdaysleftonfirstcourse() { std::cout << "Days left on first course " << getDaysleftonfirstcourse() << "\n\n"; }
    void Student::Printdaysleftonsecondcourse() { std::cout << "Days left on second course " << getDaysleftonfirstcourse() << "\n\n"; }
    void Student::Printdaysleftonthirdcourse() { std::cout << "Days left on third course " << getDaysleftonfirstcourse() << "\n\n"; }
    void Student::Printeverything() {
        Student::PrintstudentID();
        Student::Printfirstname();
        Student::Printlastname();
        Student::PrintAge();
        Student::Printemailaddress();
        Student::Printdaysleftonallcourses();
        Student::Printdegreeprogram();
    }

     

    //Variables for within the class
    std::string studentID_;
    std::string firstname_;
    std::string lastname_;
    std::string emailaddress_;
    int age_;
    std::array<int, 3> daysleftoncourse_;
    DegreeProgram degreeprogram_;
