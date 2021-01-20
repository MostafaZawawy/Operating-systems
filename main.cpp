#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;
//global variables
Buffer*clock_buffer;
int size;
int*buffer;

int main()
{
    string algorthim;
    int arr[100];
    int i=0;

    cin>> size;
    cin>> algorthim;
    int x;

    clock_buffer=(Buffer*)malloc(sizeof(Buffer)*size);
    for(int i=0; i<size; i++)
    {
        clock_buffer[i].bit=0;
        clock_buffer[i].item=0;
    }

    buffer=(int*)malloc(sizeof(int)*size);
    for(int i=0; i<size; i++)
        buffer[i]=0;


    while(cin >> arr[i]&& arr[i]!=-1)
    {
        i++;
    }

    if(algorthim.compare("FIFO")==0)
         FIFO(arr,buffer,size);
    else if(algorthim.compare("LRU")==0)
        LRU(arr,buffer,size);
    else if(algorthim.compare("OPTIMAL")==0)
        OPTIMAL(arr,buffer,size);
    else if(algorthim.compare("CLOCK")==0)
        CLOCK(arr,clock_buffer,size);


    return 0;
}
