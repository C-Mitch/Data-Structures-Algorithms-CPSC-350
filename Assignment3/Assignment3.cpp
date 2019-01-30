//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment3

#include "Assignment3.hpp"

using namespace std;

GenFileIO::GenFileIO()
{
	path = " ";
}

GenFileIO::~GenFileIO()
{
	path = "";
}

std::string GenFileIO::getStringInput()  //General String Input Function
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

void GenFileIO::setPath()  //Valid File Path Setter
{
	while(true)
	{
		cout << "Enter Valid File Path: " << endl;
		path = getStringInput();
		if(validatePath() == false) cout << endl << "FILE NONEXISTANT" << endl << endl;
		else
		{
			cout << endl << "VALID FILE PATH" << endl << endl;
			break;
		}
	}
	
}

bool GenFileIO::validatePath() //Validate A File Path
{
	ifstream in(path);
	if(in) return true;
	else if(!in) return false;
	
}

std::string GenFileIO::getPath() //Get Validated File Path
{
	return path;
}


Delimiter::Delimiter()
{
	lineCount = 1;
	cout << "Delimiter Constructed" << endl;
}


Delimiter::~Delimiter()
{
	// ¯\_(ツ)_/¯
}

void Delimiter::readFile(std::string path) //Read Input File For Valid Delimiters
{
	char c;
	ifstream in(path);
	
	while(in.get(c))
	{
		if(stack.isFull()) stack.increaseSize();
		//cout << "Current C Value: " << c << endl;
		
		if(c == '{' || c == '[' || c == '(') stack.push(c); // Push {, [, ( to stack
		else if(c == '}')
		{
			if(stack.peek() == '{') stack.pop(); //Valid End Delimiter; Pop Off Stack
			else if(stack.isEmpty() == false) //Invalid End Delimiter; Print Error && Terminate
			{
				printError(c);
				cout << endl << "Exiting" << endl;
				stack.~GenStack();
				exit(EXIT_SUCCESS);
			}
			else stack.push(c); //For Cases of End Delimiter Declaration Without Opening Delimiter Declaration
		}
		else if(c == ']')
		{
			if(stack.peek() == '[') stack.pop(); //Valid End Delimiter; Pop Off Stack
			else if(stack.isEmpty() == false) //Invalid End Delimiter; Print Error && Terminate
			{
				printError(c);
				cout << endl << "Exiting" << endl;
				stack.~GenStack();
				exit(EXIT_SUCCESS);
			}
			else stack.push(c); //For Cases of End Delimiter Declaration Without Opening Delimiter Declaration
		}
		else if(c == ')')
		{
			if(stack.peek() == '(') stack.pop(); //Valid End Delimiter; Pop Off Stack
			else if(stack.isEmpty() == false) //Invalid End Delimiter; Print Error && Terminate
			{
				printError(c);
				cout << endl << "Exiting" << endl;
				stack.~GenStack();
				exit(EXIT_SUCCESS);
			}
			else stack.push(c); //For Cases of End Delimiter Declaration Without Opening Delimiter Declaration
		}
		else if(c == '\n') lineCount++; //Update Line Count At New Line

	}
	
	//End Delimiter Checks
	if(stack.isEmpty() == false)
	{
		cout << endl << "Delimiter Error: " << endl << endl;
		
		//In event of end of file reached and prior checks inconclusive:
		if(stack.peek() == '(') cout << "	Line " << lineCount << ": Found Open ( Expecting Closing )" << endl;
		else if(stack.peek() == '[') cout << "	Line " << lineCount << ": Found Open [ Expecting Closing ]" << endl;
		else if(stack.peek() == '{') cout << "Reached End Of File: Missing }" << endl;
		else if(stack.peek() == ')') cout << "	Line " << lineCount << ": Found Closing ) Without Prior Opening ( Declaration" << endl;
		else if(stack.peek() == '}') cout << "	Line " << lineCount << ": Found Closing } Without Prior Opening { Declaration" << endl;
		else if(stack.peek() == ']') cout << "	Line " << lineCount << ": Found Closing ] Without Prior Opening [ Declaration" << endl;
	}
	else cout << endl << "File Check Complete; Everything Good!" << endl;

}

void Delimiter::printError(char c) //Prints Delimiter Error
{
	cout << endl << "Delimiter Error: " << endl << endl;
	
	//Error Conditions
	if(stack.peek() == '(')  cout << "	Line " << lineCount << ": Found " << c << " Expecting )" << endl;
	else if(stack.peek() == '{') cout << "	Line " << lineCount << ": Found " << c << " Expecting }" << endl;
	else if(stack.peek() == '[') cout << "	Line " << lineCount << ": Found " << c << " Expecting ]" << endl;
	
}