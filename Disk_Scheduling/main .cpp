#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
void FIFO(vector<int> numbers,int start)
{
    int diff=abs(start-numbers[0]);
    int sum=diff;
    float avg;
    cout<<start;
    for( int i=0; i<numbers.size(); i++)
    {

        cout<<"->"<<numbers[i];
        if(i+1<numbers.size())
        {
            diff=abs(numbers[i]-numbers[i+1]);
            sum+=diff;
        }
    }

    cout<<endl;

    avg=(float)sum/(float)(numbers.size());
    cout<<"sum is"<<sum<<endl;

    cout<<"avg is"<<fixed << setprecision(4)<<avg<<endl;


}

void SCAN(vector<int> numbers,int start,bool direction)
{
    int diff;
    int sum=0;
    float avg;
    sort(numbers.begin(), numbers.end());

    int index=0;
    while(start>numbers[++index]);

    cout<<start;
    //move to the right
    if(direction)
    {
        diff=abs(start-numbers[index]);
        sum=diff;


        for(int i=index; i<numbers.size(); i++)
        {
            cout<<"->"<<numbers[i];
            if(i+1<numbers.size())
            {
                diff=abs(numbers[i]-numbers[i+1]);
                sum+=diff;
            }
        }
        diff=abs(numbers.back()-numbers[index-1]);
        sum+=diff;


        for(int i=index-1; i>=0; i--)
        {

            cout<<"->"<<numbers[i];
            if(i-1>=0)
            {
                diff=abs(numbers[i]-numbers[i-1]);
                sum+=diff;
            }

        }


    }
    //move to the left
    else
    {

        diff=abs(start-numbers[index-1]);
        sum=diff;
        //cout<<diff<<endl;

        for(int i=index-1; i>=0; i--)
        {

            cout<<"->"<<numbers[i];
            if(i-1>=0)
            {
                diff=abs(numbers[i]-numbers[i-1]);
                //cout<<diff<<endl;
                sum+=diff;
            }

        }
        diff=abs(numbers[0]-numbers[index]);
        sum+=diff;
        //cout<<diff<<endl;

        for(int i=index; i<numbers.size(); i++)
        {
            cout<<"->"<<numbers[i];
            if(i+1<numbers.size())
            {
                diff=abs(numbers[i]-numbers[i+1]);
                //cout<<diff<<endl;
                sum+=diff;
            }
        }

    }


    cout<<endl;
    avg=(float)sum/(float)(numbers.size());
    cout<<"Total head movements ="<<sum<<endl;

    cout<<"Average head movement ="<<fixed << setprecision(4)<<avg<<endl;


}

void CSCAN(vector <int> numbers,int start,bool direction)
{

    int diff;
    int sum=0;
    float avg;
    sort(numbers.begin(), numbers.end());

    int index=0;
    while(start>numbers[++index]);
    cout<<start;
    //move to the right
    if(direction)
    {
        diff=abs(start-numbers[index]);
        sum=diff;


        for(int i=index; i<numbers.size(); i++)
        {
            cout<<"->"<<numbers[i];
            if(i+1<numbers.size())
            {
                diff=abs(numbers[i]-numbers[i+1]);
                sum+=diff;
            }
        }
        diff=abs(numbers.front()-numbers.back());
        sum+=diff;
        for(int i=0; i<index; i++)
        {
           cout<<"->"<<numbers[i];
            if(i+1<index)
            {
                diff=abs(numbers[i]-numbers[i+1]);
                sum+=diff;
            }

        }

    }
    //move to the left
    else{
    diff=abs(start-numbers[index-1]);
        sum=diff;
        //cout<<diff<<endl;

        for(int i=index-1; i>=0; i--)
        {

            cout<<"->"<<numbers[i];
            if(i-1>=0)
            {
                diff=abs(numbers[i]-numbers[i-1]);
                //cout<<diff<<endl;
                sum+=diff;
            }

        }
        diff=abs(numbers.front()-numbers.back());
        sum+=diff;
        for(int i=numbers.size()-1;i>=index; i--)
        {
            cout<<"->"<<numbers[i];
            if(i-1>=index)
            {
                diff=abs(numbers[i]-numbers[i-1]);
                //cout<<diff<<endl;
                sum+=diff;
            }
        }

    }



     cout<<endl;
    avg=(float)sum/(float)(numbers.size());
    cout<<"Total head movements ="<<sum<<endl;

    cout<<"Average head movement ="<<fixed << setprecision(4)<<avg<<endl;







    }


int main()
{
    int size;
    int i=0;
    int no_requests;
    int start;
    int select;
    bool direction;
    vector<int> numbers;
    cout<< "Enter 1 for FIFO 2 for SCAN 3 for C-SCAN"<<endl;
    cin>>select;

    cout << "Enter size of disk" << endl;
    cin >> size;
    cout << "Enter number of requests" << endl;
    cin >> no_requests;
    cout << "Enter the requests" << endl;

    for (i = 0; i < no_requests; ++i)
    {
        int temp;
        cin >> temp;
        if(temp>size){
        cout<<"You have entered an invalid value"<<endl;
        exit(0);
        }
        numbers.push_back(temp);
    }
    cout <<"Enter the head postion"<<endl;
    cin  >>start;
    cout <<"Enter the head direction"<<endl;
    cin  >> direction;

   switch(select){
    case 1:
    FIFO(numbers,start);
    break;
    case 2:
    SCAN(numbers,start,direction);
    break;
    case 3:
    CSCAN(numbers,start,direction);
    break;
}





    return 0;
}
