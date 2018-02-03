#include<iostream>
using namespace std;

// This function mainly returns LCS(str, str)
// with a modification that same characters at
// same index are not considered. 
// time O(n^2)
// space O(n^2)
// similarly space can be reduced
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();
  
    // Create and initialize DP table
    int dp[n+1][n+1]={0} ;
  
    // Fill dp table (similar to LCS loops)
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            // If characters match and indexes are 
            // not same
            if (str[i-1] == str[j-1] && i != j)     //extra condition i!=j
                dp[i][j] =  dp[i-1][j-1] + 1;          
                       
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}

int main()
{
  string X = "ABGGTABG";
  
  printf("Length of Longest repeated subsequence is %d\n", findLongestRepeatingSubSeq(X) );
 
  return 0;
}
