#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <array>


    std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	void roster::add(std::string studentID, std::string firstname, std::string lastname, std::string emailaddress, int age, std::array<int, 3> daysleftoncourse, DegreeProgram degreeprogram) {
		// create a new Student object on the heap
		Student* n = new Student(studentID, firstname, lastname, emailaddress, age, daysleftoncourse, degreeprogram);
		classRosterArray[indexx] = n;	
		indexx++;
	}

	void roster::remove(std::string studentID) {
		bool found = false;
		for (int i = 0; i < indexx; i++) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				classRosterArray[i] = nullptr;
				indexx = indexx - 1;
				int removedindex = i;
				for (int i = removedindex; i < indexx; i++) {
					classRosterArray[i] = classRosterArray[i + 1];
				}
				found = true;
				std::cout << "//Removed student with ID: " << studentID << "!" << std::endl;
				std::cout << " " << std::endl;
				break;
			}
		}
		if (!found) {
			std::cout << "//Student with this ID was not found!" << std::endl;
			std::cout << " " << std::endl;
		}
	}

    void roster::printAll() {
		std::cout << "-------------------------------" << std::endl;
		std::cout << "All students on current roster:" << std::endl;
		std::cout << "-------------------------------" << std::endl;
		for (int i = 0; i < indexx; i++) {
			classRosterArray[i]->Printeverything();
		}
		std::cout << " " << std::endl;
	}
    
	void roster::printAverageDaysInCourse(std::string studentID) {
		for (int i = 0; i < classRosterArray.size(); i++) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				std::array<int, 3> temp_array = classRosterArray[i]->getDaysleftonallcourses();
				int sum = 0;
				for (int i = 0; i < temp_array.size(); i++) {
					sum += temp_array[i];
				}
				int average = round(sum / temp_array.size());
				std::cout << "Average days in course for student with ID "<< studentID << ": " << average << std::endl;
				break;
			}
		}
	}

	void roster::printInvalidEmails() {
		std::cout << "--------------------" << std::endl;
		std::cout << "Invalid emails list:" << std::endl;
		std::cout << "--------------------" << std::endl;
		for (int i = 0; i < indexx; i++) {
			std::string tempemail = classRosterArray[i]->getEmailaddress();
			if (tempemail.find("@") == std::string::npos  || tempemail.find(".") == std::string::npos || tempemail.find(" ") != std::string::npos) {
				std::cout << "Student with ID " << classRosterArray[i]->getStudentID() << " has an invalid email address \"" << tempemail << "\"" << std::endl;
			}
		}
		std::cout << " " << std::endl;
	}

	void roster::printByDegreeProgram(DegreeProgram degreeprogram) {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Students with " << degreeProgramStrings[degreeprogram] << " Degree Program:" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		for (int i = 0; i < indexx; i++) {
			if (classRosterArray[i]->getDegreeprogram() == degreeprogram) {
				classRosterArray[i]->Printeverything();
			}
		}
		std::cout << " " << std::endl;
	}

	//destructormethod which does not to be called and will happen automatically when object is out of scope. Frees up memory for other processes.
	roster::~roster() {
		for (int i = 0; i < indexx; i++) {
			delete classRosterArray[i]; 
		}
	}