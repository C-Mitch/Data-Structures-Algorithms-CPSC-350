//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment6

#include <iostream>
#include <fstream>
#include <istream>
#include <limits>
#include <string>
#include <chrono>


using namespace std;

#ifndef Assignment6_HPP
#define Assignment6_HPP

	
//A general object to get and validate file/standard input
class GenFileIn
{
	public:
		GenFileIn();
		~GenFileIn();
		
		void setPath(); //Sets a file path to be used
		void setPath(std::string p); //Sets a file path to be used
		std::string getStringInput(); //Gets general string input
		int getIntInput(); //Gets general integer input
		double getDoubleInput(); //Gets general double input
		std::string getPath(); //Gets a file path and validates it, loops till valid file path found
		bool validatePath(); //A test to check if a path is valid, returns true if path connects, false if not
		bool validatePath(std::string pathy); //Overloaded test to check if given path is valid, returns true if path connects, false if not
		
	private:
		std::string path; //Std::string to hold a file path
	
};
//An object to read double content from given file and write to an array
class FileIn
{
	public:
		FileIn();
		FileIn(std::string p);
		~FileIn();
		
		void readInput(); //Read double input from given file and transfer to array
		double* getArray(); //Return Double* array containing file contents
		int getSize(); //Return size of array for iteration
		
	private:
		std::string path;
		double *holder;
		int size = 0;
};

//An object to handle sorting algorithm implementation and calculate approx. time ellapsed in microseconds
class Simulation
{
	
	public:
		Simulation();
		Simulation(double* d, int s);
		~Simulation();
		
		void Run();  //Centeral Control For Simulation
		void quickSort(double arrPtr[]); //Quick Sort Primer
		void quickSort(double arr[], double lo, double hi); //Quick Sort
		void swap(double* a, double* b); //General Swap Utility
		double partition(double arr[], int lo, int hi); //Partition function to set last element as pivot orders it; redistribute other values of array either less than or greater than pivot
		void insertionSort(double arrPtr[]); //Insertion Sort
		void bubbleSort(double arrPtr[]); //Bubble Sort
		void flip(double arr[], int i); //Flip Function; Reverse Array[0-i]
		int findMax(double arr[], int n); //Simple Indexer; Returns Index of Max Element in Array
		void pancakeSort(double arrPtr[]); //Pancake Sort Primer
		void pancakeSort(double *arr, int n); //Pancake Sort
	
	private:
		double* array;
		int size;
	
};
	
#endif