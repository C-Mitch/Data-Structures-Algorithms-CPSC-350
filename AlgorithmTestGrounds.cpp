

//Bubble Sort
void bubbleSort(int myArray[])
{
	for(int i = 0; i<10; ++i)
	{
		int temp = 0;
		for(int j = 0; j<9; ++i)
		{
			if(myArray[j] > myArray[j+1])
			{
				temp = myArray[j+1];
				myArray[j+1] = myArray[i];
				myArray[j] = temp;
			}
		}
	}
}

//Selection Sort
void selectionSort(int arr[], int n)
{
	int i, j, minIndex, tmp;
	for(i = 0; i<n-1; ++i)
	{
		minIndex = i;
		for(j=i+1; j<n; ++j)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
			if(minIndex != i)
			{
				tmp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = tmp;
			}
		}
	}
}

//Insertion Sort
void insertionSort(double arr[])
{
	for(int j = 1; j < 10; ++j) //marker
	{
		double temp = arr[j]; //Store marked item
		int k = j; //Where to start shifting
		while(k > 0 && arr[k-1] >= temp) //While the thing to the left is larget, shift
		{
			arr[j] = arr[k-1];
			--k;
		}
		arr[k] = temp; //Put marked item in right slot
	}
}

//Merge Sort
void mergeSort(int[] a, int lo, int hi)
{
	if(lo<hi)
	{
		m = (lo+hi)/2;
		mergeSort(a, lo, m);
		mergeSort(a, m+1, hi);
		merge(a,lo,hi);
		
	}
	
}
	
void merge(int [] a, int lo, int hi)
{
	int i,j,k,m,n=hi-lo+1;
	int[] b = new int[n]
	
}
	