#include <cstdio>
#include <algorithm>

using namespace std;

int p[1000];
int ans[1000][1000], idx[1000];

int main()
{
    int cases;
    int m, k;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d %d", &m, &k);

        long long int Max = 0, Min = 0, Mid = 0;

        for (int i = 0; i < m; i++) {
            scanf("%d", p + i);

            if (p[i] > Min) {
                Min = p[i];
            }

            Max += p[i];
        }

        while (Min < Max) {
            int amount = 1;
            long long sum = 0;

            Mid = (Max + Min) / 2;

            for (int i = 0; i < m; i++) {
                if (sum + p[i] > Mid) {
                    amount++;
                    sum = 0;
                }

                sum += p[i];
            }

            if (amount > k) {
                Min = Mid + 1;
            } else {
                Max = Mid;
            }
        }

        fill(idx, idx + 1000, 0);
        long long int sum = 0;

        for (int i = m - 1, j = k - 1; i >= 0; i--) {
            if (sum + p[i] > Max || j > i) {
                j--;
                sum = 0;
            }
            sum += p[i];
            ans[j][idx[j]++] = p[i];
        }

        for (int i = 0; i < k; i++) {
            for (int j = idx[i] - 1; j >=0 ; j--) {
                if (i != 0 || j != idx[0] - 1) {
                    printf(" ");
                }

                printf("%d", ans[i][j]);
            }
            if (i != k - 1) {
                printf(" /");
            }

        }
        printf("\n");

    }
}
