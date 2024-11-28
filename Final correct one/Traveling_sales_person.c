#include <stdio.h>
#define Max 5
int N=5;
int best_path[Max];
int vis[Max];

int final_res = 10000;

void show(int a[Max][Max])
{   int i,j;
    for(i=0;i<N;i++)
     { 
        printf("\n");
       for(j=0;j<N;j++)
	printf("%5d",a[i][j]);
      }
}

int reduct(int a[Max][Max])
 {  int i,j,k;
    int rv,min[Max];
    rv=0;
    for(i=0;i<N;i++)
     { min[i]=10000;
       for(j=0;j<N;j++)
	  if(min[i]>a[i][j])
	      min[i]=a[i][j];
       if(min[i]>900)
	 min[i]=0;
       rv+=min[i];
       if(min[i]>0 && min[i]<900)
	for(j=0;j<N;j++)
	 a[i][j]-=min[i];
      }
    for(i=0;i<N;i++)
     { min[i]=10000;
       for(j=0;j<N;j++)
	  if(min[i]>a[j][i])
	      min[i]=a[j][i];
       if(min[i]>900)
	 min[i]=0;
       rv+=min[i];
       for(j=0;j<N;j++)
	a[j][i]-=min[i];
      }

 return rv;
}


int TSP(int adj[Max][Max], int v,int s,int r)
{
    int i,j,l,k,min[Max];
    static int bp=1;
    int tadj[Max][Max],vt,vx,bc;
    int bst[Max][Max],b=1000;
    printf("\n%2d %7d",s,v);
    show(adj);
    for(k=0;k<N;k++)
    { if(vis[k]>0)   continue;
      for(i=0;i<N;i++)
       for(j=0;j<N;j++)
	tadj[i][j]=adj[i][j];
      for(i=0;i<N;i++)
      { tadj[s][i]=1000;
	tadj[i][k]=1000;
       }
      tadj[k][s]=1000;
      printf("\n %c",k+65);
      show(tadj);
      vx=reduct(tadj);
      show(tadj);
      printf("\n %d %d %d",vx,v,adj[s][k]);
      vx+=v+adj[s][k];
      printf(" %d ",vx);
      
      if(vx<b)
       {for(i=0;i<N;i++)
	  for(j=0;j<N;j++)
	    bst[i][j]=tadj[i][j];
	b=vx;
	bc=k;
       }

    }
    vis[bc]=1;
    best_path[bp]=bc;
    bp++;
//    getch();
    if(r<N-1)
       TSP(bst,b,bc,r+1);
     else
      return b;

}

// Driver code
int main()
{    int i,j,vt;
    //Adjacency matrix for the given graph
/*    int adj[Max][Max] = { {0, 10, 15, 20},
			  {10, 0, 35, 25},
			  {15, 35, 0, 30},
			  {20, 25, 30, 0}
			 };
  */
/*      int adj[Max][Max] = { {1000, 20, 30, 10,  11},
			    {15, 1000, 16,  4,   2},
			    {3,  5,  1000,  2,   4},
			    {19, 6, 18,  1000,   3},
			    {16, 4,  7, 16,   1000},
			 };
  */
      int adj[Max][Max] = { {1000, 7, 3, 12,  8},
			    {3, 1000, 6, 14,  9},
			    {5,  8,  1000,  6,  18},
			    {9, 3, 5,  1000,  11},
			    {18,14,  9, 8,   1000},
			 };

    N=5;
    
    for (i=0; i<=N; i++)
     vis[i]=0;
    vis[0]=1;
    best_path[0]=0;
    for(i=0;i<N;i++)
     { printf("\n");
       for(j=0;j<N;j++)
	printf("%5d",adj[i][j]);
      }
    vt=reduct(adj);

    vt = TSP(adj,vt,0,1);

    printf("\n Minimum cost : %d\n", vt);
    for(i=0;i<N;i++)
      printf(" %c -->",best_path[i]+65);
    printf(" %c ",best_path[0]+65);
   
    return 0;
}