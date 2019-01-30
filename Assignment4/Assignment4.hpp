//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment4

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "GenQueue.hpp"

using namespace std;

#ifndef Assignment4_HPP
#define Assignment4_HPP

//A general object to get and validate file input
class GenFileIn
{
	public:
		GenFileIn();
		~GenFileIn();
		
		void setPath(); //Sets a file path to be used
		std::string getStringInput(); //Gets general string input
		std::string getPath(); //Gets a file path and validates it, loops till valid file path found
		bool validatePath(); //A test to check if a path is valid, returns true if path connects, false if not
		bool validatePath(std::string pathy); //Overloaded test to check if given path is valid, returns true if path connects, false if not
		
	private:
		std::string path; //Std::string to hold a file path
	
};

//An object to get file input and transfer to array for easier access
class FileIn
{
	public:
		FileIn();
		FileIn(std::string p);
		~FileIn();
		
		void readInput(); //Read integer input from given file and transfer to array for eaier access
		int* getArray(); //Return Int* array containing file contents
		int getSize(); //Return size of array for iteration
		
	private:
		std::string path;
		int *holder;
		int size = 0;
};

//An object to store information pertaining to a student to be used in Registrar simulation
class Student
{
	public:
		Student();
		Student(int arrival, int needed);
		~Student();
		
		int getWaitTime();  //*Note Bug With waitTime In README*
		int getArrivalTime();
		int getTimeNeeded();
		void setWaitTime(int tick); //Set waitTime using passed int tick from Registrar
		
		
	private:
		int arrivalTime;
		int timeNeeded;
		int waitTime; //*Note Bug With waitTime In README*
	
};

//An object to store information on windows used in Registrar simulation
class Window
{
	public:
		Window();
		~Window();
		
		void setServicing(bool c); //Set servicing status of window; false by default constructor
		void setServicingTime(int timeNeeded, int tick); //Set servicing time; adds timeNeeded to current simulation tick for servicing time needed
		void setIdle(int tick); //Set totalIdle and longestIdle for given window.
		int getTotalIdle();
		int getLongestIdle();
		bool isEmpty(); //Boolean check if window is currently servicing student; true by default constructor
		bool isServicingComplete(int tick); //Boolean check if servicing time has concluded; takes current simulation tick for check.
		
	private:
		int totalIdle;
		int longestIdle;
		int servicingTime;
		bool servicing;
		
};

//A main object used to create and run a simulation of a registrar office, as well as output statistics on simulation
class Registrar
{
	public:
		Registrar();
		Registrar(int arr[], int size);  //Handles construction of most objects used in simulation, including window arrays and student queues
		~Registrar();
		
		void statistics(); //Statistic output to standard out using information calculated during simulation
		void simulation(); //Main simulation of Registrar, handles usage of winow array and student queue interactions
		
	private:
		Window *windows; //Array of windows
		GenQueue <Student> *studentQueue; //Queue of students
		
		int *waitArray; //Hold student wait times after being removed from queue
		int tick; //Global measurment of time
		int arraySize; //Size of window array;
		int waitArraySize;  //Size of wait array;
		
		double totalIdle = 0;
		double totalWait = 0;
		double maxIdle = 0;
		int maxWait = 0;
		int idleOver5 = 0;
		int waitOver10 = 0;
		double medianWait = 0;

};

#endif