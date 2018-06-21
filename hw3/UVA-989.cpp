#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Coord {
    int x;
    int y;
};

int n;
int matrix[10][10];
vector<Coord> zeroPos;

bool cmp(const Coord &a, const Coord &b);
void checkVisited(Coord pos, int visited[]);
bool bt(int dim);

int main()
{
    bool flag = false;

    while (scanf("%d", &n) != EOF) {
        if (flag) {
            printf("\n");
        } else {
            flag = true;
        }

        zeroPos.clear();

        for (int i = 0; i < n * n; i++) {
            for (int j = 0; j < n * n; j++) {
                scanf("%d", &matrix[i][j]);

                if (matrix[i][j] == 0) {
                    Coord tmp = { .x = i, .y = j };
                    zeroPos.push_back(tmp);
                }
            }
        }

        sort(zeroPos.begin(), zeroPos.end(), cmp);
        if (bt(0)) {
            for (int i = 0; i < n * n; i++) {

                for (int j = 0; j < n * n; j++) {
                    printf("%d", matrix[i][j]);

                    if (j != n * n - 1) {
                        printf(" ");
                    }
                }

                printf("\n");
            }
        } else {
            puts("NO SOLUTION");
        }

    }

}

bool cmp(const Coord &a, const Coord &b)
{
    if (a.y == b.y) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}

void checkVisited(Coord pos, int visited[])
{
    for (int i = 0; i < n * n; i++) {
        visited[matrix[pos.x][i]] = 1;
        visited[matrix[i][pos.y]] = 1;
    }

    int regionX = (pos.x / n) * n, regionY = (pos.y / n) * n;

    for (int i = regionX; i < regionX + n; i++) {
        for (int j = regionY; j < regionY + n; j++) {
            visited[matrix[i][j]] = 1;
        }
    }
}

bool bt(int dim)
{
    if (dim == zeroPos.size()) {
        return true;
    }

    int visited[n * n + 1] = {0};
    bool ansExist = false;

    checkVisited(zeroPos[dim], visited);

    for (int i = 1; i <= n * n; i++) {
        if (visited[i] == 0) {
            matrix[zeroPos[dim].x][zeroPos[dim].y] = i;

            if (!bt(dim + 1)) {
                matrix[zeroPos[dim].x][zeroPos[dim].y] = 0;
            } else {
                ansExist = true;
                break;
            }
        }
    }

    return ansExist;
}
