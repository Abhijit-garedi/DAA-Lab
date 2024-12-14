//sum of subsets 
#include <stdio.h>
#include <math.h>

#define Max 10

void sos(int w[],int k,int r,int s,int d,int x[Max],int n)
{  int i,j;
   if(k==n) return;
   x[k]=0;
   if(s==d)
    {printf("\n");
     if(k==n-1)
      for(j=0;j<n;j++)
       printf("%4d",x[j]);
     }
     else if(s+r<d) return;
     else if(s+w[k]>d) return;

   sos(w,k+1,r-w[k],s,d,x,n);

   x[k]=1;
   s+=w[k];
   if(s==d)
   { if(k==n-1)
      for(j=0;j<n;j++)
       printf("%4d",x[j]);
    }
    else if(s+r<d) return;
     else if(s+w[k]>d) return;
   sos(w,k+1,r-w[k],s,d,x,n);
}
void sort(int w[],int n)
{ int i,j,t;
  for(i=0;i<n;i++)
   for(j=i+1;j<n;j++)
   
    if(w[i]>w[j])
    { t=w[i];
      w[i]=w[j];
      w[j]=t;
     }
  }
int main()
{
  int i,j;
  int x[Max],w[]={1,2,5,6,8},d=9;
  int s=0,r=0;
  int n=sizeof(w)/sizeof(n);
  sort(w,n);
  for(i=0;i<n;i++)
  { r+=w[i];
    x[i]=0;
   }
  sos(w,0,r,s,d,x,n);

}

 