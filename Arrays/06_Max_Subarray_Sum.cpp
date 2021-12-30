/* 
                 :::KADANE'S ALGORITHM:::
    Step-1: Maintain a current sum and max sum variable.
    Step-2: Loop through array and add elements to current sum one by one.
    Step-3: If sum > max sum then update max sum.
    Step-4: If current sum goes -ve, then make it 0 because -ve value will reduce the sum of upcoming subarrays.
*/

#include <iostream>
#include <climits>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int maxSumOfSubarray(int arr[], int n)
{
    int currentSum = 0, maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        currentSum += arr[i];
        
        maxSum = max(currentSum, maxSum);

        if (currentSum < 0) currentSum = 0;
    }
    return maxSum;
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

    cout << "Maximum sum of subarray is: " << maxSumOfSubarray(arr, n) << endl;

    return 0;
}