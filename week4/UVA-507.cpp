#include <cstdio>

int main()
{
    int cases, s, num;

    scanf("%d", &cases);

    for (int i = 1; i <= cases; i++) {
        int sum = -1, start = -1;
        int max = 0, maxStart, maxEnd;

        scanf("%d", &s);

        for (int j = 1; j < s; j++) {
            scanf("%d", &num);

            if (sum >= 0) {
                sum += num;
            } else {
                sum = num;
                start = j;
            }

            if (sum > max || (sum == max && j + 1 - start > maxEnd - maxStart)) {
                max = sum;
                maxStart = start;
                maxEnd = j + 1;
            }
        }

        if (max == 0) {
            printf("Route %d has no nice parts\n", i);
        } else {
            printf("The nicest part of route %d is between stops %d and %d\n", i, maxStart, maxEnd);
        }
    }
}
