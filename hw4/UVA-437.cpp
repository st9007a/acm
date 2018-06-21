#include <cstdio>
#include <algorithm>

using namespace std;

struct Block {
    int h;
    int w;
    int l;
};

Block b[30 * 3];

bool cmp(const Block &a, const Block &b);

int main()
{
    int num, cases = 1;

    while (scanf("%d", &num) && num != 0) {
        int edge[3], ptr = 0;
        for (int i = 0; i < num; i++) {
            scanf("%d %d %d", edge, edge + 1, edge + 2);

            sort(edge, edge + 3);

            b[ptr++] = {edge[0], edge[1], edge[2]};
            b[ptr++] = {edge[1], edge[0], edge[2]};
            b[ptr++] = {edge[2], edge[0], edge[1]};
        }

        sort(b, b + ptr, cmp);

        int lis[30 * 3], maxH = 0;

        for (int i = 0; i < ptr; i++) {
            lis[i] = b[i].h;
        }

        for (int i = 0; i < ptr; i++) {

            for (int j = i + 1; j < ptr; j++) {
                if (b[i].w < b[j].w && b[i].l < b[j].l && lis[i] + b[j].h > lis[j]) {
                    lis[j] = lis[i] + b[j].h;
                }
            }
        }

        for (int i = 0; i < ptr; i++) {
            if (maxH < lis[i]) {
                maxH = lis[i];
            }
        }

        printf("Case %d: maximum height = %d\n", cases++, maxH);
    }
}

bool cmp(const Block &a, const Block &b)
{
    if (a.l == b.l) {
        return a.w < b.w;
    }
    return a.l < b.l;
}
