#include <algorithm>
#include <cstdio>

using namespace std;

int dis[102][102];

void Floyd(int c);

int main()
{
    int c, s, q;
    int a, b, w;
    int cases = 1;
    int start, end;

    while (scanf("%d %d %d", &c, &s, &q) && (c || s || q)) {
        if (cases != 1) {
            printf("\n");
        }
        printf("Case #%d\n", cases++);

        for (int i = 1; i <= c; i++) {
            for (int j = 1; j <= c; j++) {
                dis[i][j] = 99999999;
            }

            dis[i][i] = 0;
        }

        for (int i = 1; i <= s; i++) {
            scanf("%d %d %d", &a, &b, &w);
            dis[a][b] = w;
            dis[b][a] = w;
        }

        Floyd(c);

        for (int i = 0; i < q; i++) {
            scanf("%d %d", &start, &end);

            if (dis[start][end] == 99999999) {
                printf("no path\n");
            } else {
                printf("%d\n", dis[start][end]);
            }

        }
    }
}

void Floyd(int c) {
    for (int k = 1; k <= c; k++) {
        for (int i = 1; i <= c; i++) {
            for (int j = 1; j <= c; j++) {
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
            }
        }
    }
}
