// Activity Selection Problem  
#include <bits/stdc++.h> 
using namespace std;  
struct Activitiy 
{ 
	int start, finish; //job with start time, finish time, profit
}; 
 
bool CompareActivity(Activitiy s1, Activitiy s2) // A utility function that is used for sorting activities
{ 
	return (s1.finish < s2.finish); 
} 
 
void MaxActivities(Activitiy arr[], int n)  // Returns count of the maximum set of activities
{ 

	sort(arr, arr+n, CompareActivity); // Sort jobs according to finish time 

	cout << "\tFollowing activities are selected\n\n\t"; 

	
	int i = 0;  // The first activity always gets selected 
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 

	 
	for (int j = 1; j < n; j++)  // Consider rest of the activities
	{ 
	   if (arr[j].start >= arr[i].finish) 
	  { 
		cout << "(" << arr[j].start << ", "<< arr[j].finish << "), "; 
		i = j; 
	  } 
	} 

	cout<<endl<<endl;
} 

 
int main() 
{ 
	cout<<"\n\tACTIVITY SELECTION PROGRAM\n\n";
	Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout<<"\tActivities given in an unsorted manner as follows\n\n\t";
	for(int i=0;i<n;++i)
	{
		cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";
	}
	cout<<endl<<endl;
	MaxActivities(arr, n); 
	cout<<"\t";
	return 0; 
} 
