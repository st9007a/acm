#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

int seq[100000], link[100000], lis[100000];
char buf[256];

void output(int d, int s)
{
    if (link[s] >= s) {
        printf("Max hits: %d\n", d + 1);
    } else {
        output(d + 1, link[s]);
    }

    printf("%d\n", seq[s]);
}

int main()
{
    int cases;

    scanf("%d", &cases);
    getchar();
    getchar();

    while (cases--) {
        int count = 0;
        int maxIdx = 0, maxVal = 0;

        while(gets(buf) && buf[0]) {
            seq[count++] = atoi(buf);
        }

        for (int i = 0; i < count; i++) {
            lis[i] = 1;
            link[i] = i;

            for (int j = 0; j < i; j++) {
                if (seq[i] > seq[j] && lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                    link[i] = j;
                }
            }
        }

        for (int i = 0; i < count; i++) {
            if (lis[i] > lis[maxIdx]) {
                maxIdx = i;
                maxVal = lis[maxIdx];
            }
        }

        if (count) {
            output(0, maxIdx);
        } else {
            printf("Max hits: 0\n");
        }

        if (cases != 0) {
            printf("\n");
        }
    }
}
