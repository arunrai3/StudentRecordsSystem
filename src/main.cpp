#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>


int main()
{
    std::cout << "\n\nProgramming language: C++\nAuthor Name: Arun Rai\n\n";

    //Creating an instance of the class roster caleed "classRoster."
    roster classRoster;
    


    //Passing student data to a method in the classRoster object which will create student objects. 
    classRoster.add("A1", "John", "Smith", "John1989@gm ail.com", 20, std::array<int, 3>{30, 35, 40}, SECURITY);

    classRoster.add("A2", "Suzan","Erickson","Erickson_1990@gmailcom",19, std::array<int, 3>{50, 30, 40},NETWORK);

    classRoster.add("A3", "Jack", "Napoli","The_lawyer99yahoo.com",19, std::array<int, 3>{20, 40, 33},SOFTWARE);
    
    classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net",22, std::array<int, 3>{50, 58, 40},SECURITY);
    
    classRoster.add("A5", "Arun", "Rai", "arunrai202@gmail.com",22, std::array<int, 3>{23, 56, 34}, SOFTWARE);



    //This method will loop through and print every element of classRoster.classRosterArray.
    classRoster.printAll();



    //This method will loop through every element of classRoster.classRosterArray, call a get method from the student class, check if the return from that method meets certain conditions and print to screen. 
    classRoster.printInvalidEmails();



    //The method printAverageDaysInCourse prints average days in course to a specific student. But since we want to do every student we will iterate through every eleemnt in classRoster.classRosterArray, get the
    //student ID for each student and pass that data into the method for each iteration.
    std::cout << "----------------------------" << std::endl;
    std::cout << "Average days in course list:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    for (int i = 0; i < classRoster.indexx; i++) {
        std::string studentIDtemp = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(studentIDtemp);
    }
    std::cout << " " << std::endl;
    


    //Pass what degreeprogram you would like to view, after this the method will iterate through each student object and find the students with the same degreeprogram you passed, then print them to screen.
    classRoster.printByDegreeProgram(SOFTWARE);
   


    //This method will loop through every element of classRoster.classRosterArray, call a get method from the student class which will return studentID, check if the studentID passed in matches
    //the one from get method, and remove the matches.
    classRoster.remove("A3");
     


    //This method will loop through and print every element of classRoster.classRosterArray. Since we removed "A3" that whole row will be eliminated.
    classRoster.printAll();
  


    //Same as remove method from above, but if no matches are found it will notify the user through print statements.
    classRoster.remove("A3");

}