#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ll long long
#define ld long double
#define mod 1000000007

using namespace std;

void swap(ll *xp, ll *yp)
{
    ll temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(ll* arr, ll n)
{
   ll i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

/* Function to prll an array */
void printArray(ll* arr, ll size)
{
    ll i;
    cout<<size<<endl;
    for (i=0; i < size; i++)
    {
        cout<<arr[i];
    }

    printf("n");
}

void selectionSort(ll* arr, ll n)
{
    ll i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(ll* arr, ll n)
{
   ll i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void merge(ll* arr, ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;

    /* create temp arrays */
    ll L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(ll* arr, ll l, ll r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ll m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

ll partition (ll* arr, ll low, ll high)
{
    ll pivot = arr[high];    // pivot
    ll i = (low - 1);  // Index of smaller element

    for (ll j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */


void quickSort(ll* arr, ll low, ll high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        ll pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// A utility function to get maximum value in arr[] 
int getMax(ll* arr, ll n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(ll* arr, ll n, ll exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixSort(ll* arr, ll n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
}

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(ll* arr, ll n, ll i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(ll* arr, ll n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <ll> arr[5][3];     //array to store nos:
    ofstream f;
    f.open("out.txt");      //to store the output

    for(ll i=0;i<3;i++)
      for(ll j=0;j<1000*pow(10,i);j++)
      {
          arr[0][i].pb(rand()%100000);
          arr[1][i].pb(arr[0][i][j]);
          arr[2][i].pb(arr[0][i][j]);
          arr[3][i].pb(arr[0][i][j]);
          arr[4][i].pb(arr[0][i][j]);
      }

    for(ll i=0;i<3;i++)
    {
      cout<<"\n"<<1000*pow(10,i)<<endl;
      clock_t tStart = clock(); //clock starts
    	mergeSort(&arr[2][i][0],0,arr[2][i].size());
    	printf("mergeSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   // calculation of duration
      f<<"mergeSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;           //input to file

      tStart = clock(); //clock starts
    	quickSort(&arr[3][i][0],0,arr[3][i].size());
    	printf("quickSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   // calculation of duration
      f<<"quickSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;           //input to file

      tStart = clock();//clock starts
    	selectionSort(&arr[0][i][0],arr[0][i].size());
    	printf("selectionSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);// calculation of duration
      f<<"selectionSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//input to file

      tStart = clock(); //clock starts
    	insertionSort(&arr[1][i][0],arr[1][i].size());
    	printf("insertionSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   // calculation of duration
      f<<"insertionSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;           //input to file

      tStart = clock();//clock starts
    	bubbleSort(&arr[4][i][0],arr[4][i].size());
    	printf("bubbleSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);// calculation of duration
      f<<"bubbleSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//input to file

      tStart = clock();//clock starts
      heapSort(&arr[4][i][0],arr[4][i].size());
      printf("heapSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);// calculation of duration
      f<<"heapSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//input to file

      tStart = clock();//clock starts
      radixSort(&arr[4][i][0],arr[4][i].size());
      printf("radixSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);// calculation of duration
      f<<"radixSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//input to file
      cout<<endl;
    }


    for(ll i=0;i<3;i++)
      for(ll j=0;j<5000*pow(10,i);j++)
      {
          arr[0][i].pb(rand()%100000);
          arr[1][i].pb(arr[0][i][j]);
          arr[2][i].pb(arr[0][i][j]);
          arr[3][i].pb(arr[0][i][j]);
          arr[4][i].pb(arr[0][i][j]);
      }

    for(ll i=0;i<3;i++)
    {
      cout<<"\n"<<5000*pow(10,i)<<endl;
      clock_t tStart = clock(); //clock starts
      mergeSort(&arr[2][i][0],0,arr[2][i].size());
      printf("mergeSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   // calculation of duration
      f<<"mergeSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;           //input to file

      tStart = clock(); //clock starts
      quickSort(&arr[3][i][0],0,arr[3][i].size());
      printf("quickSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   // calculation of duration
      f<<"quickSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;           //input to file

      tStart = clock();//clock starts
      selectionSort(&arr[0][i][0],arr[0][i].size());
      printf("selectionSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);// calculation of duration
      f<<"selectionSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//input to file

      tStart = clock(); //clock starts
      insertionSort(&arr[1][i][0],arr[1][i].size());
      printf("insertionSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   // calculation of duration
      f<<"insertionSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;           //input to file

      tStart = clock();//clock starts
      bubbleSort(&arr[4][i][0],arr[4][i].size());
      printf("bubbleSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);// calculation of duration
      f<<"bubbleSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//input to file

      tStart = clock();//clock starts
      heapSort(&arr[4][i][0],arr[4][i].size());
      printf("heapSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);// calculation of duration
      f<<"heapSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//input to file

      tStart = clock();//clock starts
      radixSort(&arr[4][i][0],arr[4][i].size());
      printf("radixSort Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);// calculation of duration
      f<<"radixSort Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//input to file
      cout<<endl;
    }
    return 0;
}
