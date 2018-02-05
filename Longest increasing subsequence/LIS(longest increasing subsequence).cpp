#include<iostream>
using namespace std;
// time O(n^2)
//space O(n)

int LIS(int arr[],int n)        // Longest increasing subsequence
{
    int L[n]={1};

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                L[i]=max(L[i],L[j]+1);      //updating the current lement with the max length so far
            }
        }
    }

    
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(m<L[i])
        {
            m=L[i];
        }
    }

    return m;
}

int main()
{
    int arr[]={2,3,4,7,8,9,6,1};
    cout<<"Longest increasing sequence has length : "<<LIS(arr,8);
}