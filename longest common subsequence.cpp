#include<iostream.h>
using namespace std;


//longest common subsequence dp approach
int lcs(string x,string y)
{
    int m,n;
    m=x.length();
    n=y.length();

    int L[m+1][n+1],i,j;

    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                L[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;      // sequence matched so increase the counter by one
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]); // update current entry with the maximum length of subsequence found
            }
        }
    }

    return L[m][n];

}

int main()
{
  string X = "AGGTAB";
  string Y = "GXTXAYB";
  
  
  printf("Length of LCS is %dn", lcs( X, Y) );
 
  return 0;
}

