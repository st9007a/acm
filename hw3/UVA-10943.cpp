#include <cstdio>

int main()
{
    int n, k;
    int dp[201][201] = {0};
    dp[0][0] = 1;

    for (int i = 1; i <= 200; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000;
        }
    }

    while (scanf("%d %d", &n, &k)) {
        if (n == 0 && k == 0) {
            break;
        }
        printf("%d\n", dp[n + k - 1][k - 1]);
    }
}
