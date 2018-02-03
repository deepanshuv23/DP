#include<iostream>
using namespace std;
//printing the lcs function
void print_lcs(string x,string y)
{
    int m,n;
    m=x.length();
    n=y.length();
    int index = L[m][n];
 
   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   // Print the lcs
   cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
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
//space optimized solution for lcs

int lcs2(string x,string y)
{
    int m,n;
    m=x.length();
    n=y.length();
    int L[2][n+1],bi;
    for(int i=0;i<=m;i++)
    {
        bi=i&1;     //compute current binary index
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                L[bi][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                L[bi][j]=L[1-bi][j-1]+1;      // sequence matched so increase the counter by one
            }
            else
            {
                L[bi][j]=max(L[1-bi][j],L[bi][j-1]); // update current entry with the maximum length of subsequence found
            }
        }
    }
    return L[bi][n];
}


int main()
{
  string X = "AGGTAB";
  string Y = "AGGCTABX";
  
  
  printf("Length of LCS is %d\n", lcs2( X, Y) );
 
  return 0;
}

