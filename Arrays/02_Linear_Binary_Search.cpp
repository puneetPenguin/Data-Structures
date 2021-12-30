#include <iostream>
using namespace std;


void separator()
{
    cout << "-----------------------------------------------------------" << endl;
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int linearSearch(int arr[], int n, int key)
{
    for(int i=0; i<n; i++){
        if (key == arr[i])
            return i;
    }
    return -1;
}


int binarySearch(int arr[], int n, int key)
{
    int start, mid, end;
    start = 0;
    end = n-1;

    while(start <= end){
        mid = (start + end) / 2;

        if (key == arr[mid]) return mid;
        else if (key < arr[mid]) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
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

    int key;
    cout << "Enter key: ";
    cin >> key;

    separator();
    cout << "!!!:::Using linear search:::!!!" << endl;
    cout << "The given key occurs at index " << linearSearch(arr, n, key) << "." << endl;
    separator();

    separator();
    cout << "!!!:::Using binary search:::!!!" << endl;
    cout << "The given key occurs at index " << binarySearch(arr, n, key) << "." << endl;
    separator();

    return 0;
}