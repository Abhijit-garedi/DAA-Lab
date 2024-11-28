#include<stdio.h>


typedef struct { int pr,dl,no; } job;

int jseq( job jb[], job jop[], int nj)
 {  int i,r,j,k,l;   job t;   int d[15];
    jop[0].pr=0;    jop[0].dl=0;    jop[1]=jb[1];     k=1;
    for(i=2;i<=nj; i++)
    { r=k;      
      while((jop[r].dl > jb[i].dl) && (jop[r].dl!= r))    r--;
      if( (jop[r].dl <= jb[i].dl)&& (jb[i].dl > r))
      {  for(l=k; l>r; l--)     jop[l+1]=jop[l];
          jop[r+1]=jb[i];   k++;
       } }
   return k;
  }

void sort(job jb[15], int nj)
 {  int i,j;    job t;
    for(i=1;i<nj;i++)  
     for(j=i+1;j<=nj;j++)
       if(jb[i].pr < jb[j].pr)    
         {  t=jb[i];  jb[i]=jb[j]; jb[j]=t; }
  }

int main()
{ job j[15], jq[15];
  int i,n,nk,totpr=0;
  for(i=1;i<=14;i++)  
  { j[i].pr=0;    j[i].dl=0;    j[i].no=i;  }
  printf("Enter no. of jobs: ");       
    scanf("%d",&n);
  printf("Enter jobs data: ");     
   for(i=1;i<=n;i++)  
     scanf("%d %d",&j[i].pr,&j[i].dl);
  
  sort(j,n);
  nk=jseq(j,jq,n);

  printf("\n Best seq \n");
  for(i=1;i<=nk;i++)
   { totpr+=jq[i].pr;
      printf("\nJ%-2d) %5d  %5d", jq[i].no, jq[i].pr, jq[i].dl);
    }
  printf("\nTotal Profit earned is : %d\n\n ",totpr);
  //getch();
  return 0;
  }
  
