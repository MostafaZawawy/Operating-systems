#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct Buffer
{
    int item;
    bool bit;
} Buffer;
void CLOCK(int arr[],Buffer* clock_buffer,int size)
{

    int j=0;
    int fault=0;
    int counter=0;
    int full=0;
    int print=0;
    int flag=0;

    cout <<"Replacement Policy = CLOCK"<<"\n";
    cout <<"-------------------------------------"<<"\n";
    cout <<"Page   Content of Frames"<<"\n";
    cout <<"----   -----------------"<<"\n";
    while(arr[j]!=-1)
    {

        for(int i=0; i<size; i++)
            if(clock_buffer[i].item==arr[j])
            {
                flag=1;
                clock_buffer[i].bit=1;
                break;
            }

        if(flag==0)
        {
            if(full<size)
            {
                clock_buffer[full].item=arr[j];
                clock_buffer[full++].bit=1;

            }
            else
            {
                //page with a second change bit set to 1
                //are being set to 0
                //till a page with bit=0 is found
                // and this page will be the one to be replaced
                // meaning it doesn't have a second chance
                while(clock_buffer[counter].bit==1)
                {

                    clock_buffer[counter].bit=0;

                    counter++;
                    counter=counter%size;
                }
                clock_buffer[counter].item=arr[j];
                clock_buffer[counter].bit=1;
                counter++;
                counter=counter%size;

                cout<<"0"<<arr[j]<<" F   ";
                for(int i=0; i<size; i++)
                {
                    if(clock_buffer[i].item!=0)
                        cout<<"0"<<clock_buffer[i].item<<" ";

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
                if(clock_buffer[i].item!=0)
                    cout<<"0"<<clock_buffer[i].item<<" ";


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
