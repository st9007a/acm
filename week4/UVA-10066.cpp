#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int cases = 1;
    int s1, s2;

    while (scanf("%d %d", &s1, &s2) && s1 != 0 && s2 != 0) {

        int tower[2][101];
        int lcs[101][101] = {0};

        for (int i = 1; i <= s1; i++) {
            scanf("%d", &tower[0][i]);
        }
        for (int i = 1; i <= s2; i++) {
            scanf("%d", &tower[1][i]);
        }

        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {

                if (tower[0][i] == tower[1][j]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cases++, lcs[s1][s2]);

    }
}
