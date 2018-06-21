#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

struct Point {
    double x;
    double y;
};

Point p[100000], ch[100000];

bool cmp(const Point &a, const Point &b)
{
    return (a.x < b.x) || (a.x == b.x && a.y > b.y);
}

double cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int MonotoneChain(int n)
{
    sort(p, p + n, cmp);

    int m = 0;

    for (int i = 0; i < n; i++) {
        while (m >= 2 && cross(ch[m - 2], ch[m - 1], p[i]) >= 0) {
            m--;
        }

        ch[m++] = p[i];
    }

    for (int i = n - 1, t = m + 1; i >= 0; i--) {
        while (m >= t && cross(ch[m - 2], ch[m - 1], p[i]) >= 0) {
            m--;
        }

        ch[m++] = p[i];
    }

    return m;

}

int main()
{
    int n, cases = 1;

    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }

        if (cases != 1) {
            printf("\n");
        }

        printf("Region #%d:\n", cases++);
        int m = MonotoneChain(n);

        double len = 0;

        printf("(%.1lf,%.1lf)", ch[0].x, ch[0].y);
        for (int i = 1; i < m; i++) {
            printf("-(%.1lf,%.1lf)", ch[i].x, ch[i].y);

            len += sqrt(pow(ch[i].x - ch[i - 1].x, 2) + pow(ch[i].y - ch[i - 1].y, 2));
        }
        printf("\nPerimeter length = %.2lf\n", len);
    }
}
