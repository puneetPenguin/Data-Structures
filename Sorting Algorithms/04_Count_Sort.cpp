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


void countSort(int arr[], int n)
{
    int maximum = maxElement(arr, n);
    int count[maximum+1] = {0};

    for(int i=0; i<n; i++)
        count[arr[i]]++;

    int temp = 0, j=0;
    while(temp <= maximum){
        if (count[temp] != 0){
            arr[j] = temp;
            count[temp]--;
            j++;
        }
        else{
            temp++;
        }
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
    countSort(arr, n);
    printArray(arr, n);

    return 0;
}