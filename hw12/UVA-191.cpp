#include <algorithm>
#include <cstdio>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Line {
    Point s, t;
};

double cross(Point &a, Point &b, Point &o)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool onLine(Line &l, Point &p)
{
    double minx = min(l.s.x, l.t.x),
           maxx = max(l.s.x, l.t.x),
           miny = min(l.s.y, l.t.y),
           maxy = max(l.s.y, l.t.y);

    if (p.x >= minx && p.x <= maxx && p.y >= miny && p.y <= maxy) {
        if (cross(p, l.s, l.t) == 0) {
            return true;
        }
    }

    return false;
}

bool intersection(Line &a, Line &b)
{
    if (onLine(a, b.s) || onLine(a, b.t) || onLine(b, a.s) || onLine(b, a.t)) {
        return true;
    }

    if (cross(a.s, a.t, b.s) * cross(a.s, a.t, b.t) < 0 &&
        cross(a.t, a.s, b.s) * cross(a.t, a.s, b.t) < 0 &&
        cross(b.s, b.t, a.s) * cross(b.s, b.t, a.t) < 0 &&
        cross(b.t, b.s, a.s) * cross(b.t, b.s, a.t) < 0) {
        return true;
    }

    return false;
}

int main()
{
    int cases;
    Line l, edge;
    double xl, xr, yt, yb;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%lf %lf %lf %lf", &l.s.x, &l.s.y, &l.t.x, &l.t.y);
        scanf("%lf %lf %lf %lf", &xl, &yt, &xr, &yb);

        if (xl > xr) {
            double tmp = xl;
            xl = xr;
            xr = tmp;
        }

        if (yb > yt) {
            double tmp = yt;
            yt = yb;
            yb = tmp;
        }

        if (xl <= l.s.x && l.s.x <= xr && yb <= l.s.y && l.s.y <= yt) {
            printf("T\n");
        } else if (xl <= l.t.x && l.t.x <= xr && yb <= l.t.y && l.t.y <= yt) {
            printf("T\n");
        } else {
            int flag = 0;
            edge.s.x = xl, edge.s.y = yb, edge.t.x = xl, edge.t.y = yt;
            flag |= intersection(edge, l);
            edge.s.x = xr, edge.s.y = yb, edge.t.x = xr, edge.t.y = yt;
            flag |= intersection(edge, l);
            edge.s.x = xl, edge.s.y = yb, edge.t.x = xr, edge.t.y = yb;
            flag |= intersection(edge, l);
            edge.s.x = xl, edge.s.y = yt, edge.t.x = xr, edge.t.y = yt;
            flag |= intersection(edge, l);

            if (flag) {
                printf("T\n");
            } else {
                printf("F\n");
            }
        }

    }
}
