#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    long long lists[1500];
    int n2 = 0, n3 = 0, n5 = 0;

    lists[0] = 1;

    for (int i = 1; i < 1500; i++) {
        while (lists[n2] * 2 <= lists[i - 1]) {
            n2++;
        }
        while (lists[n3] * 3 <= lists[i - 1]) {
            n3++;
        }
        while (lists[n5] * 5 <= lists[i - 1]) {
            n5++;
        }

        lists[i] = min(lists[n2] * 2, min(lists[n3] * 3, lists[n5] * 5));
    }

    printf("The 1500'th ugly number is %lld.\n", lists[1499]);
}
