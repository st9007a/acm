#include <cstdio>
#include <vector>

using namespace std;

long long int num;
vector<int> prime;

bool isPrime(int n);

int main()
{
    prime.push_back(2);
    prime.push_back(3);
    for (int i = 5, gap = 2; i < 1000000; i += gap, gap = 6 - gap) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }

    while (scanf("%lld", &num)) {
        if (num < 0) {
            break;
        }

        for (int next : prime) {
            while (num % next == 0) {
                printf("    %d\n", next);
                num /= next;
            }

            if (num == 1) {
                break;
            }
        }

        if (num != 1) {
            printf("    %lld\n", num);
        }
        printf("\n");
    }
}

bool isPrime(int n)
{
    for (int i = 0; prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
    return true;
}
