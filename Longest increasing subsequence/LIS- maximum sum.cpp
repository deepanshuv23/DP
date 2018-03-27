#include<iostream>
using namespace std;
// time O(n^2)
//space O(n)

int LIS_pro(int arr[],int n)        // Longest increasing subsequence
{
    int L_sum[n];
    for(int i=0;i<n;i++)
    {
        L_sum[i]=arr[i];                // initialize with respective array elemnts
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                L_sum[i]=max(L_sum[i],L_sum[j]+arr[i]);      //updating with max contiguos product so far
            }
        }
    }

    
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(m<L_sum[i])
        {
            m=L_sum[i];
        }
    }

    return m;
}

int main()
{
    int arr[]={2,3,4,7,8,9,6,1};
    cout<<"Longest increasing sequence has length : "<<LIS_pro(arr,8);
}