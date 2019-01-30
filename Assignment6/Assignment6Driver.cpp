//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment6

#include "Assignment6.hpp"

using namespace std;

int main(int argc, char** argv)
{	
	if(argc > 1)
	{
		GenFileIn fin;
		std::string path = argv[1];
		if(fin.validatePath(path) == false)
		{
			cout << "Invalid File Path" << endl;
			while(true)
			{
				fin.setPath();
				if(fin.validatePath() == true) break;
			}
		}
		else cout << "Valid File Path" << endl;
		
		cout << " "; //Clear Out Stream
		FileIn input(fin.getPath());
		
		Simulation sim(input.getArray(), input.getSize());
		
		sim.Run();
		
	}
	else cout << "Pass a valid file path at execution" << endl;
	
	return 0;

}



