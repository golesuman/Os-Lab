#include<iostream>
#include<string.h>
using namespace std;
int main()

{
	int at[20], et[20];
	char P[20][10], t[10];
//	char t[10];
	int temp;
	float avgT, avgW;
	int sum = 0 , sumt = 0 , sumw = 0;
	int tat[20], wt[20], compt[20];
	int n;
	cout<<"Enter the no of processes:"<<endl;
	cin>>n;
	cout<<"Enter the process names, arrival time and execution time: "<<endl;
	for(int i = 0; i< n; i++)
	{
		cin>>P[i];
		cin>>at[i];
		cin>>et[i];
	}
	for (int i=0 ; i< n; i++)
	{
		if(at[i+1] < at[0])
		{
			temp = at[i+1];
			at[i+1] = at[0];
			at[0] = temp;
			temp = et[i+1];
			et[i+1] = et[0];
			et[0] = temp;
			strcpy(t, P[i+1]);
			strcpy(P[i+1], P[0]);
			strcpy(P[0], t);
			
		}
	}
	//
	for(int i =1; i<n;i++)
	{
		for(int j = 1; j<n; j++)
		{
			if (et[i]< et[j])
			{
				temp = at[i];
				at[i] = at[j];
				temp = et [i];
				et[i] = et[j];
				et[j] = temp;
				strcpy(t, P[i]);
				strcpy(P[i], P[j]);
				strcpy(P[j], t);
			}
		}
	}
	
	for(int i = 0; i< n;i++)
	{
		compt[i] = sum + et[i];
		sum += compt[i];
	}
	
	// calculating turn around time and waiting time
	for(int i = 0 ; i < n; i++)
	{
		tat[i] = compt[i] - at[i];
		sumt += tat[i];
		wt[i] = tat[i] - et[i];
		sumw += wt[i]; 
	}
	for(int i =0; i< n ; i++)
	{
		cout<<"Turn around time"<<"\t"<<"Waiting time"<<"\n"<<endl;
		cout<<tat[i] <<"\t\t\t"<<wt[i]<<endl;	
	}
	avgT = float(sumt)/n;
	avgW = float(sumw)/n;
	cout<<"The average turnaround time is "<<avgT<<endl;
	cout<<"The average waiting time is:"<<avgW<<endl;	
	
}
