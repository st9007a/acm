#include <cstdio>
#include <queue>

using namespace std;

int energy[101];
int path[101][101];

bool SPFA(int n);

int main()
{
    int n;

    while (scanf("%d", &n) && n != -1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &energy[i], &path[i][0]);
            for (int j = 1; j <= path[i][0]; j++) {
                scanf("%d", &path[i][j]);
            }
        }
        if (SPFA(n)) {
            printf("winnable\n");
        } else {
            printf("hopeless\n");
        }
    }
}

bool SPFA(int n)
{
    queue<int> q;
    bool inQueue[101] = {false};
    int dis[101] = {0};

    int count = 0;

    dis[1] = 100;
    inQueue[1] = true;
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        inQueue[curr] = false;
        q.pop();

        for (int i = 1; i <= path[curr][0]; i++) {
            int next = path[curr][i];
            int tmp = dis[curr] + energy[next];

            if (tmp > dis[next]) {
                dis[next] = tmp;

                if (!inQueue[next]) {
                    q.push(next);
                    inQueue[next] = true;
                    ++count;
                }
            }
        }

        if (dis[n] > 0) {
            return true;
        }

        if (count > 1e6) {
            return false;
        }
    }

    return false;
}
