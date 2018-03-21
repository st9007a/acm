#include <cstdio>

long dp[7500] = {0};

int main()
{
    int coins[5] = {1, 5, 10, 25, 50};
    int cents;

    for (int i = 0; i < 7500; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 7500; j++) {
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    while (scanf("%d", &cents) != EOF) {
        printf("%ld\n", dp[cents]);
    }
}
