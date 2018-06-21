#include <cstdio>

int dim;
char map[30][30];
const int dir[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void DFS(int i, int j);

int main()
{
    int num = 1;

    while (scanf("%d", &dim) != EOF) {

        for (int i = 0; i < dim; i++) {
            scanf("%s", map[i]);
        }

        int n = 0;

        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                if (map[i][j] == '1') {
                    DFS(i, j);
                    n++;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", num++, n);
    }

}

void DFS(int i, int j)
{
    if (i >= dim || i < 0 || j >= dim || j < 0) {
        return;
    }
    if (map[i][j] != '1') {
        return;
    }

    map[i][j] = 'v';
    for (int k = 0; k < 8; k++) {
        DFS(i + dir[k][0], j + dir[k][1]);
    }
}
