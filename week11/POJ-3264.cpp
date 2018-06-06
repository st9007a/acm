#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
    int maxVal, minVal;
    int l, r;
    int lidx, ridx;
};

Node tree[100005];
int ptr;
int sequence[50005];
void build(int l, int r, int idx);
void query(int l, int r, int idx, int &maxVal, int &minVal);

int main()
{
    int n, q;
    int l, r, maxVal, minVal;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", sequence + i);
    }

    ptr = 0;

    build(0, n, 0);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        query(l - 1, r, 0, maxVal, minVal);
        printf("%d\n", maxVal - minVal);
    }

    return 0;
}

void build(int l, int r, int idx)
{
    tree[idx].l = l;
    tree[idx].r = r;

    if (l == r - 1) {
        tree[idx].maxVal = tree[idx].minVal = sequence[l];
        return;
    }

    int lidx = tree[idx].lidx = ++ptr;
    int ridx = tree[idx].ridx = ++ptr;

    int mid = (l + r) >> 1;

    build(l, mid, lidx);
    build(mid, r, ridx);

    tree[idx].maxVal = max(tree[lidx].maxVal, tree[ridx].maxVal);
    tree[idx].minVal = min(tree[lidx].minVal, tree[ridx].minVal);
}

void query(int l, int r, int idx, int &maxVal, int &minVal)
{
    if (l == tree[idx].l && r == tree[idx].r) {
        minVal = tree[idx].minVal;
        maxVal = tree[idx].maxVal;
        return;
    }

    int mid = (tree[idx].l + tree[idx].r) >> 1;

    if (l >= mid) {
        query(l, r, tree[idx].ridx, maxVal, minVal);
    } else if (r <= mid) {
        query(l, r, tree[idx].lidx, maxVal, minVal);
    } else {
        int max1, min1, max2, min2;
        query(l, mid, tree[idx].lidx, max1, min1);
        query(mid, r, tree[idx].ridx, max2, min2);
        maxVal = max(max1, max2);
        minVal = min(min1, min2);
    }
}
