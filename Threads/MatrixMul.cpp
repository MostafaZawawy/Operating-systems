#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <time.h>
using namespace std;

typedef struct args
{
    int i;
    int j;
    int k;
    int*mul;
    int*Arow;
    int*Bcol;
    int n;
    int n2;
} args;
//matrix malutiplication each Row has a thread
void *dotproductR(void* input)
{

    int sum=0;
    args* arg;
    arg=(args *)input;
    int j;
    //n2 is number of columns in the second matrix
    for(int i=0; i<arg->n2; i++)
    {   // k =the number of elements in each row in the first matrix
        // k =the number of elements in each column in the second matrix
        for(j=0; j<arg->k; j++)
        {

            sum+=*((arg->Arow+arg->i*arg->n)+j)*(*((arg->Bcol+j*arg->n2)+i));


        }
        *((arg->mul+arg->i*4) + i)=sum;
        sum=0;

    }
    return 0;
}
//Each element has his own thread
void *dotproductE(void *input)
{
    int sum=0;
    args* arg;
    arg=(args *)input;

    for(int i=0; i<arg->k; i++)
    {
        sum+=*((arg->Arow+arg->i*arg->n)+i)*(*((arg->Bcol+i*arg->n2)+arg->j));

    }

    *((arg->mul+arg->i*4) + arg->j)=sum;

    return 0;
}


int main()
{
    clockid_t time1,time2;
    int m,n,m2,n2;
    //m and n are diminsions of matrix A
    //m2 and n2 are diminsions of matrix B

    printf("Please enter filename:");
    string x;
    cin>>x;
    ifstream f(x);
    f >> m >> n;
    int element;
    int *Arow;
    //alocating space for materix A
    Arow=(int*)malloc(sizeof(int)*m*n);
    //filling matrix A from file
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            f >> element;
            *((Arow+i*n)+j)=element;
        }

    f>> m2>> n2;
    if(n!=m2)
    {
        printf("cant matiply A and B");
        return 0;

    }


    int *Bcol;
    // allocating space for matrix B
    Bcol=(int*)malloc(sizeof(int)*m2*n2);
    //filling matrix B from file
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
        {
            f >> element;
            *((Bcol+i*n2)+j)=element;

        }

    int threadNo=m*n2;
    int *mul;
    mul=(int*)malloc(sizeof(int)*m*n2);
    int t=0;


    pthread_t thread[threadNo];
    // a struct used to pass paramters to the thread functions
    args *input=(args*)malloc(sizeof(args));
    input->Arow=Arow;
    input->Bcol=Bcol;
    input->mul=mul;
    input->n=n;
    input->n2=n2;
    input->k=n;

    // First method by element
    time1 = clock();
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n2; j++)
        {   //i and j indicate which row(i) is multiplied to which coloumn(j)
            input->i=i;
            input->j=j;

            pthread_create(&thread[t],NULL,(void *(*) (void *))dotproductE,(void*)input);
            pthread_join(thread[t++],NULL);

        }
    }
    time1 = clock() - time1;
    double time_taken1 = ((double)time1)/CLOCKS_PER_SEC;
    //write to file
    ofstream f1("matrixoutput.txt");
    f1 << m << " " << n2 << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            f1 <<*((mul+i*n2) +j)<<" ";
        }
        f1 << "\n";
    }
    f1 <<"END1"<<" "<<time_taken1<<"\n";

    //second method by row
     time2 = clock();
     t=0;
     int threadNo2=m;
     pthread_t thread2[threadNo2];
    for(int i=0; i<m; i++)
    {
            input->i=i;
            // i indicats which row is being calculated

            pthread_create(&thread2[t],NULL,(void *(*) (void *))dotproductR,(void*)input);

            pthread_join(thread2[t++],NULL);



    }
    time1 = clock() - time2;
    double time_taken2 = ((double)time2)/CLOCKS_PER_SEC;
    //write to file
    f1 << m << " " << n2 << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            f1 <<*((mul+i*n2) +j)<<" ";
        }
        f1 << "\n";
    }
    f1 <<"END2"<<" "<<time_taken2;

       return 0;

}
