// Matrix Chain Multiplication
#include<bits/stdc++.h> 
using namespace std; 

int MatrixChain(int dims[], int i, int j) 
{ 
	if(i == j) 
		return 0; 
	int k; 
	int min = INT_MAX; 
	int count; 
    
    for (k = i; k < j; k++) 
	{ 
		count = MatrixChain(dims, i, k) + MatrixChain(dims, k + 1, j) + dims[i - 1] * dims[k] * dims[j]; 
        if (count < min) 
			min = count; 
	} 

	return min; // Return minimum count 
} 
 
int main() 
{ 
	cout<<"\n\tMatrix Chain Multiplication"<<endl<<endl;
	int arr[] = {1, 2, 3, 4, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "\tMinimum number of multiplications is "<< MatrixChain(arr, 1, n - 1);
	cout<<endl<<endl<<"\t"; 
} 
 
