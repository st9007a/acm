#include <cstdio>

int stack[250 * 250 + 1];
int hash[250 * 250 + 1];

int main()
{
    int cases, caseIdx = 1;
    int n, p, q;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d %d %d", &n, &p, &q);

        int tmp;

        for (int i = 0; i < 250 * 250 + 1; i++) {
            hash[i] = 0;
        }

        for (int i = 1; i <= p + 1; i++) {
            scanf("%d", &tmp);

            hash[tmp] = i;
        }

        int top = 0;
        stack[top] = -1;

        for (int i = 0; i <= q; i++) {
            scanf("%d", &tmp);

            tmp = hash[tmp];

            if (tmp) {
                if (tmp > stack[top]) {
                    stack[++top] = tmp;
                } else {
                    int l = 1, r = top;

                    while (l <= r) {
                        int mid = (l + r) / 2;

                        if (stack[mid] < tmp) {
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }

                    stack[l] = tmp;
                }
            }
        }

        printf("Case %d: %d\n", caseIdx++, top);
    }
}
