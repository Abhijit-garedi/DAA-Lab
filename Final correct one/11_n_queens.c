// n queens sir wala corrected 
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define Max 10

int x[Max];

int place(int k, int i)
{ 
    int j;
  for(j=1;j<k;j++)
  {
   if( (x[j]==i)||(abs(x[j]-i) == abs( j-k)))
   {
    return 0;
   }}
  return 1;
}

void nq(int k,int n)
{  int i,j;
   static int c=0;
   for(i=1;i<=n;i++)
   { if(place(k,i))
     { x[k]=i;
       if(k==n)
	{ c++;
	  printf("\nSol(%4d): ",c);
	  for(j=1;j<=n;j++)
	   printf("%4d",x[j]);
	 }
       else nq(k+1,n);
     }
    }
}

int main()
{
  int i,j,n=4;

  nq(1,n);
  
}
