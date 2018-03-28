#include <cstdio>
#include <cmath>

using namespace std;

int p, q, r, s, t, u;
double formula(double x);

int main()
{

    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        double mid, max = 1.0, min = 0.0;
        for (int i = 0; i < 100; i++) {
            mid = (min + max) / 2;
            if (formula(mid) > 0) {
                min = mid;
            } else {
                max = mid;
            }
        }

        if (fabs(formula(mid) - 0) > 1e-9) {
            printf("No solution\n");
        } else {
            printf("%.4lf\n", mid);
        }
    }
}

double formula(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}
