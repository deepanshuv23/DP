#include<iostream>
#include<stdlib.h>
using namespace std;

// Time O(n)
// Space O(n)
int nth_ugly_number(int n)
{
    int ugly[n];
    ugly[0]=1;              //this is the first element in this sequence

    int i2,i3,i5;
    i2=i5=i3=0;

    int next_ugly_no,next_multiple2,next_multiple3,next_multiple5;
    next_multiple2=2;
    next_multiple3=3;
    next_multiple5=5;

    for(int i=1;i<n;i++)
    {
        next_ugly_no = min(min(next_multiple2,next_multiple3),next_multiple5);      // taking the least among all multiples

        ugly[i]=next_ugly_no;

        if(next_ugly_no==next_multiple2)
        {
            i2++;
            next_multiple2=ugly[i2]*2;
        }
        else if(next_ugly_no==next_multiple3)
        {
            i3++;
            next_multiple2=ugly[i3]*3;
        }
        else if(next_ugly_no==next_multiple5)
        {
            i5++;
            next_multiple5=ugly[i5]*5;
        }
    }
    return next_ugly_no;
}

int main()
{
    cout<<"9th ugly number is "<<nth_ugly_number(9);

    return 0;
}