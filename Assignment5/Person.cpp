//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5

#include "Person.hpp"


Person::Person()
{
	name = "John Doe";
	level = "Beginer";
	ID = 0;
}

Person::Person(std::string n, std::string l)
{
	name = n;
	level = l;
	ID = 0;
}

Person::~Person()
{

}

void Person::setName(std::string n)
{
	name = n;
}

void Person::setLevel(std::string l)
{
	level = l;
}

std::string Person::getName()
{
	return name;
}

std::string Person::getLevel()
{
	return level;
}

int Person::getID()
{
	return ID;
}

bool Person::operator==(const Person& b)
{
	return this->ID == b.ID;
}

bool Person::operator<(const Person& b) 
{
  	return this->ID < b.ID;
}

bool Person::operator>(const Person& b) 
{
    return this->ID > b.ID;
}

bool Person::operator!=(const Person& b) 
{
    return !(this->ID == b.ID);
}

bool Person::operator!=(const long int b) 
{
    return !(this->ID == b);
}



Student::Student()
{
	ID = setStudentID();
	major = "";
	gpa = 0.0;
	facultyID = 0;
	
	
}

Student::Student(std::string n, std::string l, std::string m, double g, int f)
{
	setName(n);
	setLevel(l);
	ID = setStudentID();
	major = m;
	gpa = g;
	facultyID = f;
	
}

Student::~Student()
{

}

void Student::setMajor(std::string m)
{
	major = m;	
}

void Student::setGPA(double g)
{
	gpa = g;
}

void Student::setFacultyID(int f)
{
	facultyID = f;
}

int Student::setStudentID()
{
	int a = ((rand() % 2001+1001));
	return a;
}

std::string Student::getMajor()
{
	return major;
}

double Student::getGPA()
{
	return gpa;
}

int Student::getFacultyID()
{
	return facultyID;
}

void Student::printInfo()
{
	cout << endl << "Student ID: " << this->getID()
		 << endl << "Student Name: " << this->getName()
		 << endl << "Student Level: " << this->getLevel()
		 << endl << "Student Major: " << this->getMajor()
		 << endl << "Student GPA: " << this->getGPA()
		 << endl << "Student Advisor ID: " << this->getFacultyID()
		 << endl;
	
}

Faculty::Faculty()
{
	ID = 0;
	department = "";
	adviseeList = new DoublyLinkedList<int>();
}

Faculty::Faculty(std::string n, std::string l, std::string d)
{
	setName(n);
	setLevel(l);
	ID = setFacultyID();
	department = d;
	adviseeList = new DoublyLinkedList<int>();
}

Faculty::~Faculty()
{

}

void Faculty::setDepartment(std::string d)
{
	department = d;
}

int Faculty::setFacultyID()
{
	int a = ((rand() % 1001+1));
	return a;
}

std::string Faculty::getDepartment()
{
	return department;
}

void Faculty::printInfo()
{
	cout << endl << "Faculty ID: " << this->getID()
		 << endl << "Faculty Name: " << this->getName()
		 << endl << "Faculty Level: " << this->getLevel()
		 << endl << "Faculty Department: " << this->getDepartment()
		 << endl << "Faculty Advisee's ID: "; this->printAdviseeList();
	cout << endl;
}

void Faculty::addAdvisee(int id)
{
	adviseeList->insertFront(id);
}

int Faculty::getAdvisee(int id)
{
	return adviseeList->find(id);
}

int Faculty::dropAdvisee(int id)
{
	int pos = adviseeList->find(id);
	if(pos > -1) return adviseeList->deletePos(pos);
	else return NULL;
}

int Faculty::removeFrontAdvisee()
{
	return adviseeList->removeFront();
}

int Faculty::getFrontAdvisee()
{
	return adviseeList->getFront();
}

DoublyLinkedList<int>* Faculty::getAdviseeList()
{
	return adviseeList;
}

int Faculty::getAdviseeListSize()
{
	return adviseeList->getSize();
}

bool Faculty::adviseeListIsEmpty()
{
	return adviseeList->isEmpty();
}

void Faculty::printAdviseeList()
{
	adviseeList->printList();
}

