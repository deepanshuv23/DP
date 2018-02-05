#include<iostream>
using namespace std;

int bitonic_LIS(int arr[],int n)        // Longest increasing subsequence
{
    int L[n]={1},L_rev[n]={1},arr_rev[n]={0};
    for(int i=0;i<n;i++)
    {
        arr_rev[i]=arr[n-i-1];          //creating a reversed array
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                L[i]=max(L[i],L[j]+1);      //updating the current element with the max length so far
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr_rev[j]<arr_rev[i])
            {                                            //LIS for reversed array
                L_rev[i]=max(L_rev[i],L_rev[j]+1);      //updating the current element with the max length so far
            }
        }
    }

    int m=0;
    for(int i=0;i<n;i++)
    {
        if(m<L[i]+L_rev[n-i-1]-1)
        {
            m=L[i]+L_rev[n-i-1]-1;
        }
    }

    return m;
}

int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14,
                  1, 9, 5, 13, 3, 11, 7, 15
                };

    cout<<bitonic_LIS(arr,16);
    return 0;
}