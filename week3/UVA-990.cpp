#include <cstdio>
#include <vector>

using namespace std;

int d[31], v[31];

int main()
{
    int t, w, n;
    bool flag = false;

    while (scanf("%d %d %d", &t, &w, &n) != EOF) {
        if (!flag) {
            flag = true;
        } else {
            printf("\n");
        }

        int dp[1001] = {0};
        bool get[31][1001] = {0};

        for (int i = 0; i < n; i++) {
            scanf("%d %d", d + i, v + i);
        }

        for (int i = 0; i < n; i++) {
            int need = d[i] * 3 * w;
            for (int j = t; j >= need; j--) {
                if (dp[j] < dp[j - need] + v[i]) {
                    dp[j] = dp[j - need] + v[i];
                    get[i][j] = true;
                }
            }
        }

        vector<int> ans;
        for (int i = n - 1, j = t; i >= 0; i--) {
            if (get[i][j]) {
                ans.push_back(i);
                j -= d[i] * 3 * w;
            }
        }

        printf("%d\n%d\n", dp[t], ans.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            printf("%d %d\n", d[ans[i]], v[ans[i]]);
        }

    }
}
