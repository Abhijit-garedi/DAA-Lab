#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define Max 10

int x[Max];

int place(int k, int i)
{
  int j;
  for(j=1; j<k; j++)

  if(x[j]==i || abs(x[j]-i) == abs(j-k))
  return 0;
  return 1;

}

void nq(int k, int n)
{
    int i,j;

    static int c=0;
    for(i=1; i<=n; i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
            c++;
            printf("\nsol %4d:", c);

            for(j=1; j<=n; j++)
            printf("%ud",x[j]);
            }
            else nq(k+1, n);

        }
    }

}

    int main()
    {
        int i,j,n=4;
        nq(1,n);
    }
 
