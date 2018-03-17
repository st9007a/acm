#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double pi = 2 * asin(1);
    int cases;
    double h, b;

    scanf("%d", &cases);

    while (cases--)
    {
        scanf("%lf %lf", &b, &h);

        double t = sqrt(pow(b / 2, 2) + pow(h, 2));
        double sum = 0;

        while (true) {
            double r = b * h / (t * 2 + b);
            if (r < 0.000001) {
                break;
            }

            sum += r * 2 * pi;
            h -= r * 2;
        }

        printf("%13.6lf\n", sum);
        if (cases != 0) {
            printf("\n");
        }
    }
}
