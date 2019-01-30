//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment4

#include "Assignment4.hpp"


using namespace std;

int main(int argc, char** argv)
{
	if(argc > 1)
	{
		GenFileIn fin;
		if(fin.validatePath(argv[1]) == false)
		{
			cout << "Invalid File Path" << endl;
			while(true)
			{
				fin.setPath();
				if(fin.validatePath() == true) break;
			}
		}
		else cout << "Valid File Path" << endl;
				
		FileIn input(fin.getPath());
		input.readInput();
		int array[input.getSize()] = {};
		for(int x = 0; x < input.getSize(); ++x) array[x] = input.getArray()[x];
		
		Registrar regi(array, input.getSize());
		regi.simulation();
		regi.statistics();
		
	}
	else cout << "Pass a File Path at Execution" << endl;
	
	return 0;
	
}