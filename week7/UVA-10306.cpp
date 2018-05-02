#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define INF 99999999

using namespace std;

struct Point {
    int x;
    int y;
};

vector<Point> ans;
int dp[302][302];

int main()
{
    int n;
    int m, s;

    scanf("%d", &n);

    while (n--) {
        scanf("%d %d", &m, &s);
        ans.clear();

        for (int i = 0; i <= s; i++) {
            for (int j = 0; j <= s; j++) {
                if (sqrt(pow(i, 2) + pow(j, 2)) == s) {
                    Point p = {i, j};
                    ans.push_back(p);
                }

                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;

        int x, y;

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);

            for (int i = x; i <= s; i++) {
                for (int j = y; j <= s; j++) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - y] + 1);
                }
            }
        }

        int count = INF;

        for (Point p : ans) {
            if (dp[p.x][p.y] < count) {
                count = dp[p.x][p.y];
            }
        }

        if (count == INF) {
            printf("not possible\n");
        } else {
            printf("%d\n", count);
        }
    }
}
