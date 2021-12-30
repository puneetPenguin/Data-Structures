#include <iostream>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void printPairs(int arr[], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++)
            cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
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

    cout << "Pairs are:\n";
    printPairs(arr, n);

    return 0;
}