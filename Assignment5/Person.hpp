//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5


#include <string>
#include <time.h>
#include "DoublyLinkedList.hpp"


using namespace std;

#ifndef Person_HPP
#define Person_HPP
//General Person Object
class Person
{
	public:
		Person();
		Person(std::string n, std::string l);
		~Person();
		
		void setName(std::string n);
		void setLevel(std::string l);
		std::string getName();
		std::string getLevel();
		int getID();
		
		//Operator Overloaders:
		bool operator==(const Person& b);
		bool operator<(const Person& b);		
		bool operator>(const Person& b);		
		bool operator!=(const Person& b);		
		bool operator!=(const long int b);
		
	protected:
		int ID;
		std::string name;
		std::string level;
		
};
//General Student Object; Inherits Name, ID, and Level from Person
class Student : public Person
{
	public:
		Student();
		Student(std::string n, std::string l, std::string m, double g, int f);
		~Student();
		
		void setMajor(std::string m);
		void setGPA(double g);
		void setFacultyID(int f);
		int setStudentID();
		
		std::string getMajor();
		double getGPA();
		int getFacultyID();
		
		void printInfo();
	
	private:
		std::string major;
		double gpa;
		int facultyID;
	
};
//General Faculty Object; Inherits Name, ID, and Level from Person
class Faculty : public Person
{
	public:
		Faculty();
		Faculty(std::string n, std::string l, std::string d);
		~Faculty();
		
		void setDepartment(std::string d);
		int setFacultyID();
		
		std::string getDepartment();
		
		void printInfo();
	
		void addAdvisee(int id);
		int getAdvisee(int id);
		int dropAdvisee(int id);
		int removeFrontAdvisee();
		int getFrontAdvisee();
		DoublyLinkedList<int>* getAdviseeList();
		int getAdviseeListSize();
		bool adviseeListIsEmpty();
		void printAdviseeList();
		
		
	private:
		std::string department;
		DoublyLinkedList<int>* adviseeList;

	
};


#endif