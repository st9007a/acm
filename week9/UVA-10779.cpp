#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int cap[40][40];
int flow[40][40];
int bottleneck[40];
int pre[40];

int main()
{
    int t, n, m, k;
    int cases = 1;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        int sink = n + m + 1;

        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        for (int i = 1; i <= n; i++) {
            scanf("%d", &k);
            int ki;

            for (int j = 1; j <= k; j++) {
                scanf("%d", &ki);
                cap[i][n + ki]++;
            }
        }

        for (int i = 2; i <= n; i++) {
            for (int j = n + 1; j <= m + n; j++) {
                if (cap[i][j]) {
                    cap[i][j]--;
                } else {
                    cap[j][i] = 1;
                }
            }
        }

        for (int i = n + 1; i <= m + n; i++) {
            cap[i][sink] = 1;
        }

        int res = 0;

        while (true) {
            memset(bottleneck, 0, sizeof(bottleneck));

            queue<int> q;
            q.push(1);

            bottleneck[1] = 1e9;

            while(!q.empty() && !bottleneck[sink]) {
                int curr = q.front();
                q.pop();

                for (int next = 1; next <= sink; next++) {
                    if (bottleneck[next] == 0 && cap[curr][next] > flow[curr][next]) {
                        q.push(next);
                        pre[next] = curr;
                        bottleneck[next] = min(bottleneck[curr], cap[curr][next] - flow[curr][next]);
                    }
                }
            }

            if (bottleneck[sink] == 0) {
                break;
            }

            for (int curr = sink; curr != 1; curr = pre[curr]) {
                flow[pre[curr]][curr] += bottleneck[sink];
                flow[curr][pre[curr]] -= bottleneck[sink];
            }

            res += bottleneck[sink];
        }

        printf("Case #%d: %d\n", cases++, res);
    }
}
