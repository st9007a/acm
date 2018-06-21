#include <cstdio>
#include <algorithm>

using namespace std;

int ans[21];
int order[21];
int lcs[21][21] = {0};

int main()
{
    int n, pos;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &pos);
        ans[pos] = i;
    }

    while (scanf("%d", &pos) != EOF) {
        order[pos] = 1;

        for (int i = 2; i < n + 1; i++) {
            scanf("%d", &pos);
            order[pos] = i;
        }

        int score = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ans[i] == order[j]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }

                if (lcs[i][j] > score) {
                    score = lcs[i][j];
                }
            }
        }

        printf("%d\n", score);

    }

}
