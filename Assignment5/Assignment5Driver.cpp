//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5

#include "Assignment5.hpp"

using namespace std;

int main(int argc, char** argv)
{
	srand (time(NULL));
	
	if(argc > 1)
	{
		
		Simulation *sim = new Simulation();
		sim->run();
		
	}
	else cout << "Pass an Arguement at Execution" << endl;
	
	return 0;

}
