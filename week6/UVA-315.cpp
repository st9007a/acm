#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<int> edge[105];
int dfn[105];
int low[105];
int dfsn;
int ans;

void dfs(int cur, int prev);

int main()
{
    int n;
    string line;

    while (scanf("%d", &n) && n) {
        ans = 0;
        dfsn = 0;

        for (int i = 0; i <= n; i++) {
            dfn[i] = 0;
            low[i] = 0;
            edge[i].clear();
        }

        int from, to;

        getline(cin, line);
        while (getline(cin, line)) {
            stringstream ss(line);
            ss >> from;

            if (!from) {
                break;
            }

            while (ss >> to) {
                edge[from].push_back(to);
                edge[to].push_back(from);
            }
        }

        dfs(1, -1);

        printf("%d\n", ans);
    }
}

void dfs(int cur, int prev)
{
    bool cut = false;
    int child = 0;

    low[cur] = dfn[cur] = ++dfsn;

    for (int i = 0; i < edge[cur].size(); i++) {
        int next = edge[cur][i];

        if (!dfn[next]) {
            dfs(next, cur);

            low[cur] = min(low[cur], low[next]);

            if (low[next] >= dfn[cur]) {
                cut = true;
            }
            ++child;
        } else if (next != prev) {
            low[cur] = min(low[cur], dfn[next]);
        }
    }

    if ((child > 1 || prev != -1) && cut) {
        ++ans;
    }
}
