#include <cstdio>

int set[20002];

int FindRoot(int x);

int main()
{
    int n;
    int c, x, y;

    for (int i = 0; i < 20002; i++) {
        set[i] = i;
    }

    scanf("%d", &n);

    while (scanf("%d %d %d", &c, &x, &y) != EOF) {
        if (c == 0 && x == 0 && y == 0) {
            break;
        }

        int xF = FindRoot(x), xE = FindRoot(x + n);
        int yF = FindRoot(y), yE = FindRoot(y + n);

        switch (c) {
            case 1:
                if (xF == yE) {
                    puts("-1");
                } else {
                    set[xF] = yF;
                    set[xE] = yE;
                }
                break;
            case 2:
                if (xF == yF) {
                    puts("-1");
                } else {
                    set[xF] = yE;
                    set[xE] = yF;
                }
                break;
            case 3:
                if (xF == yF) {
                    puts("1");
                } else {
                    puts("0");
                }
                break;
            case 4:
                if (xF == yF) {
                    puts("0");
                } else {
                    puts("1");
                }
                break;
        }
    }

}

int FindRoot(int x)
{
    if (set[x] == x) {
        return x;
    }

    return set[x] = FindRoot(set[x]);
}
