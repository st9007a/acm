#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Position {
    int x;
    int y;
};

Position p[201];
double dis[201][201];

int main()
{
    int num, cases = 0;

    while (scanf("%d", &num)) {
        if (num == 0) {
            break;
        }

        for (int i = 0; i < num; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
        }

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                dis[i][j] = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
            }
        }

        for (int k = 0; k < num; k++) {
            for (int i = 0; i < num; i++) {
                for (int j = 0; j < num; j++) {
                    dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
                }
            }
        }

        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++cases, dis[0][1]);

    }
}
