//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment2

#ifndef Assignment2_HPP
#define Assignment2_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <limits>
#include <chrono>
#include <thread>

//For Delay
using namespace std::this_thread;     
using namespace std::chrono_literals; 

//General Get Functions
int getIntInput();
std::string getStringInput();

class Gameboard //Board Generation for All Game Modes
{
	public:
		Gameboard();
		Gameboard(int g, int m); //Takes In Board Generation Type (Manual or File) and Boarder Mode (Standard, Dough, Mirror)
		~Gameboard();
		
		void printBoard(); //Print Current Board
		int getRandomInt(); //Get Random int [1-99]
		void populateBoard(int m); //Populate a Manually Generated Board Based On Boarder Mode (Standard, Dough, Mirror)
		 
		 //Getters
		int** getprimBoard();
		int** getnextBoard();
		int getX();
		int getY();
		
		//Setters
		void setPath(); //Input File Path
		void setName(); //Output File Name
		
		void readFile(); //Read File Input (For Generation Type: File)
		void writeFile(); //Write Current Generation to File
		
		
	private:
		int **primBoard;
		int **nextBoard;
		int x = 5, y = 5;
		int genCounter = 0, writeCounter = 0;

		int line = 1;		
		std::string path; //File Input Path
		std::string name; //Output File Name
		int gridHolder[500]; //Blank Array to Hold File Input Grid
	
};

class Simulation //Updating and Sequencing Boards
{
	public:
		Simulation();
		void update(int** boardCurrent, int** boardNext, int x, int y, int mode); //Main Simulation Control
		void setNeighbors(int** boardCurrent, int x, int y, int z, int k); //Sets Current Cells Neighbors for ALL GAME MODES (Standard, Dough, Mirror)
		int getRule(int x, int y); //Returns State of Board Based On Neighbors
		bool isStable(int** boardCurrent, int x, int y);
		bool isEmpty(int** boardCurrent, int x, int y);
	
	private:
		int stabalizationCheck;
		int neighbors;
	
	
	
	
};





#endif