//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5

#include "Assignment5.hpp"

using namespace std;


Simulation::Simulation()
{
	if(in.validatePath("studentTable"))
	{
		//deserializeFile(1,"studentTable");
		 masterStudent = new BST<Student>();
	}
	else masterStudent = new BST<Student>();
	
	if(in.validatePath("facultyTable"))
	{
		//deserializeFile(2,"facultyTable");
		masterFaculty = new BST<Faculty>();
	}
	else masterFaculty = new BST<Faculty>();
	
	exitControll = false;
}

Simulation::~Simulation()
{
	delete masterStudent;
	delete masterFaculty;
	
}

void Simulation::deserializeFile(int c, std::string file)
{
	cout << "In deserializeFile: " << endl;
	if(c == 1)
	{
		masterStudent = new BST<Student>();
		//ifstream inn(path);

	}
	else
	{
		masterFaculty = new BST<Faculty>();
	}
	
	
}

void Simulation::serializeFile()
{
	ofstream out("studentTable", std::ofstream::trunc);
	if(out.is_open()) 
	{
		cout << "FILE WRITER OPEN" << endl;
		
		if(!masterStudent->isEmpty())
		{
			int max = masterStudent->getMax()->data.getID();
			for(int i = 1001; i <= max; ++i)
			{
				if(masterStudent->contains(i))
				{
					out << "*" << endl;
					out << masterStudent->find(i)->getID() << endl;
					out << masterStudent->find(i)->getName() << endl;
					out << masterStudent->find(i)->getLevel() << endl;
					out << masterStudent->find(i)->getMajor() << endl;
					out << masterStudent->find(i)->getGPA() << endl;
					out << masterStudent->find(i)->getFacultyID() << endl;
					out << "+" << endl;
					
				}
			}
		}
		out.close();
	}
	
	ofstream out2("facultyTable", std::ofstream::trunc);
	if(out2.is_open()) 
	{
		cout << "FILE WRITER OPEN" << endl;
		
		if(!masterFaculty->isEmpty())
		{

			int max = masterFaculty->getMax()->data.getID();
			for(int i = 1; i <= max; ++i)
			{
				if(masterFaculty->contains(i))
				{
					out2 << '*' << endl;
					out2 << masterFaculty->find(i)->getID() << endl;
					out2 << masterFaculty->find(i)->getName() << endl;
					out2 << masterFaculty->find(i)->getLevel() << endl;
					out2 << masterFaculty->find(i)->getDepartment() << endl;
					out2 << '~' << endl;
					
					if(!masterFaculty->find(i)->adviseeListIsEmpty())
					{
						for(int l = 1000; l <= 2999; ++i)
						{
							if(masterFaculty->find(i)->getAdviseeList()->contains(l))
							{
								out2 << masterStudent->find(l)->getID() << endl;
							}
						}
					}
					else out2 << 0 << endl;
				}
			}
		}
		out2.close();
	}
	
	
}

BST<Student>* Simulation::getStudentTree()
{
	return masterStudent;
}

BST<Faculty>* Simulation::getFacultyTree()
{
	return masterFaculty;
}

void Simulation::run()
{
	while(!exitControll)
	{
		menu();
	}
	
	serializeFile();
	
}

void Simulation::menu()
{
	int s = 0;
	

	cout << endl << "			Menu" << endl
		 << "1. Print all students and their information (sorted by ascending id #)" << endl
		 << "2. Print all faculty and their information (sorted by ascending id #)" << endl
		 << "3. Display student information given student id" << endl
		 << "4. Display faculty information given faculty id" << endl
		 << "5. Print the name and info of an advisor given student id" << endl
		 << "6. Print the name and info of all of a Faculty's advisees given faculty id" << endl
		 << "7. Add a new student" << endl
		 << "8. Delete a student from database" << endl
		 << "9. Add a new faculty member" << endl
		 << "10. Delete a faculty member from database" << endl
		 << "11. Change a student’s advisor given the student id and the new faculty ID." << endl
		 << "12. Remove an advisee from a faculty member given the ID" << endl
		 << "13. Rollback" << endl
		 << "14. Exit" << endl
		 << endl << "Please enter a number: ";

	while(true)
	{
		s = in.getIntInput();
		if(s > 0 && s < 15) break;
		else cout << "Input Valid Command Number" << endl;
	}

	switch(s)
	{
		case 1:
			printStudents();
			break;
		case 2:
			printFaculty();
			break;
		case 3:
			displayStudent();
			break;
		case 4:
			displayFaculty();
			break;
		case 5:
			displayAdvisor();
			break;
		case 6:
			displayAdvisees();
			break;
		case 7:
			insertStudent();
			break;
		case 8:
			deleteNode(1);
			break;
		case 9:
			insertFaculty();
			break;
		case 10:
			deleteNode(2);
			break;
		case 11:
			changeAdvisor();
			break;
		case 12:
			removeAdvisee();
			break;
		case 13:
			rollback();
			break;
		case 14:
			exitControll = true;
			break;	
	}
	
}

//Option 1
void Simulation::printStudents()
{
	if(!masterStudent->isEmpty())
	{
		cout << endl << "Student Info By Ascending Order: " << endl;
		int max = masterStudent->getMax()->data.getID();
		for(int i = 1001; i <= max; ++i) //Loop to find students
		{
			if(masterStudent->contains(i)) masterStudent->find(i)->printInfo(); 
		}
	}
	else cout << "No Students In Database" << endl;
	
}
//Option 2
void Simulation::printFaculty()
{
	if(!masterFaculty->isEmpty())
	{
		cout << endl << "Faculty Info By Ascending Order: " << endl;
		int max = masterFaculty->getMax()->data.getID();
		for(int i = 1; i <= max; ++i) //Loop to find faculty
		{
			if(masterFaculty->contains(i)) masterFaculty->find(i)->printInfo(); 
		}
	}
	else cout << "No Faculty In Database" << endl;
}
//Option 3
void Simulation::displayStudent()
{
	int qID = -1;
	
	while(qID != 0)
	{
		if(masterStudent->contains(qID))
		{
			masterStudent->find(qID)->printInfo();
			break;	
		}
		else
		{
			cout << endl << "Enter A Valid Student ID To Display" << endl << "Enter 0 To Return Menu" << endl;
			qID = in.getIntInput();
		}
	}
	
}
//Option 4
void Simulation::displayFaculty()
{
	int qID = -1;
	
	while(qID != 0)
	{
		if(masterFaculty->contains(qID))
		{
			masterFaculty->find(qID)->printInfo();
			break;	
		}
		else
		{
			cout << endl << "Enter A Valid Faculty ID To Display" << endl << "Enter 0 To Return Menu" << endl;
			qID = in.getIntInput();
		}
	}
	
}
//Option 5
void Simulation::displayAdvisor()
{
	int qID = -1;
	
	while(qID != 0)
	{
		if(masterStudent->contains(qID))
		{
			qID = masterStudent->find(qID)->getFacultyID();
			if(masterFaculty->contains(qID)) masterFaculty->find(qID)->printInfo();
			else cout << "Student Has No Advisor" << endl;
			break;	
		}
		else
		{
			cout << endl << "Enter A Valid Student ID To Display Advisor" << endl << "Enter 0 To Return Menu" << endl;
			qID = in.getIntInput();
		}
	}
}
//Option 6
void Simulation::displayAdvisees()
{
	int qID = -1;
	
	while(qID != 0)
	{
		if(masterFaculty->contains(qID))
		{
			
			if(masterFaculty->find(qID)->adviseeListIsEmpty())cout << "Advisor Has No Advisees" << endl;
			else
			{
				cout << "Advisee Information: " << endl;
				
				for(int i = 1000; i <= masterStudent->getMax()->data.getID(); ++i)
				{
					if(masterFaculty->find(qID)->getAdviseeList()->contains(i)) masterStudent->find(i)->printInfo();
				}
			}
			break;	
		}
		else
		{
			cout << endl << "Enter A Valid Faculty ID To Display Advisees" << endl << "Enter 0 To Return Menu" << endl;
			qID = in.getIntInput();
		}
	}
}
//Option 7
void Simulation::insertStudent()
{
	cout << endl << "Add New Student: " << endl;
	
	string name;
	string level;
	string major;
	double gpa;
	int fID = 0;
	
	cout << "Enter Student Name: " << endl;
	name = in.getStringInput();
	cout << "Enter Student Level: " << endl;
	level = in.getStringInput();
	cout << "Enter Student Major: " << endl;
	major = in.getStringInput();
	cout << "Enter Student GPA: " << endl;
	gpa = in.getDoubleInput();
	
	Student stud(name, level, major, gpa, fID);
	
	while(masterStudent->contains(stud.getID())) //In case of random ID assignemnt collision with existing
	{
		stud.setStudentID();
	}

	if(masterFaculty->isEmpty()) //In case no existing faculty; assigned ID 0 for nonexistant
	{
		masterStudent->insert(stud, stud.getID());
		cout << endl << "New Student Added: " << endl << "New Student Info: " << endl;
		stud.printInfo();
	}
	else //Faculty exists
	{
		bool p = false;
		int qID = stud.getID()%1000; //Assigned faculty determined through queried student ID mod [1000]
		//cout << "qID : " << qID << endl;
		for(qID; qID < 1001; ++qID) //Find closest faculty to modded student ID from above
		{
			if(masterFaculty->contains(qID)) 
			{
				stud.setFacultyID(masterFaculty->find(qID)->getID());
				masterStudent->insert(stud, stud.getID());
				masterFaculty->find(qID)->addAdvisee(stud.getID());
				
				cout << endl <<"New Student Added: " << endl << "New Student Info: " << endl;
				stud.printInfo();
				
				p = true;
				break;
			}

		}
		
		qID = stud.getID()%1000;
		if(p == false)
		{
			for(qID; qID > 0; --qID) //Find closest faculty to modded student ID from below
			{
				if(masterFaculty->contains(qID))
				{
					stud.setFacultyID(masterFaculty->find(qID)->getID());
					masterStudent->insert(stud, stud.getID());
					masterFaculty->find(qID)->addAdvisee(stud.getID());
					
					cout << endl << "New Student Added: " << endl << "New Student Info: " << endl;
					stud.printInfo();
					break;
				}
			}
		}
	}
	
	
	
}
//Option 9
void Simulation::insertFaculty()
{
	cout << endl << "Add New Faculty: " << endl;
	
	string name;
	string level;
	string department;

	
	cout << "Enter Faculty Name: " << endl;
	name = in.getStringInput();
	cout << "Enter Faculty Level: " << endl;
	level = in.getStringInput();
	cout << "Enter Faculty Department: " << endl;
	department = in.getStringInput();

	
	Faculty facu(name, level, department);
	
	while(masterFaculty->contains(facu.getID())) //In case of random ID assignemnt collision with existing
	{
		facu.setFacultyID();
	}
	
	if(masterFaculty->isEmpty()) //If faculty tree is empty; new = first
	{
		if(!masterStudent->isEmpty()) //If students already exist
		{
			int max = masterStudent->getMax()->data.getID();
			for(int i = 1001; i <= max; ++i) //Assign existing students to new (first) faculty
			{
				if(masterStudent->contains(i))
				{
					masterStudent->find(i)->setFacultyID(facu.getID());
					facu.addAdvisee(i);
				}
			}
		}
		masterFaculty->insert(facu, facu.getID());
	}
	else masterFaculty->insert(facu, facu.getID());
	
	

}
//Option 8/10
void Simulation::deleteNode(int c)
{
	
	//Student
	if(c == 1)
	{
		cout << endl << "Delete Student: " << endl;
		
		cout << "Enter Student ID To Delete: " << endl;
		int qID = in.getIntInput();
		
		if(masterStudent->contains(qID))
		{
			cout << "Student To Delete: " << endl;
			masterStudent->find(qID)->printInfo();
			
			if(masterFaculty->contains(masterStudent->find(qID)->getFacultyID()))
			{
				//cout << endl << "Has Faculty: " << endl;
				//cout << masterFaculty->find(masterStudent->find(qID)->getFacultyID())->getID();
				masterFaculty->find(masterStudent->find(qID)->getFacultyID())->dropAdvisee(qID);
			}
			masterStudent->deleteNode(qID);
			
			cout << "Student Deleted" << endl;
		}
		else cout << "Student Not In Database" << endl;
		
	}
	//Faculty
	else
	{
		cout << endl << "Delete Faculty: " << endl;
		
		cout << "Enter Faculty ID To Delete: " << endl;
		int qID = in.getIntInput();
		
		if(masterFaculty->contains(qID)) //Valid Faculty ID
		{
			if(!masterFaculty->find(qID)->adviseeListIsEmpty()) //If Faculty Has Advisees
			{
				int temp;
				int cID = qID+1;
				bool p = false;
				for(cID; cID < 1001; ++cID) //Check If Any Replacement Faculty Availible (Faculty ID Greater Then Target)
				{
					if(masterFaculty->contains(cID)) //Found Replacement Faculty
					{
						//cout << "Found UPPER Trannsfer Faculty" << endl;
						while(!masterFaculty->find(qID)->adviseeListIsEmpty()) //Transfer Advisees and Enforce Referential Integrity
						{
							temp = masterFaculty->find(qID)->removeFrontAdvisee();
							//cout << "Temp: " << temp << endl;
							masterFaculty->find(cID)->addAdvisee(temp);	
							masterStudent->find(temp)->setFacultyID(cID);
						}
						
						masterFaculty->deleteNode(qID);
						cout << "Faculty Deleted" << endl;
						
						p = true;
						break;
					}
				}
				
				cID = qID-1;
				if(p == false) 
				{
					for(cID; cID > 0; --cID) //Check If Any Replacement Faculty Availible (Faculty ID Less Then Target)
					{
						if(masterFaculty->contains(cID)) //Found Replacement Faculty
						{
							//cout << "Found LOWER Trannsfer Faculty" << endl;
							while(!masterFaculty->find(qID)->adviseeListIsEmpty()) //Transfer Advisees and Enforce Referential Integrity
							{
								temp = masterFaculty->find(qID)->removeFrontAdvisee();
								//cout << "Temp: " << temp << endl;
								masterFaculty->find(cID)->addAdvisee(temp);	
								masterStudent->find(temp)->setFacultyID(cID);
							}
							
							masterFaculty->deleteNode(qID);
							cout << "Faculty Deleted" << endl;
							
							p = true;
							break;
						}
					}
				}
				
				if(p == false) //No Replacement Faculty Availible;
				{
					//cout << "Found NO Trannsfer Faculty" << endl;
					while(!masterFaculty->find(qID)->adviseeListIsEmpty()) //0 out Advisee's Faculty ID
					{
						int temp = masterFaculty->find(qID)->removeFrontAdvisee();
						//cout << "Temp: " << temp << endl;
						masterStudent->find(temp)->setFacultyID(0);
					}
					masterFaculty->deleteNode(qID);
					
					cout << "Faculty Deleted" << endl;
				}
				
			}
			else
			{
				masterFaculty->deleteNode(qID);
				cout << "Faculty Deleted" << endl;
			}
			
		}
		else cout << "Faculty Not In Database" << endl;
	}
	
	
}
//Option 11
void Simulation::changeAdvisor()
{
	cout << endl << "Change Student Advisor: " << endl;
	
	cout << "Enter Student ID To Change: " << endl;
	int qID = in.getIntInput();
	cout << "Enter Faculty ID To Add: " << endl;
	int cID = in.getIntInput();
	
	if(!masterFaculty->isEmpty()) //Exists Faculty
	{
		if(masterStudent->contains(qID)) //Exists student ID
		{
			if(masterFaculty->contains(cID)) //Exists Faculty ID
			{
				if(!masterFaculty->find(cID)->getAdviseeList()->contains(qID)) //Faculty is different from Student Advisor
				{
					masterFaculty->find(cID)->addAdvisee(qID);
					if(masterStudent->find(qID)->getFacultyID() != 0) //Transfer and referential integrity
					{
						int temp = masterFaculty->find(masterStudent->find(qID)->getFacultyID())->removeFrontAdvisee();
						while(qID != temp)
						{
							masterFaculty->find(masterStudent->find(qID)->getFacultyID())->getAdviseeList()->insertBack(temp);
							temp = masterFaculty->find(masterStudent->find(qID)->getFacultyID())->removeFrontAdvisee();
						}
					}
					//masterFaculty->find(masterStudent->find(qID)->getFacultyID())->dropAdvisee(qID);
					masterStudent->find(qID)->setFacultyID(cID);
				}
				else cout << "Faculty Is Already Student's Advisor" << endl;
			}
			else cout << "Faculty Not In Database" << endl;
		}
		else cout << "Student Not In Database" << endl;
	}
	else cout << "No Faculty In Database" << endl;
	
}
//Option 12
void Simulation::removeAdvisee()
{
	cout << endl << "Remove Advisee From Faculty: " << endl;
	
	cout << "Enter Student ID To Remove: " << endl;
	int qID = in.getIntInput();
	
	if(!masterFaculty->isEmpty()) //Faculty exists
	{
		int max = masterFaculty->getMax()->data.getID();
		for(int i = 1; i <= max; ++i) //Iterate and remove advisee ID
		{
			if(masterFaculty->contains(i))
			{
				if(masterFaculty->find(i)->getAdviseeList()->contains(qID))
				{
					masterFaculty->find(i)->dropAdvisee(qID);
					masterStudent->find(qID)->setFacultyID(0);
				}
			}
		}
	}
	else cout << "No Faculty In Database" << endl;
	
}
//Option 13
void Simulation::rollback() //NOT FINISHED
{
	cout << endl << "Yea, no.  Enjoy some tree traversing instead." << endl;
	
	cout << endl << "Master Student In Order Traversal: " << endl;
	masterStudent->printTree();
	cout << endl << "Master Faculty In Order Traversal: " << endl;
	masterFaculty->printTree();
}

