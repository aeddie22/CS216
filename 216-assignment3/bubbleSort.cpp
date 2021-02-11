/*
    อาดีนัน อับดุลลี
    6209650719
 */
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
     if (swapped == false)
        break;
   }
}
  
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
    cout << arr[i] << " ";
}

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
    bubbleSort(arr, size);
    clock_t End = clock();
    cout << "Sorting values from "<< fileName << ":" << endl;
    printArray(arr, size);
    cout << endl;
    float elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Time taken: " << elapsedTime << " ms" << endl;
    return 0;
}
