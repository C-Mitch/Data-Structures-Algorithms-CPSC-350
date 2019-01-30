//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment6

#include "Assignment6.hpp"

using namespace std;

FileIn::FileIn() //Standard - Unused
{
	path = "";
}

FileIn::FileIn(std::string p) //Overloaded - Used
{
	path = p;
	size = 0;	
	readInput();
	
}

FileIn::~FileIn()
{

}

void FileIn::readInput() //Transfer file input to holder array
{
	int count, k = 0;
	double t;
	ifstream inn(path);
	while(inn >> t)
	{
		if(count == 0)
		{
			size = t;
			holder = new double[size];
			//cout << "Established Holder" << endl;
		}
		else holder[k++] = t;
		count++;
	}
	
	//for(int x = 0; x < size; ++x) cout << "Holder Contains: " << holder[x] << " at: " << x << endl;
	inn.close();
}

double* FileIn::getArray()
{
	return holder;
}

int FileIn::getSize()
{
	return size;
}

Simulation::Simulation()
{
	array = new double[10];
	size = 10;
}

Simulation::Simulation(double* d, int s)
{
	array = d;
	size = s;
	
}

Simulation::~Simulation()
{
	delete array;
}

//Centeral Control For Simulation
void Simulation::Run()
{
	auto start1 = chrono::steady_clock::now();
	
	//cout << endl <<"Quick Sort: " << endl << "Set Prior: " << endl;
	//for(int x = 0; x < size; ++x) cout << "Array Contains: " << array[x] << " at: " << x << endl;
	
	quickSort(array);

	auto end1 = chrono::steady_clock::now();
	cout << "Quick Sort Time Ellapsed: " << chrono::duration_cast<chrono::microseconds>(end1-start1).count() << " microseconds" << endl;
	
	//cout << endl << "Insertion Sort: " << endl << "Set Prior: " << endl;
	//for(int x = 0; x < size; ++x) cout << "Array Contains: " << array[x] << " at: " << x << endl;
	
	auto start2 = chrono::steady_clock::now();
	
	insertionSort(array);

	auto end2 = chrono::steady_clock::now();
	cout << "Insertion Sort Time Ellapsed: " << chrono::duration_cast<chrono::microseconds>(end2-start2).count() << " microseconds" << endl;
	
	//cout << endl << "Bubble Sort: " << endl << "Set Prior: " << endl;
	//for(int x = 0; x < size; ++x) cout << "Arr Contains: " << array[x] << " at: " << x << endl;
	
	auto start3 = chrono::steady_clock::now();
	
	bubbleSort(array);

	auto end3 = chrono::steady_clock::now();
	cout << "Bubble Sort Time Ellapsed: " << chrono::duration_cast<chrono::microseconds>(end3-start3).count() << " microseconds" << endl;
	
	//cout << endl << "Pancake Sort: " << endl << "Set Prior: " << endl;
	//for(int x = 0; x < size; ++x) cout << "Arr Contains: " << array[x] << " at: " << x << endl;
	
	auto start4 = chrono::steady_clock::now();
	
	pancakeSort(array);
	
	auto end4 = chrono::steady_clock::now();
	cout << "Pancake Sort Time Ellapsed: " << chrono::duration_cast<chrono::microseconds>(end4-start4).count() << " microseconds" << endl;

}

//Quick Sort Primer
void Simulation::quickSort(double arrPtr[])
{
	//Make Deep Copy of Array
	double* arr = new double[size];
	for(int t = 0; t < size; ++t) { arr[t] = arrPtr[t]; }
	
	quickSort(arr, 0, size-1);

	//cout << "Set After: " << endl;
	//for(int x = 0; x < size; ++x) cout << "Array Contains: " << arr[x] << " at: " << x << endl;
}

//Quick Sort
void Simulation::quickSort(double arr[], double lo, double hi)
{
    if (lo < hi)
    {

        double part = partition(arr, lo, hi);

        quickSort(arr, lo, part-1);
        quickSort(arr, part+1, hi);
    }
}

//General Swap Utility
void Simulation::swap(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

//Partition function to set last element as pivot orders it; redistribute other values of array either less than or greater than pivot
double Simulation::partition(double arr[], int lo, int hi)
{
	double pivot = arr[hi];
	int i = (lo-1);
	
	for (int j = lo; j <= hi-1; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[hi]);
	return (i+1);
   
}

//Insertion Sort
void Simulation::insertionSort(double arrPtr[])
{
	//Make Deep Copy of Array
	double* arr = new double[size];
	for(int t = 0; t < size; ++t) { arr[t] = arrPtr[t]; }
	
	for(int j = 1; j < size; ++j) //marker
	{
		double temp = arr[j]; //Store marked item
		int k = j-1; //Where to start shifting
		while(k >= 0 && arr[k] > temp) //While the thing to the left is larget, shift
		{
			arr[k+1] = arr[k];
			--k;
		}
		arr[k+1] = temp; //Put marked item in right slot
	}
	
	//cout << "Set After: " << endl;
	//for(int x = 0; x < size; ++x) cout << "Array Contains: " << arr[x] << " at: " << x << endl;
}

//Bubble Sort
void Simulation::bubbleSort(double arrPtr[])
{
	//Make Deep Copy of Array
	double* arr = new double[size];
	for(int t = 0; t < size; ++t) { arr[t] = arrPtr[t]; }
	
	for(int i = 0; i<size; ++i)
	{
		double temp = 0;
		for(int j = 0; j<size-1; ++j)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	//cout << "Set After: " << endl;
	//for(int x = 0; x < size; ++x) cout << "Arr Contains: " << arr[x] << " at: " << x << endl;
}

//Flip Function; Reverse Array[0-i]
void Simulation::flip(double arr[], int i)
{
    double temp;
	int start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        ++start;
        --i;
    }
}

//Simple Indexer; Returns Index of Max Element in Array
int Simulation::findMax(double arr[], int n)
{
	int mi, i;
	for (mi = 0, i = 0; i < n; ++i)
		if (arr[i] > arr[mi])
				mi = i;
	return mi;
}

//Pancake Sort Primer
void Simulation::pancakeSort(double arrPtr[])
{
	//Make Deep Copy of Array
	double* arr = new double[size];
	for(int t = 0; t < size; ++t) { arr[t] = arrPtr[t]; }
	
	pancakeSort(arr, size);

	//cout << "Set After: " << endl;
	//for(int x = 0; x < size; ++x) cout << "Array Contains: " << arr[x] << " at: " << x << endl;
	
}

//Pancake Sort
void Simulation::pancakeSort(double *arr, int n)
{
    for (int curr_size = n; curr_size > 1; --curr_size)
    {
        int mi = findMax(arr, curr_size);
		
        if (mi != curr_size-1)
        {
            flip(arr, mi);
            flip(arr, curr_size-1);
        }
    }
	
}




