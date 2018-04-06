#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;

    scanf("%d", &n);

    int seq[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", seq + i);
    }

    scanf("%d", &q);

    while (q--) {
        int h;

        scanf("%d", &h);

        int *low = lower_bound(seq, seq + n, h);
        int *up = upper_bound(seq, seq + n, h);

        if (low == seq) {
            printf("X ");
        } else {
            printf("%d ", *(low - 1));
        }

        if (up == seq + n) {
            printf("X\n");
        } else {
            printf("%d\n", *up);
        }

    }
}
