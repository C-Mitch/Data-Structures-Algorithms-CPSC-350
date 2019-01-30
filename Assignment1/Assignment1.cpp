//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment1

#include "Assignment1.hpp"

using namespace std;



int main(int argc, char** argv)
{
	if(argc > 1)
	{
		//Variable declaration
		srand (time(NULL));
		int counter = 0;
		std::string sequence;
		char choice;
		
		while(true)
		{
			clearVariables();
			
			if(counter != 0) //For Subsequent Loops
			{
				std::string input;
				cout << endl <<"Please Enter Valid Name Of File To Run: " << endl;
				cin >> input;
				sequence = readFile(input);
				
			}
			else sequence = readFile(argv[1]); //For Initial Loop
			
			//Function Block
			generateStatistics(sequence);
			nucleotideProb(sequence);
			bigramProb(sequence);
			writeFile(counter);
			//setGauss();
			simulator();
			
			//Rerun Check
			cout << endl << "Enter New File and Rerun Program? 'y' or 'n': ";
			cin >> choice;
			if(tolower(choice) == 'n') break;
			
			counter++;
		}
	}
	else cout << "No Valid File Input" << endl << "Please Enter Valid File On Launch" << endl;
	
	return 0;
}



//Read Input File and Append Characters to String
std::string readFile(std::string filename)
{
	string holder;
	char c;
	ifstream in(filename);
	while(in.get(c))  //Iterate through file
	{
		if(c=='\n') holder+=(c);
		else if(c=='\r') continue; //Ignore carriage return (when applicable)
		else holder+=(tolower(c,loc)); //Append characters to string, convert to lower
	}
	holder+=('\n');
	in.close();
	
	return holder;
}

//Generate Sequence Sum, mean, variance, and standard deviation of the length of the DNA
void generateStatistics(std::string str)
{
	//Sum Generation
	double lineCount;
	for(unsigned int i=0; i<str.length(); ++i)
	{
		if(str[i] != '\n') sum++; //New Line Char indicates end of line; ignore when counting sequence total
		else lineCount++; //Extract original # of lines from string
	}
	cout << endl << "sum: " << sum << " lineCount: " << lineCount << endl;
	//Mean Generation
	mean = sum/lineCount;
	cout << "mean: " << mean << endl;
	//Variance Generation
	double temp, temp2;
	for(unsigned int i=0; i<str.length(); ++i)
	{
		
		if(str[i] == '\n') //New Line Char indicates end of line: 
		{
			//cout << "temp value: " << temp << endl;
			temp2 += ((temp-mean)*(temp-mean));
			temp = 0;
		}
		else temp++;  //Add up number of sequence members in a line
		
	}
	variance = temp2/(lineCount-1);
	cout << "variance: " << variance << endl;
	//Standard Deviation Generation
	stdDeviation = sqrt(variance);
	cout << "Standard Deviation: " << stdDeviation << endl;
	
}

//Set Nucleotide Probability
void nucleotideProb(std::string str)
{
	for(unsigned int i=0; i<str.length(); ++i)  //Iterate through entire sequence, ignore New Line Char, add to respective counter
	{
		if(str[i] == 'a') a++;
		else if(str[i] == 'g') g++;
		else if(str[i] == 't') t++;
		else if(str[i] == 'c') c++;
		
	}
	 
	//Divide counter by sum for relative probability
	a = a/sum;
	g = g/sum;
	t = t/sum;
	c = c/sum;
}

//Set Bigram Probability
void bigramProb(std::string str)
{
	std::string bi;
	for(unsigned int i=0; i<str.length(); ++i)//Iterate through entire sequence, add to respective counter
	{
		if(str[i] == '\n') continue; //New Line Char is ignored when counting Bigrams
		else bi = str[i];
		if(str[i+1] == '\n') continue; //Similarly, New Line Char of end is ignored
		else bi += str[i+1];
		
		if(bi == "aa") aa++;
		else if(bi == "ag") ag++;
		else if(bi == "ac") ac++;
		else if(bi == "at") at++;
		else if(bi == "ga") ga++;
		else if(bi == "gg") gg++;
		else if(bi == "gc") gc++;
		else if(bi == "gt") gt++;
		else if(bi == "ca") ca++;
		else if(bi == "cg") cg++;
		else if(bi == "cc") cc++;
		else if(bi == "ct") ct++;
		else if(bi == "ta") ta++;
		else if(bi == "tg") tg++;
		else if(bi == "tc") tc++;
		else if(bi == "tt") tt++;
		
		bi =  "";
	}
	
	//Divide counter by sum for relative probability
	aa = aa/sum;
	ag = ag/sum;
	ac = ac/sum;
	at = at/sum;
	ga = ga/sum;
	gg = gg/sum;
	gc = gc/sum;
	gt = gt/sum;
	ca = ca/sum;
	cg = cg/sum;
	cc = cc/sum;
	ct = ct/sum;
	ta = ta/sum;
	tg = tg/sum;
	tc = tc/sum;
	tt = tt/sum;
}

//File Writer
void writeFile(int counter)
{
	if(counter == 0)
	{
		ofstream out("ChaseMitchell.txt", std::ofstream::trunc); //Initial Opening of file, Truncate to clear content when applicable
		if(out.is_open()) //Write Initial Statistics
		{
			cout << "FILE WRITER OPEN" << endl;
			
			out << "Chase Mitchell" << endl << "#002274657" << endl << "Mitch213@mail.chapman.edu" << endl << "CPSC-350-01" << endl << "Assignment1" << endl;
			out << endl << "DNA INPUT STATISTICS" << endl;
			out << "Sequence Sum: " << sum << endl;
			out << "Sequence Mean: " << mean << endl;
			out << "Sequence Variance: " << variance << endl;
			out << "Sequence Standard Deviation: " << stdDeviation << endl;
			out << endl << "NUCLEOTIDE PROBABILITY" << endl;
			out << "A: " << a << endl;
			out << "G: " << g << endl;
			out << "T: " << t << endl;
			out << "C: " << c << endl;
			out << endl << "BIGRAM PROBABILITY" << endl;
			out << "AA: " << aa << "\nAG: " << ag << "\nAC: " << ac << "\nAT: " << at << endl;
			out << "GA: " << ga << "\nGG: " << gg << "\nGC: " << gc << "\nGT: " << gt << endl;
			out << "CA: " << ca << "\nCG: " << cg << "\nCC: " << cc << "\nCT: " << ct << endl;
			out << "TA: " << ta << "\nTG: " << tg << "\nTC: " << tc << "\nTT: " << tt << endl << endl;

		}	
		out.close();
		cout << "FILE WRITER CLOSED" << endl;
	}
	else
	{		
		ofstream out("ChaseMitchell.txt", std::ofstream::app); //Subsequent Opening of file, append to file
		if(out.is_open()) //Write Initial Statistics
		{
			cout << "FILE APPENDER OPEN" << endl;
			
			out << endl <<"Chase Mitchell" << endl << "#002274657" << endl << "Mitch213@mail.chapman.edu" << endl << "CPSC-350-01" << endl << "Assignment1" << endl;
			out << endl << "DNA INPUT STATISTICS" << endl;
			out << "Sequence Sum: " << sum << endl;
			out << "Sequence Mean: " << mean << endl;
			out << "Sequence Variance: " << variance << endl;
			out << "Sequence Standard Deviation: " << stdDeviation << endl;
			out << endl << "NUCLEOTIDE PROBABILITY" << endl;
			out << "A: " << a << endl;
			out << "G: " << g << endl;
			out << "T: " << t << endl;
			out << "C: " << c << endl;
			out << endl << "BIGRAM PROBABILITY" << endl;
			out << "AA: " << aa << "\nAG: " << ag << "\nAC: " << ac << "\nAT: " << at << endl;
			out << "GA: " << ga << "\nGG: " << gg << "\nGC: " << gc << "\nGT: " << gt << endl;
			out << "CA: " << ca << "\nCG: " << cg << "\nCC: " << cc << "\nCT: " << ct << endl;
			out << "TA: " << ta << "\nTG: " << tg << "\nTC: " << tc << "\nTT: " << tt << endl << endl;

		}	
		out.close();
		cout << "FILE APPENDER CLOSED" << endl;
	}
}

//Calculate Gaussian Distribution
void setGauss()
{
	double a,b,c;
	a = ((rand() % 100+1));
	a = a/100.00; //Generate Random double between 0-0.99, incrementing by 0.01
	b = ((rand() % 100+1));
	b = b/100.00;
	c = (sqrt((-2*log(a)))*cos((2*M_PI*b))); //Box-Muller Transformation

	gaussianD = rint((stdDeviation*c)+mean);  //Round Gaussian Distribution and convert to int
}

//Simulation x1000
void simulator()
{
	std::string holder;
	int x = sum;
	int nucA = a*sum; //Restore probabilities to Int form (number of Nucleotide)
	int nucG = g*sum+nucA; //Set upper bound of probability range
	int nucC = c*sum+nucG;
	for (int j = 0; j <= 1000; ++j)
	{
		setGauss();
		for(int i = 0; i < gaussianD; ++i) //Gaussian Distribution sets length of string
		{
			int r = rand() % x+1; //Generate a random number, r, with range 1-sum

			if(r <= nucA) holder+='a';  //Number of each Nucleotide correspond to probability of appearance when random range is sum of Nucleotides
			else if( r > nucA && r <= nucG) holder+='g'; //Number range above A but below C is probability of G
			else if( r > nucG && r <= nucC) holder+='c';
			else holder+='t';

		}
		fileAppender(holder);
		holder = "";		
	}
	
}

//File Appender
void fileAppender(std::string str)
{
	ofstream out("ChaseMitchell.txt", std::ofstream::app); //Open file to append
	if(out.is_open())
	{
		out << str << endl;
	}
	out.close();
	
}

//Clear/Reset Variables;
void clearVariables()
{
	cout << endl << "Variables Cleared" << endl;
	sum = 0;
	mean = 0;
	variance = 0;
	stdDeviation = 0;
	a = 0;g = 0;t = 0;c = 0;
	aa = 0; ag = 0; ac = 0; at = 0;
	ga = 0; gg = 0; gc = 0; gt = 0;
	ca = 0; cg = 0; cc = 0; ct = 0;
	ta = 0; tg = 0; tc = 0; tt = 0;
	gaussianD = 0;
}
