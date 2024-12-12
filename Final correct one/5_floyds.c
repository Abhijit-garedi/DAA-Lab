// Floyd Warshall's algorithm in C

#include <stdio.h>

#define MAX 10

// Applying Krushkal Algo
void APSP(int a[MAX][MAX],int n,int k)
{ int i,j;

  for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
    if (a[i][j] > a[i][k]+a[k][j])
     a[i][j]=a[i][k]+a[k][j];
  printf("\nRound %d",k);
  for (i = 0; i < n; i++)
  { printf("\n");
    for (j = 0; j < n; j++)
      printf("%6d",a[i][j]);
  }

  k++;
  if(k<n) APSP(a,n,k);
}

int main()
{
  int a[MAX][MAX]={{0    ,    4,15000,    5,15000},
		   {15000,    0,    1,15000,    6},
		   {    2,15000,    0,    3,15000},
		   {15000,15000,    1,    0,    2},
		   {    1,15000,15000,    4,    0}};
  int n,i,j;

  n = 5;
  printf("\n Initially");
  for (i = 0; i < n; i++)
  { printf("\n");
    for (j = 0; j < n; j++)
      printf("%4d",a[i][j]);
  }
  APSP(a,n,0);
  printf("\n Finally");
  for (i = 0; i < n; i++)
  { printf("\n");
    for (j = 0; j < n; j++)
      printf("%4d",a[i][j]);
  }
 return 0;
}