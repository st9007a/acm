#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int llink[300], rlink[10];
bool visited[10];
bool edge[300][10];
vector<char> users;

bool DFS(int now);

int main()
{
    char line[20];

    while (gets(line)) {
        memset(edge, 0, sizeof(edge));
        users.clear();

        int num = line[1] - '0';
        for (int i = 0; i < num; i++) {
            users.push_back(line[0]);
        }
        for (int i = 3; line[i] != ';'; i++) {
            int com = line[i] - '0';
            for (int j = 0; j < users.size(); j++) {
                edge[j][com] = true;
            }
        }

        while (gets(line)) {
            if (line[0] == '\0') {
                break;
            }
            int num = line[1] - '0';
            int start = users.size();
            for (int i = 0; i < num; i++) {
                users.push_back(line[0]);
            }
            for (int i = 3; line[i] != ';'; i++) {
                int com = line[i] - '0';
                for (int j = start; j < users.size(); j++) {
                    edge[j][com] = true;
                }
            }
        }

        bool ansExist = true;
        memset(llink, -1, users.size() * sizeof(int));
        memset(rlink, -1, sizeof(rlink));

        for (int i = 0; i < users.size(); i++) {
            memset(visited, 0, sizeof(visited));
            if (!DFS(i)) {
                ansExist = false;
                break;
            }
        }

        if (!ansExist) {
            printf("!\n");
        } else {
            for (int i = 0; i < 10; i++) {
                printf("%c", rlink[i] == -1 ? '_' : users[rlink[i]]);
            }
            printf("\n");
        }
    }
}

bool DFS(int now)
{
    for (int i = 0; i < 10; i++) {
        if (!edge[now][i] || visited[i]) {
            continue;
        }

        visited[i] = true;

        if (rlink[i] == -1 || DFS(rlink[i])) {
            llink[now] = i;
            rlink[i] = now;
            return true;
        }
    }

    return false;
}
