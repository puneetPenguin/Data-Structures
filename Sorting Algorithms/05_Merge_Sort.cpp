#include <iostream>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void merge(int arr[], int l, int mid, int r){
    int i = l, j = mid+1, k = l;
    int *temp = new int[r+1]; 

    while(i<=mid && j<=r){
        if (arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int m = l; m <= r; m++)
        arr[m] = temp[m];
    
    delete [] temp;
}


void mergeSort(int arr[], int l, int r)
{
    if(l<r){
        int mid = (l+r)/2;
        // calling merge sort for left part.
        mergeSort(arr, l, mid);  
        // calling for right part.
        mergeSort(arr, mid+1, r);  
        // merging sorted parts.
        merge(arr, l, mid, r);
    }

}



int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array before sorting: ";
    printArray(arr, n);

    cout << "Array after sorting: ";
    mergeSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}