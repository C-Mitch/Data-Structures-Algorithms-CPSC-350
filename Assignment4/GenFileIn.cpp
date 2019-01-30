//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment4

#include "Assignment4.hpp"

using namespace std;

GenFileIn::GenFileIn()
{
	path = " ";
}

GenFileIn::~GenFileIn()
{
	path = "";
}

std::string GenFileIn::getStringInput()  //General String Input Function
{
	cin.clear();
	std::string in;
	while(!(cin >> in))
	{
		cout << "Enter Valid String" << endl;
		cin.clear();
	}
	return in;
}

void GenFileIn::setPath()  //Valid File Path Setter
{
	while(true)
	{
		cout << "Enter Valid File Path: " << endl;
		path = getStringInput();
		if(validatePath() == false) cout << endl << "FILE NONEXISTANT" << endl << endl;
		else
		{
			cout << endl << "VALID FILE PATH" << endl;
			break;
		}
	}
	
}

bool GenFileIn::validatePath() //Validate A File Path
{
	ifstream in(path);
	if(in)
	{
		in.close();
		return true;
	}
	else if(!in)
	{
		in.close();
		return false;
	}
	
}

bool GenFileIn::validatePath(std::string pathy)
{
	path = pathy;
	validatePath();
}

std::string GenFileIn::getPath() //Get Validated File Path
{
	return path;
}