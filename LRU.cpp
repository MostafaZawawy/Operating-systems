#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void LRU(int arr[],int*buffer,int size)
{
    int j=0;
    int fault=0;
    int flag=0;
    int full=0;
    int print=0;
    int index;
    int arrIndex;

    cout <<"Replacement Policy = LRU"<<"\n";
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
            {
                index=0;
                arrIndex=j-1;
                for(int k=0; k<size; k++)
                {
                    for(int i=j-1; i>=0; i--)
                    {  //finding the LRU page
                        if(buffer[k]==arr[i])
                        {
                            if(arrIndex>i)
                            {
                                arrIndex=i;
                                index=k;
                            }
                            break;
                        }
                    }
                }
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
