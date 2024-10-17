#include <stdio.h>

int c[7][7], w[7][7], r[7][7];
int p[7] = {0, 3, 3, 1, 1, 2};  // probabilities of successful searches (keys)
int q[7] = {2, 3, 1, 1, 1, 1};  // probabilities of unsuccessful searches

void obst(int n) {
    int i, j, k, min, mr, s;

    // Initialize weight, cost, and root arrays
    for (s = 0; s <= n; s++) {
        for (i = 0; (i + s) <= n; i++) {
            j = i + s;
            w[i][j] = q[i];

            // Calculate weight matrix
            for (k = i + 1; k <= j; k++) {
                w[i][j] += q[k] + p[k];
            }

            // Initialize minimum cost and root
            min = 10000;  // Large value to simulate infinity
            mr = 0;

            // Find minimum cost and corresponding root
            for (k = i + 1; k <= j; k++) {
                if (min > (c[i][k - 1] + c[k][j])) {
                    min = c[i][k - 1] + c[k][j];
                    mr = k;
                }
            }

            // Update cost and root arrays
            if (j > i) {
                c[i][j] = min + w[i][j];
                r[i][j] = mr;
            }
        }
    }
}

int main() {
    int n = 7, i, j; // number change form here

    // Initialize cost, weight, and root matrices to zero
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            w[i][j] = 0;
            c[i][j] = 0;
            r[i][j] = 0;
        }
    }

    // Call the OBST function
    obst(n);

    // Output the cost and root of the optimal binary search tree
    printf("\nCost of OBST = %d", c[0][n]);
    printf("\nRoot of OBST = %d\n", r[0][n]);

    return 0;
}