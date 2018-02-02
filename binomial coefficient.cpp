#include<iostream.h>
using namespace std;

//recursive approach to find binomial coefficient
int binomial_rec(int n,int k)
{
    if(k==0||k==n)
        return 1;

    return binomial_rec(n-1,k-1)+binomial_rec(n-1,k);
}


//dp appraoch

int binomial_dp(int n,int k)
{
    int c[n+1][k+1];
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<min(i,k);j++)         //min is used to ignore irelevant cases
        {
            if(j==0||i==j)
            {
                c[i][j]=1;              // base condition
            }
            else
            {
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }

    return c[n][k];
}
int main()
{
    int n = 5, k = 2;
    printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) );
    return 0;
}