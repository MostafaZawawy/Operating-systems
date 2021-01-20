#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct Buffer
{
    int item;
    bool bit;
} Buffer;
void FIFO(int arr[],int*buffer,int size);
void LRU(int arr[],int*buffer,int size);
void OPTIMAL(int arr[],int*buffer,int size);
void CLOCK(int arr[],Buffer*clock_buffer,int size);
#endif // HEADER_H_INCLUDED
