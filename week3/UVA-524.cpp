#include <cstdio>
#include <vector>

using namespace std;

int prime[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
vector<int> ans;

void dfs(int curr, int visited[], int n);

int main()
{
    int cases = 0;
    int n;

    while (scanf("%d", &n) != EOF) {
        if (cases != 0) {
            printf("\n");
        }

        printf("Case %d:\n", ++cases);

        int visited[17] = {0};
        ans.clear();
        ans.push_back(1);
        visited[1] = 1;

        dfs(1, visited, n);

    }
}

void dfs(int curr, int visited[], int n)
{
    if (ans.size() == n) {
        bool check = false;

        for (int i = 0; i < 11; i++) {
            if (ans[n - 1] + 1 == prime[i]) {
                check = true;
                break;
            }
        }

        if (check) {

            printf("%d", ans[0]);

            for (int i = 1; i < n; i++) {
                printf(" %d", ans[i]);
            }

            printf("\n");
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            bool check = false;

            for (int j = 0; j < 11; j++) {
                if (prime[j] == i + curr) {
                    check = true;
                    break;
                }
            }

            if (check) {
                ans.push_back(i);
                visited[i] = 1;
                dfs(i, visited, n);
                ans.pop_back();
                visited[i] = 0;
            }
        }
    }
}
