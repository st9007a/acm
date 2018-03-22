#include <cstdio>
#include <vector>

using namespace std;

vector<int> ans;
int graph[6][6] = {0};
int visited[6][6] = {0};

void dfs(int pos);

int main()
{

    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][4] = 1; graph[4][3] = 1;
    graph[4][5] = 1; graph[5][4] = 1;
    graph[1][3] = 1; graph[3][1] = 1;
    graph[1][5] = 1; graph[5][1] = 1;
    graph[2][5] = 1; graph[5][2] = 1;
    graph[3][5] = 1; graph[5][3] = 1;

    ans.push_back(1);
    dfs(1);

}

void dfs(int pos)
{

    if (ans.size() == 9) {
        for (int i = 0; i < 9; i++) {
            printf("%d", ans[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= 5; i++) {
        if ((visited[i][pos] == 0 || visited[pos][i] == 0) && graph[pos][i] == 1) {
            visited[pos][i] = 1;
            visited[i][pos] = 1;
            ans.push_back(i);

            dfs(i);

            visited[pos][i] = 0;
            visited[i][pos] = 0;
            ans.pop_back();
        }
    }
}
