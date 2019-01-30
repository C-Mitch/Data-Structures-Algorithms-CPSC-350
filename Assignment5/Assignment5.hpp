//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5

#include <iostream>
#include <fstream>
#include <istream>
#include <limits>
#include <string>
#include "BST.hpp"
#include "Person.hpp"
#include "GenStack.hpp"


using namespace std;

#ifndef Assignment5_HPP
#define Assignment5_HPP

	
//A general object to get and validate file input
class GenFileIn
{
	public:
		GenFileIn();
		~GenFileIn();
		
		void setPath(); //Sets a file path to be used
		std::string getStringInput(); //Gets general string input
		int getIntInput(); //Gets general integer input
		double getDoubleInput(); //Gets general double input
		std::string getPath(); //Gets a file path and validates it, loops till valid file path found
		bool validatePath(); //A test to check if a path is valid, returns true if path connects, false if not
		bool validatePath(std::string pathy); //Overloaded test to check if given path is valid, returns true if path connects, false if not
		
	private:
		std::string path; //Std::string to hold a file path
	
};
	
//Handle All Database Functionality
class Simulation
{
	public:
		Simulation();
		~Simulation();
		

		BST<Student>* getStudentTree(); //Returns masterStudent
		BST<Faculty>* getFacultyTree(); //Returns masterFaculty
		
		void serializeFile(); //Serializes trees and transfers them to file for storage and reuse
		void deserializeFile(int c, std::string file); //Deserializes trees from given file and reimplements them - NOT FINISHED
		
		void run(); //Run the database; main loop control
		void menu(); //Main hub for command selection
		
		void printStudents(); //Print all students and their information (sorted by ascending id #)
		void printFaculty(); //Print all faculty and their information (sorted by ascending id #)
		void displayStudent(); //Display student information given student id
		void displayFaculty(); //Display faculty information given faculty id
		void displayAdvisor(); //Print the name and info of an advisor given student id
		void displayAdvisees(); //Print the name and info of all of a Faculty's advisees given faculty id
		void insertStudent(); //Add a new student; ID is assigned as random integer [1001-2999]
		void insertFaculty(); //Add a new faculty member; ID is assigned as random integer [1-999]
		void deleteNode(int c); //Delete a student or faculty from database; accounts for referential integrity
		void changeAdvisor(); //Change a student’s advisor given the student id and the new faculty ID; accounts for referential integrity
		void removeAdvisee(); //Remove an advisee from a faculty member given the ID; accounts for referential integrity
		void rollback(); //Undo previous command which altered structure of BST - NOT FINISHED
	
	
	private:
		BST<Student>* masterStudent;
		BST<Faculty>* masterFaculty;
		GenFileIn in;
		bool exitControll;
		
	
};
	
	
#endif