#include <cstdio>
#include <vector>

using namespace std;

vector<int> prime;

bool isPrime(int n);

int main()
{
    int n, c;
    int start = 0, end = 0;

    prime.push_back(1);
    prime.push_back(2);
    prime.push_back(3);
    for (int i = 5, gap = 2; i < 1000000; i += gap, gap = 6 - gap) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }

    while (scanf("%d %d", &n, &c) != EOF) {

        for (int i = 0; i < 1005; i++) {
            if ((prime[i] < n && prime[i + 1] > n) || prime[i] == n) {
                if (i % 2 == 0) {
                    start = i / 2 - c + 1;
                    end = i / 2 + c - 1;
                } else {
                    start = i / 2 - c + 1;
                    end = i / 2 + c;
                }

                printf("%d %d:", n, c);
                for (int j = start; j <= end; j++) {
                    if (j < 0) {
                        continue;
                    }
                    if (prime[j] > n || j >= 1005) {
                        break;
                    }

                    printf(" %d", prime[j]);
                }
                printf("\n\n");
                break;
            }
        }
    }
}

bool isPrime(int n)
{
    for (int i = 1; prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
    return true;
}
