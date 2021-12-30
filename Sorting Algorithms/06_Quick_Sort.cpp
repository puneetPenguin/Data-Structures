#include <iostream>
#include <climits>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int maxElement(int arr[], int n)
{   
    int m = INT_MIN;
    for(int i=0; i<n; i++)
        m = max(m, arr[i]);
    return m;
}


// Function that sorts element to its position and returns partition index.
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;

        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], pivot);
    return j;
}


void quickSort(int arr[], int low, int high)
{
    if(low < high){
        int partitionIndex = partition(arr, low, high);
        // Call function for left partition.
        quickSort(arr, low, partitionIndex-1);
        // Call function for right partition.
        quickSort(arr, partitionIndex+1, high);
    }
}


int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << "Array before sorting: ";
    printArray(arr, n);

    cout << "Array after sorting: ";
    quickSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}