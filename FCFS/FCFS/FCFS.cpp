//============================================================================
// Name        : FCFS.cpp
// Author      : Amogh, Michael, Kyle
// Version     : 1.0.0
// Description : First Come First Serve Scheduling Algorithm in C++, Ansi-style
// Reference   : https://www.thecrazyprogrammer.com/2014/11/c-cpp-program-for-first-come-first-served-fcfs.html
//============================================================================
#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>

using namespace std;

int main()
{
    cout <<endl;
    cout <<"-----------------------FIRST COME FIRST SERVE ALGORITHM--------------------------" <<endl;
    while(true)
    {
        cout <<endl
             <<"OPTIONS : " <<endl
             <<"1. Test with random data " <<endl
             <<"2. Custom Data " <<endl
             <<"Enter choice (1/2), or any other value to exit : " ;
    
        int choice;
        cin >>choice;
        if (choice !=1 && choice != 2) exit(0);
    
    
        int n; //Total number of processes
        int avwt = 0; // Average waiting time
        int avtat = 0; // Average Turnaround time
        int i; //Iteration variable
        int j; //Iteration variable
    
        /*
         * bt : Burst Time
         * wt : Wait Time
         * tat : Turnaround time
         */
    
        vector<int> bt, wt, tat;
        srand(static_cast<int>(time(NULL)));
    
        cout<<"Enter total number of processes : ";
        if (choice == 2) cin>>n;
        else
        {
            
            n = rand() % 30 + 1;
            cout <<n <<endl;
        }
        bt.reserve(n);
        wt.reserve(n);
        tat.reserve(n);
    
        if (choice ==2) cout<<"\nEnter Process Burst Time\n";
        for( i = 0 ; i < n ; i++ )
        {
            cout<<"P["<<i+1<<"]:";
            if (choice == 2) cin>>bt[i];
            else
            {
                bt[i] = rand() % 20 + 1;
                cout <<" " <<bt[i] <<endl;
            }
        }
    
        wt[0]=0;    // waiting time for first process is 0
    
        //calculating waiting time
        for( i = 1 ; i < n ; i++ )
        {
            wt[i] = 0;
            for( j = 0 ; j < i ; j++ )
                wt[i] += bt[j];
        }
    
        cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    
        //calculating turnaround time
        for( i=0 ; i < n ; i++ )
        {
            tat[i] = bt[i] + wt[i];
            avwt += wt[i];
            avtat += tat[i];
            cout<<"\nP[" <<i + 1 <<"]" <<"\t\t\t" <<bt[i] <<"\t\t" <<wt[i] <<"\t\t" <<tat[i];
        }
    
        avwt /= i;
        avtat /= i;
        cout<<"\n\nAverage Waiting Time:"<<avwt;
        cout<<"\nAverage Turnaround Time:"<<avtat <<endl;
    }
    return 0;
}
