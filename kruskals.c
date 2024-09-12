// Kruskal's algorithm in C

#include <stdio.h>

#define MAX 30

typedef struct edge {  int u, v, w; } edge;

typedef struct edge_list {  edge data[MAX];  int n; } edge_list;

edge_list elist;   edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2, int n);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo(int g[MAX][MAX],int n) {
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) {
      if (g[i][j] != 0) {
	elist.data[elist.n].u = i;
	elist.data[elist.n].v = j;
	elist.data[elist.n].w = g[i][j];
	elist.n++;
      }
    }

  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2,n);
    }
  }
}

int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2,int n) {
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

// Sorting algo
void sort() {
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
	temp = elist.data[j];
	elist.data[j] = elist.data[j + 1];
	elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

int main()
{ int n,g[MAX][MAX];
            /*=
	      {{ 0,14, 0, 0, 0, 0, 0, 8, 0},
	      {14, 0,12, 0, 0, 0, 0, 1, 0},
	      { 0,12, 0, 3, 0, 5, 0, 0,13},
	      { 0, 0, 3, 0, 9, 4, 0, 0, 0},
	      { 0, 0, 0, 9, 0,10, 0, 0, 0},
	      { 0, 0, 5, 4,10, 0, 2, 0, 0},
	      { 0, 0, 0, 0, 0, 2, 0,11, 6},
	      { 8, 1, 0, 0, 0, 0,11, 0, 7},
	      { 0, 0,13, 0, 0, 0, 6, 7, 0} };

  n = 9;*/
  int i, j, total_cost;



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

  kruskalAlgo(g,n);
  print();
}