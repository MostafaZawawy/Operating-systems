#include <iostream>
#include<pthread.h>
#include<stdlib.h>
#include <fstream>
#include<unistd.h>
using namespace std;
int* arr = NULL;
int n = 0;
typedef struct args
{
    int start;
    int end;
} args;

// typical megre code merges the right half
//which is from l to m and second half which is from m+r to r
void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;


	int L[n1], R[n2];


	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]
	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void* mergeSort(void* input){


    args* arg;
    arg=(args *)input;
    //l: left inedex , r: right index
    int l = arg->start;
	int r = arg->end;

	if(l<r){
	int m = (l+r-1)/2;
	args *indexLeft=(args*)malloc(sizeof(args));
	args *indexRight=(args*)malloc(sizeof(args));
	//the starting and last index of the left subarray which the left thread would be working on
	indexLeft->start=l;
	indexLeft->end=m;
	//the starting and last index of the right subarray which the right thread would be working on
	indexRight->start = m+1;
	indexRight->end = r;
	pthread_t threadLeft;
	pthread_t threadRight;
	//creating a thread of each half, right and lift recusivly
	pthread_create(&threadLeft, NULL, (void *(*) (void *))mergeSort, (void*)(indexLeft));
	pthread_create(&threadRight, NULL, (void *(*) (void *))mergeSort, (void*)(indexRight));
	pthread_join(threadLeft, NULL);
	pthread_join(threadRight, NULL);
	merge(arr,l,m,r);
	}
	else{//do nothing only 1 element is in subarray
	}
return 0;
}




int main()
{
    //read from file
      printf("Please enter filename:");
    string x;
    cin>>x;
    ifstream f(x);
	f >>n;

	arr = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n;i++)
		f >>  arr[i];
     //the startig and ending index of the whole arrary
    args *index=(args*)malloc(sizeof(args));
    index->start=0;
    index->end=n-1;
	//print unstorted arrary
	cout << "Unsorted Arary:  \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	pthread_t thread;

	//creating the first thread to merge sort
	pthread_create(&thread, NULL,(void *(*) (void *)) mergeSort, (void*)(index));
	pthread_join(thread, NULL);
   //print sorted array
	cout << "\nSorted Array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout<<"\n";
	return 0;
}




