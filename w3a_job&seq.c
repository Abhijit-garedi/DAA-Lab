//prisms
#include <stdio.h>
#include <limits.h>

#define vertices 7  /*Define the number of vertices in the graph*/

int nearest(int k[], int mst[])
{
  int minimum  = INT_MAX, min,i;
    for (i = 0; i < vertices; i++)
	if (mst[i] == 0 && k[i] < minimum )
	    minimum = k[i], min = i;
    return min;
}
void prim(int g[vertices][vertices])
{
    int par[vertices];
    int k[vertices];
    int mst[vertices];
    int i, count,u,v; /*Here 'v' is the vertex*/
    for (i = 0; i < vertices; i++)
    {	k[i] = INT_MAX;
	mst[i] = 0;
    }
    //mst[0]=1;
    k[0] = 0;
    par[0] = -1;
    for (count = 0; count < vertices; count++)
    {   u = nearest(k, mst);
	mst[u] = 1;
	for (v = 0; v < vertices; v++)
	{
	    if (g[u][v] && mst[v] == 0 &&
		 g[u][v] <  k[v]   )
	    {
		par[v]  = u;
		k[v] = g[u][v];
	    }
	}
	if(par[u]>-1)
	 printf("(%d--%d),",par[u],u);


     }
     /*Print the constructed Minimum spanning tree*/
     printf("\n Edge \t  Weight\n");
     for (i = 1; i < vertices; i++)
     printf(" %d <-> %d    %d \n", par[i], i, g[i][par[i]]);

}
int main()
{
   int i,j,n,e,g[vertices][vertices];
   int s,d,w;
	   /* = {
	      { 0,14, 0, 0, 0, 0, 0, 8, 0},
	      {14, 0,12, 0, 0, 0, 0, 1, 0},
	      { 0,12, 0, 3, 0, 5, 0, 0,13},
	      { 0, 0, 3, 0, 9, 4, 0, 0, 0},
	      { 0, 0, 0, 9, 0,10, 0, 0, 0},
	      { 0, 0, 5, 4,10, 0, 2, 0, 0},
	      { 0, 0, 0, 0, 0, 2, 0,11, 6},
	      { 8, 1, 0, 0, 0, 0,11, 0, 7},
	      { 0, 0,13, 0, 0, 0, 6, 7, 0} };*/

    clrscr();
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
    { g[i][j]=0;
    }

    printf("Enter no. of vertices");  scanf("%d",&n);
    printf("Enter no. of Edges");  scanf("%d",&e);
    printf("Enter S   D   W. of Edges\n");
    for(i=0;i<e;i++)
    { printf("e%d) ",i+1);  scanf("%d %d%d",&s,&d,&w);
      g[s][d]=w; g[d][s]=w;
    }


    prim(g);
    return 0;
}