
#include<iostream>
using namespace std;
int main()
{
	int a[10], b[10], x[10];
	int waiting[10], turnaround[10], completion[10];
	int i, j, smallest, count = 0, time, n;
	double avg = 0, tt = 0, end;
	cout<<"Enter the number of processes:"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the arrival time of process:";
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the burst time of process:";
		cin>>b[i];
	}
	for(i=0;i<n;i++)
	{
		x[i] = b[i];
	}
		b[9] = 999;

		
	time = 0;
	while(count!= n)
	{
		
		smallest = 9;
		for(i=0;i<n;i++)
		{
			if (a[i]<=time && b[i] < b[smallest] && b[i] > 0)
				smallest = i;
		}	
			
		b[smallest] --;
		if (b[smallest] == 0)
		{
			count ++;
			end = time+1;
			completion[smallest] = end;
			waiting[smallest] = end - a[smallest] - x [smallest];
			turnaround[smallest] = end - a[smallest];
			
		}
		time++;
	}
		
	cout<<"Process"<<"\t"<<"burst time"<<"\t"<<"arrival time"<<"\t"<<"Waiting time"<<"\t"<<"turrnaound time"<<"\t"<<"completion time"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
		avg += waiting[i];
		tt += turnaround[i];
	}
	cout<<"\n Average waiting time = "<<avg/n<<"\n";
	cout<<"Average turanound time = "<<tt/n<<endl;
	return 0;	
	}

