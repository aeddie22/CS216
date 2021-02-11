/*
    อาดีนัน อับดุลลี
    6209650719
 */
#include<iostream>
#include <fstream>
#include <time.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
  
    // Create temp arrays
    int L[n1], R[n2];
  
    // Copy data to temp arrays L[] and R[]
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    // Merge the temp arrays back into arr[l..r]
      
    // Initial index of first subarray
    int i = 0;
      
    // Initial index of second subarray
    int j = 0;
      
    // Initial index of merged subarray
    int k = l;
      
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
  
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
          
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}
  
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
        cout << A[i] << " ";
}
  
// Driver code
int main()
{
    ifstream myFile;
    string fileName;
    int temp, i = 0;
    
    cout << "Enter file name : ";
    cin >> fileName;
    myFile.open(fileName);
    int arr[1001];
    while (myFile >> temp) {
        arr[i] = temp;
        i++;
    }
    int size = arr[0];
    
       int b[size];
       for(int i = 1 , j=0 ; i<size ,j<size ; i++ , j++){
           b[j]=arr[i];
    }
    //int n = sizeof(arr)/sizeof(arr[0]);
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;
    clock_t Start = clock();
    mergeSort(arr, 0, size-1);
    clock_t End = clock();
    cout << "Sorting values from "<< fileName << ":" << endl;
    printArray(arr, size);
    cout << endl;
    float elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Time taken: " << elapsedTime << " ms" << endl;
    return 0;
}
