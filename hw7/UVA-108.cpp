#include <cstdio>

int dp[101][101];

int main()
{
    int n;
    int maxSum = -9999999;

    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    int tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &tmp);

            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + tmp;
        }
    }

    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= n; y2++) {
                    int sum = dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1];

                    if (sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }
        }
    }

    printf("%d\n", maxSum);

}
