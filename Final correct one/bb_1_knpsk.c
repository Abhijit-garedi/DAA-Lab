// 0/1 knapsack using branch and bound
#include<stdio.h>
#define Max 30
typedef struct { double w;   double p;} Item;
typedef struct { int level;double lb,ub,p,w;int code;}  Node;

Node Q[Max],u, v;
int fr=-1,rr=-1;

double ub(Node y, int n, double W, Item arr[])
{   double profit_ub = y.p;
    int j = y.level + 1;
    double totweight;
    totweight = y.w;
    if (y.w >= W)      return 0;
    while ((j < n) && (totweight + arr[j].w <= W))
    { totweight += arr[j].w;
      profit_ub += arr[j].p;
      j++;
     }
    y.lb=profit_ub;
    if (j < n)
      profit_ub += (W - totweight) * arr[j].p / arr[j].w;
    y.ub=profit_ub;
    printf("(%3.0f,%3.0f) %d\n",y.lb,y.ub,y.code);
    return profit_ub;
}

Node del(Node q[])
{  Node x;
   x=q[fr];
   fr++;
   if(fr>rr)
    {fr=-1;rr=-1;}   return x;
}

void add(Node q[], Node x)
{  if(fr<0)  fr++;   rr++;   q[rr]=x;
}

int empty(Node q[])
{  if(fr<0) return 1; else   return 0;}

double knapsack(double W, Item arr[], int n)
{  double maxProfit = 0;
    u.level = -1;
    u.p = u.w = 0.0; u.code=0;
    v.p=0;v.lb=0;
    v.ub=0;v.level=-1;v.code=0;

    add(Q,u);
    while (!empty(Q))
    {	u = del(Q);
	if (u.level == -1)	   v.level = 0;
	if (u.level == n-1)	   continue;
	v.level = u.level + 1;
	v.code=2*u.code+1;
	v.w = u.w + arr[v.level].w;
	v.p = u.p + arr[v.level].p;
	if (v.w <= W && v.p > maxProfit)
	    maxProfit = v.p;
	v.ub = ub(v, n, W, arr);
	if (v.ub > maxProfit)
	  add(Q,v);
	v.w = u.w;	v.p = u.p;
	v.code=2*u.code;
	v.ub = ub(v, n, W, arr);
	if (v.ub > maxProfit)
	  add(Q,v);
    }
    return maxProfit;
}

int main()
{   double W=15;
    Item arr[] = {{2.0,10.0}, {4.0, 10.0}, {6.0,12.0},{9.0, 18.0}};
    int n = sizeof(arr) / sizeof(arr[0]);
   
    printf(" \n\nMaximum possible profit = %6.1f ",knapsack(W, arr, n));
  
    return 0;
}
