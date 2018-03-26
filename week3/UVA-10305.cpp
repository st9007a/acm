#include <cstdio>
#include <vector>

using namespace std;

int ans[101];
int relation[101][101];
int in[101];
int n, m;

void topo();

int main()
{

    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < 101; i++) {
            in[i] = 0;
            ans[i] = 0;

            for (int j = 0; j < 101; j++) {
                relation[i][j] = 0;
            }
        }

        int k, l;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &k, &l);

            if (relation[k][l] == 0) {
                relation[k][l] = 1;
                in[l]++;
            }
        }

        topo();

        for(int i = 1; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[n]);
    }
}

void topo()
{
    for (int i = 1; i <= n; i++) {
        int k = 1;

        while (in[k]) {
            k++;
        }

        ans[i] = k;
        in[k] = -1;

        for (int j = 1; j <= n; j++) {
            if (relation[k][j]) {
                in[j]--;
            }
        }
    }
}
