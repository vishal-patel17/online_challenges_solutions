/*  Task

Write a program which for each data set from a sequence of several data sets:

    reads integers n and k from input,
    computes the number of n-element permutations with exactly k inversions,
    writes the result to output.


 Input
The first line of the input file contains one integer d, 1<=d<=10, which is the number of data sets. The data sets follow. Each data set occupies one line of the input file and contains two integers n (1<=n<=12) and k (0<=k<=98) separated by a single space.

 Output
The i-th line of the output file should contain one integer - the number of n-element permutations with exactly k inversions.
Example

Sample input:
1
4 1

Sample output:
3
 */


#include <stdio.h>

int dp[100][100];

int inversions(int n, int k)
{
    if (dp[n][k] != -1) return dp[n][k];
    if (k == 0) return dp[n][k] = 1;
    if (n == 0) return dp[n][k] = 0;
    int j = 0, val = 0;
    for (j = 0; j < n && k-j >= 0; j++)
        val += inversions(n-1, k-j);
    return dp[n][k] = val;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, i, j;
        scanf("%d%d", &n, &k);
        for (i = 1; i <= n; i++)
            for (j = 0; j <= k; j++)
                dp[i][j] = -1;
        printf("%d\n", inversions(n, k));
    }
    return 0;
}