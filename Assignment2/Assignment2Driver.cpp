//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment2

#include "Assignment2.hpp"

using namespace std;


int main()
{

	cout << endl << "Welcome To The Game Of Life Simulation" << endl << endl;
	
	cout << "Enter Board Generation Mode: " << endl
		<< "	-Manual Entry: 'M'" << endl
		<< "	-File Entry:   'F'" << endl;
	std::string in = " ";
	int genType;
	while(true)
	{
		in = getStringInput();
		
		if(in == "M")
		{
			cout << endl <<  "Manual Grid Generation Selected" << endl << endl;
			genType = 0;
			break;
		}
		else if(in == "F")
		{
			cout << endl <<  "File Grid Generation Selected" << endl << endl;
			genType = 1;
			break;
		}
		else cout << "Please Enter Valid Input" << endl;
		
	}
	
	cout << "Enter Simulation Boarder Mode: " << endl
		<< "	-Standard Mode: 'S'" << endl
		<< "	-Doughnut Mode: 'D'" << endl
		<< "	-Mirror Mode:   'M'" << endl;
	in = " ";
	int modeType;
	while(true)
	{
		in = getStringInput();
		
		if(in == "S")
		{
			cout << endl <<  "Standard Boarder Mode Selected" << endl << endl;
			modeType = 0;
			break;
		}
		else if(in == "D")
		{
			cout << endl <<  "Doughnut Boarder Mode Selected" << endl << endl;
			modeType = 1;
			break;
		}
		else if(in == "M")
		{
			cout << endl <<  "Mirror Boarder Mode Selected" << endl << endl;
			modeType = 2;
			break;
		}
		else cout << "Please Enter Valid Input" << endl;
		
	}
	
	Gameboard board(genType, modeType);
	
	cout << endl << "Output Generations To File? " << endl
		<< "	-Yes:	'Y'" << endl
		<< "	-No:	'N'" << endl;
	in = " ";
	int writerType;
	while(true)
	{
		in = getStringInput();
		
		if(in == "Y")
		{
			cout << endl <<  "File Output Selected" << endl << endl;
			board.setName();
			board.writeFile();
			writerType = 0;
			break;
		}
		else if(in == "N")
		{
			cout << endl <<  "File Output Not Selected" << endl << endl;
			writerType = 1;
			break;
		}
		else cout << "Please Enter Valid Input" << endl;
	}

	cout << "Enter Simulation Sequencing Mode: " << endl
		<< "	-Manual Iteration Mode: 'M'" << endl
		<< "	-Delay Mode: 		'D'" << endl
		<< "	-Instant Mode:   	'I'" << endl;
	in = " ";
	int sequencerType;
	while(true)
	{
		in = getStringInput();
		
		if(in == "M")
		{
			cout << endl <<  "Manual Iteration Mode Selected" << endl << endl;
			sequencerType = 0;
			break;
		}
		else if(in == "D")
		{
			cout << endl <<  "Delay Mode Selected" << endl << endl;
			sequencerType = 1;
			break;
		}
		else if(in == "I")
		{
			cout << endl <<  "Instant Mode Selected" << endl << endl;
			sequencerType = 2;
			break;
		}
		else cout << "Please Enter Valid Input" << endl;
	}
	
	Simulation sim;
	int modX = 1;
	board.printBoard();
	
	while(true)
	{
		if(sequencerType == 0)
		{
			cout << "Press 'ENTER' To Proceed" << endl;
			std::cin.get();
		}
		else if(sequencerType == 1)
		{
			sleep_for(3s);
		}

		sim.update(board.getprimBoard(), board.getnextBoard(), board.getX(), board.getY(), modeType);
		
		if(writerType == 0) board.writeFile();
		board.printBoard();
		
		if(modX++%2 == 0){
			if(sim.isStable(board.getprimBoard(), board.getX(), board.getY()))
			{
				cout << endl << "BOARD IS STABLE" << endl;
				break;
			}
		}
		if(sim.isEmpty(board.getprimBoard(), board.getX(), board.getY()))
		{
			cout << endl << "BOARD IS EMPTY" << endl;
			break;
		}
		
	}
	
	cout << endl << "The Simulation Has Ended" << endl << endl;
	
	return 0;
}