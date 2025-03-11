#include <stdio.h>
#include <string.h>

int i, j, m, n, lcs_table[20][20];
char s1[20] = "abababa", s2[20] = "babba", b[20][20];

void LCSAlgo() {
    m = strlen(s1);
    n = strlen(s2);

    for (i = 0; i <= m; i++)
        lcs_table[i][0] = 0;

    for (j = 0; j <= n; j++)
        lcs_table[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
            } else if (lcs_table[i - 1][j] >= lcs_table[i][j - 1]) {
                lcs_table[i][j] = lcs_table[i - 1][j];
            } else {
                lcs_table[i][j] = lcs_table[i][j - 1];
            }
        }
    }

    int index = lcs_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcsAlgo[index - 1] = s1[i - 1];
            index--;
            i--;
            j--;
        } else if (lcs_table[i - 1][j] > lcs_table[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("S1: %s\nS2: %s\n", s1, s2);
    printf("LCS: %s\n", lcsAlgo);
}

void main() {
    LCSAlgo();
    printf("\n");
}