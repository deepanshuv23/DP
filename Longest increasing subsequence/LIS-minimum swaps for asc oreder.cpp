// CPP program to find min elements to
// change so array is strictly increasing
#include <bits/stdc++.h>
using namespace std;
 
// To find min elements to remove from array
// to make it strictly increasing
int minRemove(int arr[], int n)
{
    int LCS[n], len = 0;
 
    // Mark all elements of LCS as 1
    for (int i = 0; i < n; i++)
        LCS[i] = 1;
 
    // Find LCS of array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                LCS[i] = max(LCS[i], LCS[j] + 1);
        }
        len = max(len, LCS[i]);
    }
 
    // Return min changes for array
    // to strictly increasing
    return n - len;
}
 
// Driver program to test minRemove()
int main()
{
    int arr[] = { 1, 2, 6, 5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << minRemove(arr, n);
 
    return 0;
}