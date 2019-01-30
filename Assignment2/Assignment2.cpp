//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment2

#include "Assignment2.hpp"

using namespace std;

int getIntInput() //General Integer Input Function
{
	cin.clear();
	int x;

	while(!(cin >> x))
	{
		cout << "Enter Valid Integer Value" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return x;
}

std::string getStringInput()  //General String Input Function
{
	cin.clear();
	std::string in;
	while(!(cin >> in))
	{
		cout << "Enter Valid String" << endl;
		cin.clear();
	}
	//cout << "IN: " << in << endl;
	return in;
}


void Gameboard::setPath()  //Valid File Path Setter
{
	while(true)
	{
		cout << "Enter Valid File Path" << endl;
		path = getStringInput();
		ifstream in(path);
		if(!in) cout << "FILE NONEXISTANT" << endl;
		else if(in)
		{
			cout << "VALID FILE" << endl;
			break;
		}
	}
	
}

void Gameboard::setName() //Set Name of Output File
{
	cout << "Enter Name Of Output File" << endl;
	name = getStringInput();
	
}

void Gameboard::readFile()  //File Reader
{
	ifstream in(path);
	in >> x >> y;  
	//cout << "x: " << x << endl;
	//cout << "y: " << y << endl;
	char c;
	int count = 0;
	in.close();
	
	ifstream inn(path);
	while(inn.get(c))	//Iterate through file and store valid grid characters to temp. array gridHolder
	{
		//cout << "C: " << c << endl;
		if(c == '-') gridHolder[count++] = 0;	
		else if(c == 'X') gridHolder[count++] = 1;
	}
	
	inn.close();

}

void Gameboard::writeFile()  //File Writer
{
	if(writeCounter == 0) //For initial creation of file; truncation if file already exists.
	{
		ofstream out(name, std::ofstream::trunc);
		if(out.is_open()) 
		{
			//cout << "FILE WRITER OPEN" << endl;
			
			out << "Chase Mitchell" << endl << "#002274657" << endl << "Mitch213@mail.chapman.edu" << endl << "CPSC-350-01" << endl << "Assignment2" << endl;
			out << endl << "GAME OF LIFE GENERATIONS" << endl;
			out.close();
		}
		writeCounter++;
	}
	ofstream out(name, std::ofstream::app);
	if(out.is_open()) //For printing boards and generations
	{
		//cout << "FILE WRITER APPENDER" << endl;
		
		out << endl << "GENERATION: " << genCounter << endl;
		
		for(int z = 0; z<x; ++z){
			for(int k = 0; k<y; ++k){
				if(primBoard[z][k] == 0) out << "-";
				else if(primBoard[z][k] == 1) out << "X";
				else if(primBoard[z][k] == 2) out << "#";
				else if(primBoard[z][k] == 3) out << "@";
			}
			out << endl;
		}
	}
	out.close();

}

Gameboard::Gameboard()  //Default Constructor
{
	//Lonely :(
}

Gameboard::Gameboard(int g, int m) //Main Constructor and Grid Generation
{
	srand (time(NULL));

	if(g == 0) //If Manual Generation Selected
	{

		cout << "Enter Row Value" << endl;
		x = getIntInput();
		cout << "Enter Column Value" << endl;
		y = getIntInput();
		
		if(m == 0) //Standard Board
		{
			//cout << "Mode Type 0" << endl;
			primBoard = new int*[x];
				for(int i = 0; i < x; ++i) primBoard[i] = new int[y];
			//nextBoard = new int*[x];
				//for(int i = 0; i < x; ++i) nextBoard[i] = new int[y];    

			populateBoard(0);
			
		}
		else //Dough and Mirror Boards
		{	
			x += 2;
			y += 2;
			primBoard = new int*[x];
				for(int i = 0; i < x; ++i) primBoard[i] = new int[y];		
			
			if(m == 1)
			{
				//cout << "Mode Type 1" << endl;
				populateBoard(1);
			}
			else if(m == 2)
			{
				//cout << "Mode Type 2" << endl;
				populateBoard(2);
			}
		}
	}
	else if(g == 1) //If File Generation Selected
	{
		setPath();
		readFile();
		int count=0;
		if(m == 0) //Standard Board 
		{
			primBoard = new int*[x];
				for(int i = 0; i < x; ++i) primBoard[i] = new int[y];
				
			for(int z = 0; z<x; ++z){
				for(int k = 0; k<y; ++k){
					primBoard[z][k] = gridHolder[count++];
				}
			}
		}		
		else //Dough and Mirror Boards
		{
			x += 2;
			y += 2;	
			primBoard = new int*[x];
				for(int i = 0; i < x; ++i) primBoard[i] = new int[y];

			for(int z = 0; z<x; ++z){
				for(int k = 0; k<y; ++k){
					if(m == 1) primBoard[z][k] = 2;
					else if(m == 2) primBoard[z][k] = 3;
				}
			}
			
			for(int z = 1; z<x-1; ++z){
				for(int k = 1; k<y-1; ++k){
					primBoard[z][k] = gridHolder[count++];
				}
			}	
		}
	}
	//Create Reference Board
	nextBoard = new int*[x];
		for(int i = 0; i < x; ++i) nextBoard[i] = new int[y];
	//Fill Reference Board
	for(int z = 0; z<x; ++z){
		for(int k = 0; k<y; ++k){
			nextBoard[z][k] = primBoard[z][k];
		}
	}
	cout << "Board Generated" << endl << endl;
}

Gameboard::~Gameboard() //Destructor
{
	for(int z = 0; z<x; ++z){
		for(int k = 0; k<y; ++k){
			primBoard[z][k] = NULL;
		}
	}
	
	for(int z = 0; z<x; ++z){
		for(int k = 0; k<y; ++k){
			nextBoard[z][k] = primBoard[z][k];
		}
	}
	delete *primBoard;
	delete *nextBoard;
	
}

int** Gameboard::getprimBoard()
{
	return primBoard;
}

int** Gameboard::getnextBoard()
{
	return nextBoard;
}

int Gameboard::getX()
{
	return x;
}

int Gameboard::getY()
{
	return y;
}

int Gameboard::getRandomInt()  //General Random Integer Generator [1-99]
{
	int a = ((rand() % 100+1));
	//cout << "random int generated: " << a << endl;
	return a;
}

void Gameboard::populateBoard(int m) //Board Population for Manual Board Generation
{
	int p = 0;
	while(p<=0 || p>100) //Get Int [1-99] to be used for random population of board
	{
		cout << "Enter Integer Value greater than 0 and less than or equal to 100 " << endl;
		p = getIntInput();
	}
	
	//cout << " p value: " << p << endl;
	
	int compare = 0;
	if(m == 0) //Set Population for Standard Board
	{
		//Fill In Grid
		for(int z = 0; z<x; ++z){
			for(int k = 0; k<y; ++k){
				compare = getRandomInt();
				if(p<compare) primBoard[z][k] = 0;
				else primBoard[z][k] = 1;
				//cout << primBoard[z][k] << endl;
				compare = 0;
			}
		}
	}
	else
	{
		//Create Boarder for Dough & Mirror
		for(int z = 0; z<x; ++z){
			for(int k = 0; k<y; ++k){
				if(m == 1) primBoard[z][k] = 2;
				else if(m == 2) primBoard[z][k] = 3;
			}
		}		
		
		//Fill In Grid
		for(int z = 1; z<x-1; z++){
			for(int k = 1; k<y-1; k++){
				compare = getRandomInt();
				if(p<compare) primBoard[z][k] = 0;
				else primBoard[z][k] = 1;
				//cout << primBoard[z][k] << endl;
				compare = 0;
			}
		}	
		
	}
	
}

void Gameboard::printBoard() //Current Board Printer
{
	int count = 0;
	//cout << "PRINT BOARD" << endl << endl;
	for(int z = 0; z<x; ++z){
		for(int k = 0; k<y; ++k){
			if(primBoard[z][k] == 0) cout << "-";
			else if(primBoard[z][k] == 1) cout << "X";
			else if(primBoard[z][k] == 2) cout << "#";
			else if(primBoard[z][k] == 3) cout << "@";
			++count;
		}
		cout << endl;
	}
	//cout << "counter total: " << count << endl;
	cout << "GENERATION: " << genCounter++ << endl;
}


Simulation::Simulation() //Simulation Constructor
{
	cout << "Simulation Created" << endl << endl;
	//Also Lonely :{
}

void Simulation::update(int** boardCurrent, int** boardNext, int x, int y, int mode)  //Main Simulation Sequencing Control
{
	if(mode == 0) //Standard Game Mode
	{
		for(int z = 0; z<x; ++z){
			for(int k = 0; k<y; ++k){
				
				setNeighbors(boardCurrent, x, y, z, k);
				//cout << "Neighbors Set" << endl;
				if(getRule(z,k) != 2) boardNext[z][k] = getRule(z,k);
			}
		}
	}
	else if(mode == 1 || mode == 2) //Dough or Mirror Mode
	{
		for(int z = 1; z<x-1; ++z){
			for(int k = 1; k<y-1; ++k){
				
				setNeighbors(boardCurrent, x, y, z, k);
				//cout << "Neighbors Set" << endl;
				if(getRule(z,k) != 2) boardNext[z][k] = getRule(z,k);
			}
		}
	}
	
	//Set Current Board to Next Board
	for(int z = 0; z<x; ++z){
		for(int k = 0; k<y; ++k){
			boardCurrent[z][k] = boardNext[z][k];
		}
	}
}

void Simulation::setNeighbors(int** boardCurrent, int x, int y, int z, int k) //Neighbor Checker/Setter for All Game Modes
{
	neighbors = 0;
	cout << "boardCurrent: " << boardCurrent[z][k] << endl;
	
	//Check Below Condition (Y-1)
	if(k+1 < y){
		//cout << "IN DOWN" << endl;
		if(boardCurrent[z][k] == boardCurrent[z][k+1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z][k+1] << endl;}
		else if(boardCurrent[z][k+1] == 2)  //Dough Mode
		{
			if(boardCurrent[z][k] == boardCurrent[z][1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z][1] << endl;}
		}
		else if(boardCurrent[z][k+1] == 3)  //Mirror Mode
		{
			++neighbors; //cout << "	NEIGHBOR FOUND: " << boardCurrent[z][k] << endl;
		}
	}
	//Check Above Condition (Y+1)
	if(k-1 >= 0){
		//cout << "IN UP" << endl;
		if(boardCurrent[z][k] == boardCurrent[z][k-1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z][k-1] << endl;}
		else if(boardCurrent[z][k-1] == 2) //Dough Mode
		{
			if(boardCurrent[z][k] == boardCurrent[z][y-2]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z][y-2] << endl;}
		}
		else if(boardCurrent[z][k-1] == 3) //Mirror Mode
		{
			++neighbors; //cout << "	NEIGHBOR FOUND: " << boardCurrent[z][k] << endl;
		}
	}
	//Check Back Condition (X-1)
	if(z-1 >= 0){
		//cout << "IN BACK" << endl;
		if(boardCurrent[z][k] == boardCurrent[z-1][k]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z-1][k] << endl;}
		else if(boardCurrent[z-1][k] == 2)  //Dough Mode
		{
			if(boardCurrent[z][k] == boardCurrent[x-2][k]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[x-2][k] << endl;}
		}
		else if(boardCurrent[z-1][k] == 3) //Mirror Mode
		{
			++neighbors; //cout << "	NEIGHBOR FOUND: " << boardCurrent[z][k] << endl;
		}
	}
	//Check Front Condition (X+1)
	if(z+1 < x){
		//cout << "IN FORWARD" << endl;
		if(boardCurrent[z][k] == boardCurrent[z+1][k]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z+1][k] << endl;}
		else if(boardCurrent[z+1][k] == 2) //Dough Mode
		{
			if(boardCurrent[z][k] == boardCurrent[1][k]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[1][k] << endl;}
		}
		else if(boardCurrent[z+1][k] == 3) //Mirror Mode
		{
			++neighbors; //cout << "	NEIGHBOR FOUND: " << boardCurrent[z][k] << endl;
		}
	}
	//Check Back and Up Condition (X-1&&Y-1)
	if(z-1 >= 0 && k-1 >= 0){
		//cout << "IN BACK+UP" << endl;
		if(boardCurrent[z][k] == boardCurrent[z-1][k-1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z-1][k-1] << endl;}
		else if(boardCurrent[z-1][k-1] == 2) //Dough Mode
		{
			if(k == 1 && z == 1) //For Specifically Top-Left Corner
			{
				if(boardCurrent[z][k] == boardCurrent[x-2][y-2]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (CORNER): " << boardCurrent[x-2][y-2] << endl;}
			}
			else if(z == 1)  //For X-Axis Values
			{
				if(boardCurrent[z][k] == boardCurrent[x-2][k-1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (Z/X): " << boardCurrent[x-2][k-1] << endl;}
			}
			else if(k == 1)  //For Y-Axis Values
			{
				if(boardCurrent[z][k] == boardCurrent[z-1][y-2]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (K/Y): " << boardCurrent[z-1][y-2] << endl;}
			}
		}
		else if(boardCurrent[z-1][k-1] == 3) //Mirror Mode - For Top-Left Corner
		{
			if(k == 1 && z == 1) ++neighbors; //{++neighbors; cout << "3 FOUND; IN LOOP BACK+UP" << endl << "	NEIGHBOR FOUND (CORNER): " << boardCurrent[z][k] << endl;}
		}
	}
	//Check Back and Down Condition (X-1&&Y+1)
	if(z-1 >= 0 && k+1 < y){
		//cout << "IN BACK+DOWN" << endl;
		if(boardCurrent[z][k] == boardCurrent[z-1][k+1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z-1][k+1] << endl;}
		else if(boardCurrent[z-1][k+1] == 2) //Dough Mode
		{
			if(k == y-2 && z == 1) //For Specifically Bottom-Left Corner
			{
				if(boardCurrent[z][k] == boardCurrent[x-2][1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (CORNER): " << boardCurrent[x-2][1] << endl;}
			}
			else if(z == 1) //For X-Axis Values
			{
				if(boardCurrent[z][k] == boardCurrent[x-2][k+1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (Z/X): " << boardCurrent[x-2][k+1] << endl;}
			}
			else if(k == y-2) //For Y-Axis Values
			{
				if(boardCurrent[z][k] == boardCurrent[z-1][1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (K/Y): " << boardCurrent[z-1][1] << endl;}
			}
		}
		else if(boardCurrent[z-1][k+1] == 3) //Mirror Mode - For Bottom-Left Corner
		{
			if(k == y-2 && z == 1) ++neighbors; //{++neighbors; cout << "3 FOUND; IN LOOP BACK+DOWN" << endl << "	NEIGHBOR FOUND (CORNER): " << boardCurrent[z][k] << endl;}
		}
	}
	//Check Forward and Up Condition (X+1&&Y-1)
	if(z+1 < x && k-1 >= 0){
		//cout << "IN FORWARD+UP" << endl;
		if(boardCurrent[z][k] == boardCurrent[z+1][k-1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z+1][k-1] << endl;}
		else if(boardCurrent[z+1][k-1] == 2) //Dough Mode
		{
			if(k == 1 && z == x-2) //For Specifically Top-Right Corner
			{
				if(boardCurrent[z][k] == boardCurrent[1][y-2]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (CORNER): " << boardCurrent[1][y-2] << endl;}
			}
			else if(z == x-2) //For X-Axis Values
			{
				if(boardCurrent[z][k] == boardCurrent[1][k-1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (Z/X): " << boardCurrent[1][k-1] << endl;}
			}
			else if(k == 1) //For Y-Axis Values
			{
				if(boardCurrent[z][k] == boardCurrent[z+1][y-2]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (K/Y): " << boardCurrent[z+1][y-2] << endl;}
			}
		}
		else if(boardCurrent[z+1][k-1] == 3) //Mirror Mode - Top-Right Corner
		{
			if(k == 1 && z == x-2) ++neighbors; //{++neighbors; cout << "3 FOUND; IN LOOP FORWARD+UP" << endl << "	NEIGHBOR FOUND (CORNER): " << boardCurrent[z][k] << endl;}
		}
	}
	//Check Forward and Down Condition (X+1&&Y+1)
	if(z+1 < x && k+1 < y){
		//cout << "IN FORWARD+DOWN" << endl;
		if(boardCurrent[z][k] == boardCurrent[z+1][k+1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND: " << boardCurrent[z+1][k+1] << endl;}
		else if(boardCurrent[z+1][k+1] == 2)  //Dough Mode
		{
			if(k == y-2 && z == x-2) //For Specifically Bottom-Right Corner
			{
				if(boardCurrent[z][k] == boardCurrent[1][1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (CORNER): " << boardCurrent[1][1] << endl;}
			}
			else if(z == x-2) //For X-Axis Values
			{
				if(boardCurrent[z][k] == boardCurrent[1][k+1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (Z/X): " << boardCurrent[1][y-2] << endl;}
			}
			else if(k == y-2) //For Y-Axis Values
			{
				if(boardCurrent[z][k] == boardCurrent[z+1][1]) ++neighbors; //{++neighbors; cout << "	NEIGHBOR FOUND (K/Y): " << boardCurrent[z+1][1] << endl;}
			}
		}
		else if(boardCurrent[z+1][k+1] == 3) //Mirror Mode - Bottom-Right Corner
		{
			if(k == y-2 && z == x-2) ++neighbors; //{++neighbors; cout << "3 FOUND; IN LOOP FORWARD+DOWN" << endl << "	NEIGHBOR FOUND (CORNER): " << boardCurrent[z][k] << endl;}
		}
	}
	
	//cout << "  neighbors: " << neighbors << endl;
}
		
int Simulation::getRule(int x, int y) //Returns the Status of Cell Based on It's Neighbors
{
	if(neighbors <= 1) return 0;
	else if(neighbors == 2) return 2;
	else if(neighbors == 3) return 1;
	else if(neighbors >= 4) return 0;

}

bool Simulation::isEmpty(int** boardCurrent, int x, int y) //Checks for Empty Grid
{
	//Assume Grid Is Empty
	int check = 0;
	for(int z = 0; z<x; ++z){
		for(int k = 0; k<y; ++k){
			if(boardCurrent[z][k] == 1) check = 1; //If a Cell Lives, Set False
		}
	}
	
	if(check == 0) return true;
	else return false;
	
}

bool Simulation::isStable(int** boardCurrent, int x, int y) //Check for Stability Across 1 Generation Gap
{
	//Get Number of Alive Cells in Current Grid
	int check = 0;
	for(int z = 0; z<x; ++z){
		for(int k = 0; k<y; ++k){
			if(boardCurrent[z][k] == 1) check++;
		}
	}
	
	//Compare Number of Alive Cells to Previous Check of Alive Cells
	//Since isStable is called for every even Generation: Compares GenCurrent == GenCurrent-2
	if(check == stabalizationCheck) return true;
	else
	{
		stabalizationCheck = check;
		return false;
	}
}

