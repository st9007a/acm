#include <cstdio>

char map[201][201];
int n;
const int dir[6][2] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};

int DFS(int i, int j);

int main()
{
    int cases = 0;

    while (scanf("%d", &n) && n) {
        cases++;

        for (int i = 0; i < n; i++) {
            scanf("%s", map[i]);
        }

        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (map[0][i] == 'b' && (flag = DFS(0, i)) == 1) {
                break;
            }
        }

        if (flag) {
            printf("%d B\n", cases);
        } else {
            printf("%d W\n", cases);
        }
    }
}

int DFS(int i, int j)
{
    if (i == n) {
        return 1;
    }

    if (i < 0 || i >= n || j < 0 || j >= n) {
        return 0;
    }
    if (map[i][j] != 'b') {
        return 0;
    }

    map[i][j] = 'v';

    for (int k = 0; k < 6; k++) {
        if (DFS(i + dir[k][0], j + dir[k][1]) == 1) {
            return 1;
        }
    }

    return 0;
}
