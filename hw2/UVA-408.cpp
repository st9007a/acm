#include <cstdio>

int gcd(int a, int b);

int main()
{
    int step, mod;

    while (scanf("%d %d", &step, &mod) != EOF) {
        int flag = gcd(step, mod);

        if (flag == 1) {
            printf("%10d%10d    Good Choice\n\n", step, mod);
        } else {
            printf("%10d%10d    Bad Choice\n\n", step, mod);
        }
    }
}

int gcd(int a, int b)
{
    if (a == 0) {
        return b;
    }

    return gcd(b % a, a);
}
