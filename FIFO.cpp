#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void FIFO(int arr[],int*buffer,int size)
{
    int j=0;
    int fault=0;
    int counter=0;
    int full=0;
    int print=0;
    int flag=0;

    cout <<"Replacement Policy = FIFO"<<"\n";
    cout <<"-------------------------------------"<<"\n";
    cout <<"Page   Content of Frames"<<"\n";
    cout <<"----   -----------------"<<"\n";
    while(arr[j]!=-1)
    {

        for(int i=0; i<size; i++)
            if(buffer[i]==arr[j])
            {
                flag=1;
                break;
            }

        if(flag==0)
        {
            if(full<size)
            {
                buffer[full++]=arr[j];

            }
            else
            { // simple pointer counter holding the index
              // of the oldest page in buffer
              // that will be swapped when a new page is requested
                if(counter<size)
                {
                    buffer[counter++]=arr[j];

                }
                else
                {
                    counter=0;
                    buffer[counter++]=arr[j];

                }
                cout<<"0"<<arr[j]<<" F   ";
                for(int i=0; i<size; i++)
                {
                    if(buffer[i]!=0)
                        cout<<"0"<<buffer[i]<<" ";

                }
                cout<<"\n";
                fault++;
                print=1;

            }
        }
        flag=0;
        if(print==0)
        {
            cout<<"0"<<arr[j]<<"     ";
            for(int i=0; i<size; i++)
            {
                if(buffer[i]!=0)
                    cout<<"0"<<buffer[i]<<" ";


            }
            cout<<"\n";
        }
        print=0;
        j++;

    }

    cout <<"-------------------------------------"<<"\n";
    cout <<"Number of page faults = "<<fault;
    cout <<"\n";

}
