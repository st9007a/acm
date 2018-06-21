#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edge[2002];
vector<int> tmp;
int dfn[2002];
int low[2002];
int dfsn;
int ans;

void Tarjan(int v);

int main()
{
    int n, m;

    while (scanf("%d %d", &n, &m) && (n || m)) {
        ans = 0;
        dfsn = 0;
        tmp.clear();

        for (int i = 0; i <= n; i++) {
            dfn[i] = 0;
            low[i] = 0;
            edge[i].clear();
        }

        int v, w, p;

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &v, &w, &p);
            edge[v].push_back(w);

            if (p == 2) {
                edge[w].push_back(v);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!dfn[i] && ans <= 1) {
                Tarjan(i);
            }
        }

        if (ans == 1) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}

void Tarjan(int v)
{
    dfn[v] = low[v] = ++dfsn;
    tmp.push_back(v);

    for (int i = 0; i < edge[v].size(); i++) {
        int next = edge[v][i];
        if (!dfn[next]) {
            Tarjan(next);
            low[v] = min(low[v], low[next]);
        } else if (find(tmp.begin(), tmp.end(), next) != tmp.end()) {
            low[v] = min(low[v], dfn[next]);
        }
    }

    if (dfn[v] == low[v]) {
        ans++;
        int top;
        do {
            top = tmp.back();
            tmp.pop_back();
        } while (v != top);
    }
}
