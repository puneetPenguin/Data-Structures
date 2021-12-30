#include <iostream>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void reverseArray(int arr[], int n)
{
    int start = 0, end = n-1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++; 
        end--;
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

    cout << "Original array is: ";
    printArray(arr, n);

    reverseArray(arr, n);

    cout << "Reversed array is: ";
    printArray(arr, n);

    return 0;
}