//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment4

#include "Assignment4.hpp"

using namespace std;

Registrar::Registrar() //Standard - Unused
{
	windows = new Window[5];
}

Registrar::Registrar(int arr[], int size) //Overloaded - Used; Passed values from FileIn
{
	tick = 0;
	arraySize = arr[0]; //Number of windows specified in file input
	windows = new Window[arraySize];
	
	for(int y = 0; y < arraySize; ++y) //Fills window array with windows
	{
		Window windy;
		windows[y] = windy;
	}
	
	studentQueue = new GenQueue<Student>(); //Student Queue implementation
	int z = 2; //Default posision of first student creation requst in input array
	while(z < size)  //Fills student queue with generic student objects
	{
		int temp1 = z; //temp1 handles student arrival time
		int temp2 = z; //temp2 handles student time needed
		int temp3 = arr[z]; //temp3 handles number of students to be created at given time
		z += temp3+2; //increment z to next student creation request in input array
		while(temp3-->0)
		{
			Student stud(arr[temp1-1], arr[++temp2]);
			studentQueue->insert(stud);
		}
	}
	
	waitArraySize = studentQueue->getSize();
	waitArray = new int[waitArraySize];

}

Registrar::~Registrar()
{
	
}

void Registrar::simulation() //Main processing function
{
	//Usefull local variables
	int waitArrayTracker = 0;
	int exitInt = 0; //Exit controll
	
	while(true) //Main Simulation Loop
	{
		//cout << "Current Tick: " << tick << endl;
		exitInt = 0;
		for(int y = 0; y < arraySize; ++y) //Checks if occupied window has completed servicing request using current tick
		{
			if(windows[y].isEmpty() == false)
			{
				if(windows[y].isServicingComplete(tick) == true) windows[y].setServicing(false); 
			}
			else exitInt++; //All windows empty, Half-condition for ending simulation
		}
		
		if(studentQueue->isEmpty() == false) //Check if array is empty
		{
			while(studentQueue->peek().getArrivalTime() <= tick) //Check if front student has arrived
			{
				int track = 0;
				for(int x = 0; x < arraySize; ++x) //Handles finding an empty window, if availible
				{
					if(windows[x].isEmpty() == true) //If empty window found, set parameters and remove student from queue
					{
						//cout << "Student Queue Arrival Time: " << studentQueue->peek().getArrivalTime() << endl;
						//cout << "Window: " << x << " Now Servicing" << endl;
						windows[x].setServicing(true);
						windows[x].setServicingTime(studentQueue->peek().getTimeNeeded(), tick);
						studentQueue->peek().setWaitTime(tick);
						//cout << "Student Wait Time: " << studentQueue->peek().getWaitTime() << endl;
						waitArray[waitArrayTracker++] = studentQueue->remove().getWaitTime();
						break;
					}
					else track++;
				}
				if(track == arraySize) break; //No Empty Windows, Pass till next tick
				else if(studentQueue->isEmpty() == true) break; //Queue is empty, Half-condition for ending simulation
			}
		}
		
		if(studentQueue->isEmpty() == true && exitInt == arraySize) break; //If queue is empty and all students service, simulation ends
		else if(tick == 1000)  break; //Precautionary end case
		
		tick++; //Tick incrementer
		for(int z = 0; z < arraySize; ++z) windows[z].setIdle(tick); //Handles idle counter incrementation in windows

	}
	
	cout << endl << "Simulation Loop Exited On Tick: " << tick << endl << endl;
}


void Registrar::statistics() //Statistical output
{
	
	for(int x = 0; x < arraySize; ++x) //Handles Idle Calculations
	{	
		totalIdle += windows[x].getTotalIdle();
		if(maxIdle < windows[x].getLongestIdle()) maxIdle = windows[x].getLongestIdle();
		if(windows[x].getTotalIdle() > 5) idleOver5++;
	}
	
	for(int y = 0; y < waitArraySize; ++y) //Handles Wait Calculations
	{
		totalWait += waitArray[y];
		if(maxWait < waitArray[y]) maxWait = waitArray[y];
		if(waitArray[y] > 10) waitOver10++;
	}
	
	int temp;
	for(int z = 0; z < waitArraySize; ++z) //Order Wait Times Ascending to Find Median
	{
		for(int k = 0; k < waitArraySize; ++k)
		{
			if(waitArray[k] > waitArray[k+1])
			{
				temp = waitArray[k];
				waitArray[k] = waitArray[k+1];
				waitArray[k+1] = temp;
			}
		}
	}
	
	medianWait = waitArray[waitArraySize/2];
	
	cout << "STATISTICS: " << endl << endl;
	
	cout << "	Mean Student Wait Time: " << (totalWait/waitArraySize) << endl;
	cout << "	Median Student Wait Time: " <<  medianWait << endl;
	cout << "	Longest Student Wait Time: " <<  maxWait << endl;
	cout << "	Students Wait Time Over 10 Minutes: " <<  waitOver10 << endl;
	cout << "	Mean Window Idle Time: " <<  (totalIdle/arraySize) << endl;
	cout << "	Longest Window Idle Time: " <<  maxIdle << endl;
	cout << "	Windows Idle Time Over 5 Minutes: " << idleOver5 << endl;
	
	/*
	cout << "TOTAL IDLE" << endl;
	for(int z = 0; z < arraySize; ++z) totalIdle += cout << "Window " << z << ": " <<  windows[z].getTotalIdle() << endl;
	
	cout << "LONGEST IDLE" << endl;
	for(int x = 0; x < arraySize; ++x) cout << "Window " << x << ": " <<  windows[x].getLongestIdle() << endl;
	
	cout << "WAIT TIMES" << endl;
	for(int y = 0; y < 3; ++y) cout << "Student " << y << ": " <<  waitArray[y] << endl;
	*/
}

