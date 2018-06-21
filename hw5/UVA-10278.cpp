#include <cstdio>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

int pos[101];
int dis[501][501];

void Floyd(int n);

int main()
{
    int cases;
    int f, inter;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d %d", &f, &inter);

        for (int i = 0; i < f; i++) {
            scanf("%d", pos + i);
        }

        for (int i = 1; i <= inter; i++) {
            for (int j = 1; j <= inter; j++) {
                dis[i][j] = 99999999;
            }
            dis[i][i] = 0;
        }

        int a, b, l;
        string str;

        getline(cin, str);

        while (getline(cin, str) && !str.empty()) {
            stringstream ss(str);
            ss >> a >> b >> l;

            dis[a][b] = l;
            dis[b][a] = l;
        }

        Floyd(inter);

        int s[501];
        int maxS = 0;

        for (int i = 1; i <= inter; i++) {
            s[i] = 99999999;

            for (int j = 0; j < f; j++) {
                s[i] = min(s[i], dis[i][pos[j]]);
            }

            maxS = max(maxS, s[i]);
        }

        int ans = 1;

        for (int i = 1; i <= inter; i++) {
            int newL = 0;

            for (int j = 1; j <= inter; j++) {
                newL = max(newL, min(dis[i][j], s[j]));
            }

            if (newL < maxS) {
                maxS = newL;
                ans = i;
            }
        }

        printf("%d\n", ans);
        if (cases) {
            printf("\n");
        }

    }
}

void Floyd(int n)
{
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}
