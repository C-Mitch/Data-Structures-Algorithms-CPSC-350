//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment4

#include "Assignment4.hpp"


FileIn::FileIn() //Standard - Unused
{
	path = "";
}

FileIn::FileIn(std::string p) //Overloaded - Used
{
	path = p;
	int z = 0;
	size = 0;
	ifstream in(path);
	while(in >> z) size++; //Set # of lines in file for holding array
	holder = new int[size];
	in.close();
}

FileIn::~FileIn()
{
	path = "";
	delete holder;
}

void FileIn::readInput() //Transfer file input to holder array
{
	int t, k = 0;
	ifstream inn(path);
	while(inn >> t) holder[k++] = t;

	//for(int x = 0; x < size; ++x) cout << "Holder Contains: " << holder[x] << " at: " << x << endl;
	inn.close();
}

int * FileIn::getArray()
{
	return holder;
}

int FileIn::getSize()
{
	return size;
}

Student::Student() //Standard - Unused
{
	arrivalTime = 0;
	timeNeeded = 5;
	waitTime = 0;
}

Student::Student(int arrival, int needed) //Overloaded - Used *Note Bug With waitTime In README*
{
	arrivalTime = arrival;
	timeNeeded = needed;
	waitTime = 0;
}

Student::~Student()
{
	
}

int Student::getWaitTime()
{
	//cout << waitTime << endl;
	return waitTime;
}

int Student::getArrivalTime()
{
	return arrivalTime;
}

int Student::getTimeNeeded()
{
	return timeNeeded;
}

void Student::setWaitTime(int tick) //Uses tick value from Registrar
{
	waitTime = (tick-arrivalTime);
	//cout << waitTime << endl;
}


Window::Window() //Standard - Used
{
	totalIdle = 0;
	longestIdle = 0;
	servicing = false;
}

Window::~Window()
{
	
}

void Window::setServicing(bool c)  //Boolean Pass
{
	servicing = c;
}

void Window::setServicingTime(int timeNeeded, int tick) //Uses timeNeeded from student and tick from registrar
{
	servicingTime = timeNeeded+tick;
}

void Window::setIdle(int tick) //Uses current tick from registrar
{
	if(servicing == false)
	{	
		totalIdle++;
	}
	else
	{ 
		if(totalIdle-longestIdle > longestIdle) longestIdle = totalIdle-longestIdle;
	}
	
	if(totalIdle == tick) longestIdle = totalIdle;
	
}

bool Window::isEmpty()
{
	if(servicing == false) return true;
	else return false;
}

bool Window::isServicingComplete(int tick) //Uses current tick from registrar
{
	if(servicingTime == tick) return true;
	else return false;
}

int Window::getTotalIdle()
{
	return totalIdle;
}

int Window::getLongestIdle()
{
	return longestIdle;
}

