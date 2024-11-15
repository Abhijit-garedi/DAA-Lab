#include <stdio.h>
#define MAX 15

int a[MAX][MAX] = { // 0 1 2 3 4 5 6 7 8 9
    {0,1,1,0,0,0,0,0,0,0}, // 0
    {1,0,1,0,0,0,0,0,0,0}, // 1
    {1,1,0,1,1,0,0,0,0,0}, // 2
    {0,0,1,0,1,0,0,0,0,0}, // 3
    {0,0,1,1,0,0,1,1,0,0}, // 4
    {0,0,0,0,0,0,1,0,1,0}, // 5
    {0,0,0,0,1,1,0,1,1,0}, // 6
    {0,0,0,0,1,0,1,0,0,0}, // 7
    {0,0,0,0,0,1,1,0,0,0}, // 8
    {0,0,1,0,0,0,0,0,0,0}, // 9
};
int par[MAX], ch[MAX][MAX], vis[MAX], dfn[MAX], lp[MAX], ap[MAX];
int n = 10; // Set this to the actual number of nodes in the adjacency matrix

// Initialization of the DFS depth counter
int c = 0;

void prop(int p, int m) {
    if (p < 0) return;
    if (m < lp[p]) lp[p] = m;
    prop(par[p], m);
}

int lv(int u) {
    int v, min;
    lp[u] = dfn[u];
    min = 100;
    for (v = 0; v < n; v++) {
        if (a[u][v] == 1 && par[u] != v) {
            if (dfn[v] < min) min = dfn[v];
        }
    }
    if (min > dfn[u]) min = dfn[u];
    prop(par[u], min);
    return min;
}

void dfs(int u) {
    int i, v;
    c++; // Increment global depth counter
    vis[c] = u; // Mark the node as visited in the dfs order
    printf("%4d", u);
    dfn[u] = c; // Set discovery time for `u`
    for (i = 0; i < n; i++) {
        if (dfn[i] < 0 && a[u][i] != 0) { // If `i` is not visited
            par[i] = u;                  // Set parent of `i` as `u`
            ch[u][0]++;                  // Count children for articulation
            ch[u][ch[u][0]] = i;
            dfs(i); // Recursively visit
        }
    }
}

int main() {
    int i, j, x, noap = 0;

    // Initialize arrays
    for (i = 0; i < n; i++) {
        dfn[i] = -1;
        ch[i][0] = 0;
        par[i] = -1;
        vis[i] = -1;
        ap[i] = 0;
    }

    // Call DFS Algorithm
    dfs(0);

    // Check if root node is an articulation point
    x = vis[1];
    if (ch[x][0] > 1)
        ap[x] = 1;

    // Finding DFN and Low values of nodes
    for (i = 0; i < n; i++)
        lp[i] = dfn[i];
    for (i = 1; i <= c; i++) {
        x = vis[i];
        lp[x] = lv(x);
    }

    // Determine any articulation point
    for (i = 0; i < n; i++) {
        if (vis[1] != i) {
            for (j = 1; j <= ch[i][0]; j++) {
                x = ch[i][j];
                if (dfn[i] <= lp[x]) {
                    ap[i] = 1;
                    noap++;
                }
            }
        }
    }

    // Output results
    if (noap == 0)
        printf("\nNo Articulation Points in the Graph");
    else
        for (i = 0; i < n; i++)
            if (ap[i] == 1)
                printf("\n%d is an Articulation Point", i);

    return 0;
}
