//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment3

#include "Assignment3.hpp"

using namespace std;

int main(int argc, char** argv)
{
	if(argc > 1)
	{
		cout << endl << "SOURCE CODE DELIMITER SYNTAX ANALYZER" << endl << endl;
		
		cout << "Please Enter File To Check Delimiters" << endl << endl;
		
		GenFileIO fio;
		while(true)
		{
			fio.setPath();
			if(fio.validatePath() == true) break;
		}
		
		Delimiter check;
		std::string in = " ";
		
		while(true)
		{
			check.readFile(fio.getPath());
			
			in = " ";
			while(in != "Y" && in != "N")
			{
				cout << endl << "Check Another File?" << endl << 
				"	-Yes (Y)" << endl << "	-No (N)" <<endl;
				
				in = fio.getStringInput();
				
			}
			
			if(in == "N") break;
			else
			{
				while(true)
				{
					fio.setPath();
					if(fio.validatePath() == true) break;
				}
			}
			
		}
		
		
	}
	else cout << "Pass an argument at execution please." << endl;
	
	return 0;
}
