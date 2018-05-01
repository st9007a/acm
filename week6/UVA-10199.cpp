#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

map<string, int> strToNum;
string numToStr[102];

vector<int> edge[102];
int dfn[102];
int low[102];
int dfsn;
set<string> ans;

void dfs(int cur, int prev);

int main()
{
    int n, r;
    int cases = 1;

    while (cin >> n && n) {
        for (int i = 0; i <= n; i++) {
            dfn[i] = low[i] = 0;
            edge[i].clear();
        }
        dfsn = 0;
        strToNum.clear();
        ans.clear();


        string a, b;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            strToNum[a] = i;
            numToStr[i] = a;
        }

        cin >> r;
        for (int i = 0; i < r; i++) {
            cin >> a >> b;

            edge[strToNum[a]].push_back(strToNum[b]);
            edge[strToNum[b]].push_back(strToNum[a]);
        }

        for (int i  = 1; i <= n; i++) {
            if (!dfn[i]) {
                dfs(i, -1);
            }
        }

        if (cases != 1) {
            cout << endl;
        }
        cout << "City map #" << cases++ << ": " << ans.size() << " camera(s) found" << endl;
        for (set<string>::iterator iter = ans.begin(); iter != ans.end(); iter++) {
            cout << *iter << endl;
        }
    }

}

void dfs(int cur, int prev)
{
    int child = 0;

    dfn[cur] = low[cur] = ++dfsn;

    for (int next : edge[cur]) {
        if (!dfn[next]) {
            ++child;
            dfs(next, cur);
            low[cur] = min(low[cur], low[next]);
            if (prev == -1 && child > 1 || prev != -1 && low[next] >= dfn[cur]) {
                ans.insert(numToStr[cur]);
            }
        } else if (next != prev) {
            low[cur] = min(low[cur], dfn[next]);
        }
    }
}
