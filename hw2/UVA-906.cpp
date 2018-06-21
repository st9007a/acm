#include <cstdio>

int main()
{
    int a, b;
    double eps;

    while (scanf("%d %d", &a, &b) != EOF) {
        scanf("%lf", &eps);

        long double r = (long double)a / b;
        int c, d;
        for (d = 1; ; d++) {
            c = r * d;

            while (a * d >= c * b) {
                c++;
            }

            if ((long double)c / d - r <= eps) {
                printf("%d %d\n", c, d);
                break;
            }
        }
    }
}
