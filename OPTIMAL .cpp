#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void  OPTIMAL(int arr[],int*buffer,int size)
{

    int j=0;
    int fault=0;
    int flag=0;
    int full=0;
    int print=0;
    int arrIndex;
    int index;
    int notfound=0;

    cout <<"Replacement Policy = OPTIMAL"<<"\n";
    cout <<"-------------------------------------"<<"\n";
    cout <<"Page   Content of Frames"<<"\n";
    cout <<"----   -----------------"<<"\n";

    while(arr[j]!=-1)
    {
         //checking if the page is already
         // present in buffer or not
        for(int i=0; i<size; i++)
            if(buffer[i]==arr[j])
            {
                flag=1;
                break;
            }

        if(flag==0)
        {    //checking if buffer is full or not
            if(full<size)
            {
                buffer[full++]=arr[j];

            }
            else
            {

                int i=j+1;
                arrIndex=i;
                index=0;
                for(int k=0; k<size; k++)
                { //finding the page which is the furthest to be reuqested
                    while(arr[i]!=-1)
                    {
                        if(buffer[k]==arr[i])
                        {
                            notfound=0;
                            if(arrIndex<i)
                            {
                                arrIndex=i;
                                index=k;
                            }

                            break;
                        }
                        else
                        {
                            notfound=1;

                        }
                        i++;
                    }

                    //page is not found in any futre requests
                    // so its choosen to be replaced
                    i=j+1;
                    if(notfound)
                    {
                        index=k;
                        break;

                    }

                }
                // page fault happend
                // and a page is being swapped
                buffer[index]=arr[j];
                fault++;
                cout<<"0"<<arr[j]<<" F   ";
                for(int i=0; i<size; i++)
                {
                    if(buffer[i]!=0)
                        cout<<"0"<<buffer[i]<<" ";

                }
                cout<<"\n";
                print=1;


            }
        }

        //print=0 when the buffer is not full yet
        // or the page wanted is already in buffer
        //meaning no page fault occured
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
        flag=0;
        print=0;
        j++;


    }
    cout <<"-------------------------------------"<<"\n";
    cout <<"Number of page faults = "<<fault;
    cout <<"\n";
}
