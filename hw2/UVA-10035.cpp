#include <cstdio>

int main()
{
    unsigned long a, b;

    while(scanf("%lu %lu", &a, &b)) {
        if (a == 0 && b == 0) {
            break;
        }

        int count = 0;
        int carry = 0;

        for (int i = 0; i < 12; i++) {
            if ((a % 10) + (b % 10) + carry >= 10) {
                count++;
                carry = 1;
            } else {
                carry = 0;
            }

            a /= 10;
            b /= 10;
        }

        if (count == 0) {
            printf("No carry operation.\n");
        }
        else if (count == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", count);
        }
    }
}
