#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> strToNum;
string numToStr[30];

vector<int> edge[30];
vector<int> scc[30];
vector<int> tmp;
int dfn[30];
int low[30];
bool inStack[30];
int dfsn;
int ans;

void Tarjan(int v);

int main()
{
    int n, m;
    int cases = 1;

    while (cin >> n >> m && (n || m)) {

        ans = 0;
        dfsn = 0;
        tmp.clear();
        strToNum.clear();

        for (int i = 0; i <= n; i++) {
            edge[i].clear();
            scc[i].clear();
            dfn[i] = 0;
            low[i] = 0;
            inStack[i] = false;
        }

        string from, to;

        for (int i = 0, idx = 1; i < m; i++) {
            cin >> from >> to;

            if (!strToNum[from]) {
                strToNum[from] = idx;
                numToStr[idx++] = from;
            }

            if (!strToNum[to]) {
                strToNum[to] = idx;
                numToStr[idx++] = to;
            }

            edge[strToNum[from]].push_back(strToNum[to]);
        }

        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                Tarjan(i);
            }
        }

        if (cases != 1) {
            cout << endl;
        }

        cout << "Calling circles for data set " << cases++ << ":" << endl;
        for (int i = 0; i < ans; i++) {
            for (int j = 0; j < scc[i].size() - 1; j++) {
                cout << numToStr[scc[i][j]] << ", ";
            }
            cout << numToStr[scc[i].back()] << endl;
        }
    }
}

void Tarjan(int v)
{
    dfn[v] = low[v] = ++dfsn;
    tmp.push_back(v);
    inStack[v] = true;

    for (int i = 0; i < edge[v].size(); i++) {
        int next = edge[v][i];

        if (!dfn[next]) {
            Tarjan(next);
            low[v] = min(low[v], low[next]);
        } else if (inStack[next]) {
            low[v] = min(low[v], dfn[next]);
        }
    }

    if (dfn[v] == low[v]) {
        int top;
        do {
            top = tmp.back();
            scc[ans].push_back(top);
            tmp.pop_back();
            inStack[top] = false;
        } while (top != v);
        ans++;
    }
}
