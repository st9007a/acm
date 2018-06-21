#include <cstdio>

char visit[100000001] = {0};
int prime[10000001];

int bs(int r, int key);

int main()
{
    int n;
    int count = 0;

	for (int i = 2; i < 100000001; ++ i) {
		if (!visit[i]) {
			prime[count++] = i;
		}
        for (int j = 0; j < count && i * prime[j] < 100000001; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
				break;
			}
        }
    }
	prime[count] = 100000001;

    while(scanf("%d", &n) != EOF) {
        if (n < 5) {
            printf("%d is not the sum of two primes!\n", n);
        } else if (n % 2) {
            if (prime[bs(count, n - 2) + 1] == n - 2) {
                printf("%d is the sum of 2 and %d.\n", n, n - 2);
            } else {
                printf("%d is not the sum of two primes!\n", n);
            }
        } else {
            int flag = 1;
            for (int i = bs(count, n / 2); i >= 0; i--) {
                if (prime[bs(count, n - prime[i]) + 1] == n - prime[i]) {
                    printf("%d is the sum of %d and %d.\n", n, prime[i], n - prime[i]);
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                printf("%d is not the sum of two primes!\n", n);
            }
        }
    }
}

int bs(int r, int key)
{
    int mid, l = 0;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (prime[mid] >= key) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }

    return l;
}
