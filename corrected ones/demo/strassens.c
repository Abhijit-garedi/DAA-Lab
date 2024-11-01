#include <stdio.h>
#include <math.h>

#define max 8

int smm(int a[max][max],int b[max][max],int c[max][max],int rw)
{ static noa=0,nom=0;
  int p,q,r,s,t,u,v;

  int i,j;

  if(rw==2)
  { p = (a[0][0]+a[1][0])*(b[0][0]+b[0][1]);
    printf("\n(%d+%d)*(%d+%d)==>%d",a[0][0],a[1][0],b[0][0],b[0][1],p);
    q = (a[0][1]+a[1][1])*(b[1][0]+b[1][1]);
    printf("\n(%d+%d)*(%d+%d)==>%d",a[0][1],a[1][1],b[1][0],b[1][1],q);
    r = (a[0][0]-a[1][1])*(b[0][0]+b[1][1]);
    printf("\n(%d-%d)*(%d+%d)==>%d",a[0][0],a[1][1],b[0][0],b[1][1],r);
    s = (a[0][0])*(b[0][1]-b[1][1]);
    printf("\n(%d)*(%d-%d)==>%d",a[0][0],b[0][1],b[1][1],s);
    t = (a[1][0]+a[1][1])*(b[0][0]);
    printf("\n(%d+%d)*(%d)==>%d",a[1][0],a[1][1],b[0][0],t);
    u = (a[0][0]+a[0][1])*(b[1][1]);
    printf("\n(%d+%d)*(%d)==>%d",a[0][0],a[0][1],b[1][1],u);
    v = (a[1][1])*(b[1][0]-b[0][0]);
    printf("\n(%d)*(%d-%d)==>%d",a[1][1],b[1][0],b[0][0],v);
    nom+=7;    noa+=10;

    c[0][0]=q+r-u-v;
    printf("\n(%d+%d-%d-%d)==>%d",q,r,u,v,c[0][0]);

    c[0][1]=s+u;
    printf("\n(%d+%d)==>%d",s,u,c[0][1]);

    c[1][0]=t+v;
    printf("\n(%d+%d)==>%d",t,v,c[1][0]);

    c[1][1]=p-r-s-t;
    printf("\n(%d-%d-%d-%d)==>%d",p,r,s,t,c[1][1]);


    noa+=8;
    }
  return nom;
}

int main()
{  int i,j,n,nm;
   int m3[8][8],m1[8][8],m2[8][8];

    n=2;
   for(i=0;i<max;i++)   for(j=0;j<max;j++)
   { m1[i][j]=0; m2[i][j]=0;m3[i][j]=0;}

   printf("Enter the Elements of Matrix 1\n");
   for(i=0;i<n;i++)    for(j=0;j<n;j++)      scanf("%d",&m1[i][j]);

   printf("Enter the Elements of Matrix 2\n");
   for(i=0;i<n;i++)  for(j=0;j<n;j++)       scanf("%d",&m2[i][j]);

   nm=smm(m1,m2,m3,n);

   printf("\nNo. of Mult.s :%d \n",nm);
   printf("\nProd:\n");
   for(i=0;i<n;i++)
    { printf("\n");
      for(j=0;j<n;j++)  printf("%5d",m3[i][j]);
    }
    getch();
    return 0;
}
