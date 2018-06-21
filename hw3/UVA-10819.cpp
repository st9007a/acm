#include <cstdio>

int price[110], favour[110];

int main()
{
    int m, n;

    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d", price + i, favour + i);
        }

        int dp[10202] = {0};

        if (m > 1800) {
            m += 200;
        }

        for (int i = 0; i < n; i++) {
            for (int j = m; j >= price[i]; j--) {
                if (dp[j] < dp[j - price[i]] + favour[i]) {
                    dp[j] = dp[j - price[i]] + favour[i];
                }
            }
        }

        int idx = m;
        while (idx > 0 && dp[idx] == dp[idx - 1]) {
            idx--;
        }

        if (idx <= 2000 && m > 2000) {
            printf("%d\n", dp[m - 200]);
        } else {
            printf("%d\n", dp[m]);
        }
    }
}
