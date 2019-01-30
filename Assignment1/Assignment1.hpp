//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment1

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <locale> 
#include <time.h>

//Variable Declaration/Initialization
std::locale loc;
double sum;
double mean;
double variance;
double stdDeviation;
double a = 0,g = 0,t = 0,c = 0;
double aa = 0, ag = 0, ac = 0, at = 0;
double ga = 0, gg = 0, gc = 0, gt = 0;
double ca = 0, cg = 0, cc = 0, ct = 0;
double ta = 0, tg = 0, tc = 0, tt = 0;
int gaussianD = 0;

//Function Declaration/Initialization
std::string readFile(std::string filename);
void generateStatistics(std::string str);
void nucleotideProb(std::string str);
void bigramProb(std::string str);
void writeFile(int counter);
void setGauss();
void simulator();
void fileAppender(std::string str);
void clearVariables();