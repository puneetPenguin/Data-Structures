/*
    1: Iterate from arr[1] to arr[n] over the array. 
    2: Compare the current element (key) to its predecessor. 
    3: If the key element is smaller than its predecessor, compare it to the elements 
       before. Move the greater elements one position up to make space for the swapped element.
*/

#include <iostream>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void selectionSort(int arr[], int n)
{
    int i, j, min_index;
    for(i = 0; i < n-1; i++){
        min_index = i;
        for(j = i+1; j < n; j++){
            if (arr[j] < arr[min_index]) min_index = j;
        }
        swap(arr[min_index], arr[i]);
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
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}