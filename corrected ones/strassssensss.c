#include <stdio.h>

#define max 8

int smm(int a[max][max], int b[max][max], int c[max][max], int rw) {
    static int noa = 0, nom = 0;
    int p, q, r, s, t, u, v;

    if (rw == 2) {
        // Step-by-step Strassen's algorithm for 2x2 matrix multiplication
        p = (a[0][0] + a[1][0]) * (b[0][0] + b[0][1]);
        printf("\n(%d + %d) * (%d + %d) ==> %d", a[0][0], a[1][0], b[0][0], b[0][1], p);
        
        q = (a[0][1] + a[1][1]) * (b[1][0] + b[1][1]);
        printf("\n(%d + %d) * (%d + %d) ==> %d", a[0][1], a[1][1], b[1][0], b[1][1], q);
        
        r = (a[0][0] - a[1][1]) * (b[0][0] + b[1][1]);
        printf("\n(%d - %d) * (%d + %d) ==> %d", a[0][0], a[1][1], b[0][0], b[1][1], r);
        
        s = a[0][0] * (b[0][1] - b[1][1]);
        printf("\n%d * (%d - %d) ==> %d", a[0][0], b[0][1], b[1][1], s);
        
        t = (a[1][0] + a[1][1]) * b[0][0];
        printf("\n(%d + %d) * %d ==> %d", a[1][0], a[1][1], b[0][0], t);
        
        u = (a[0][0] + a[0][1]) * b[1][1];
        printf("\n(%d + %d) * %d ==> %d", a[0][0], a[0][1], b[1][1], u);
        
        v = a[1][1] * (b[1][0] - b[0][0]);
        printf("\n%d * (%d - %d) ==> %d", a[1][1], b[1][0], b[0][0], v);

        nom += 7; // 7 multiplications

        // Fill the result matrix `c` using Strassen's formula
        c[0][0] = q + r - u - v;
        printf("\n(%d + %d - %d - %d) ==> %d", q, r, u, v, c[0][0]);

        c[0][1] = s + u;
        printf("\n(%d + %d) ==> %d", s, u, c[0][1]);

        c[1][0] = t + v;
        printf("\n(%d + %d) ==> %d", t, v, c[1][0]);

        c[1][1] = p - r - s - t;
        printf("\n(%d - %d - %d - %d) ==> %d", p, r, s, t, c[1][1]);

        noa += 8; // 8 additions
    }

    return nom; // Return the number of multiplications
}

int main() {
    int i, j, n, nm;
    int m1[max][max], m2[max][max], m3[max][max];

    n = 2; // Fixed size 2x2 matrices

    // Initialize matrices with zeros
    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) {
            m1[i][j] = 0;
            m2[i][j] = 0;
            m3[i][j] = 0;
        }
    }

    // Input elements of Matrix 1
    printf("Enter the elements of Matrix 1 (2x2):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    // Input elements of Matrix 2
    printf("Enter the elements of Matrix 2 (2x2):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    // Perform Strassen's matrix multiplication
    nm = smm(m1, m2, m3, n);

    // Output the number of multiplications and the resulting matrix
    printf("\nNumber of Multiplications: %d\n", nm);
    printf("\nProduct Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++) {
            printf("%5d", m3[i][j]);
        }
    }

    return 0;
}