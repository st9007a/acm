#include <cstdio>

int exGCD(int a, int b, int &x, int &y);

int main()
{
    int a, b, x, y, gcd;

    while (scanf("%d %d", &a, &b) != EOF) {
        gcd = exGCD(a, b, x, y);
        printf("%d %d %d\n", x, y, gcd);
    }
}

int exGCD(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    } else {
        int gcd = exGCD(b, a % b, x, y);

        int tmp = x;
        x = y;
        y = tmp - (a / b) * y;
        return gcd;
    }
}
