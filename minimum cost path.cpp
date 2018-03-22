/* Dynamic Programming implementation of MCP problem */
#include<stdio.h>
#include<limits.h>
#define R 3
#define C 3
 // apply a greedy approach 
int min(int x, int y, int z);
 
int minCost(int cost[R][C], int m, int n)
{
    int result[R][C]={0};

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0&&j==0)
            {
                result[i][j]=cost[i][j];            // no way to go
            }
            else if(i==0)
            {
                result[i][j]=cost[i][j]+result[i][j-1];     // can only move right
            }
            else if(j==0)
            {
                result[i][j]=cost[i][j]+result[i-1][j];     // can only move down
            }
            else
            {
                result[i][j]=cost[i][j]+min(result[i][j-1],result[i-1][j],result[i-1][j-1]); //minimum of the three path options
            }
        }
    }

    return result[m-1][n-1];
}
 
/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
 
/* Driver program to test above functions */
int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", minCost(cost, 3, 3));
   return 0;
}
