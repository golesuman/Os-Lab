#include<iostream>
using namespace std;


int main()
{
    int ct[10];
    int at[10];
    int tat[10];
    int bt[10];
    int wt[10]; 
    int i;
    int totalTat = 0, totalWt = 0, sum = 0;
    
    float average; 
    float averageTurn;
    int n;
    //tat = completion time  - arrival time
    //waiting time = tat - burst time

    cout<<"Enter the no of processes:"<<endl;
    cin>>n;
    cout<<"Enter the arrival time:"<<endl;
    for(i = 0;i<n;i++)
    {
        cin>>at[i];
    }
    cout<<"Enter the burst time:"<<endl;

    for(int j=0;j<n;j++)
    {
        cin>>bt[j];
    }

    for(i = 0;i<n ; i++) //completion time
    {  
        sum += bt[i];
        ct[i] += sum;
        
    }

    for(int k = 0;k< n;k++)
    {
        tat[k] = ct[k] - at[k]; //total arrival time
        totalTat += tat[k];
      

    }
   for(int j = 0; j<n ; j++)
   {
        wt[j] = tat[j] - bt[j]; //waiting time
        totalWt += wt[j];
   }
    
 

    average = float(totalWt) / n;
    averageTurn = float(totalTat) / n;
    cout<<average<<endl;
    cout<<averageTurn<<endl;
}