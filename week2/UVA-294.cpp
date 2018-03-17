#include <cstdio>
#include <vector>

using namespace std;

vector<int> prime;
bool isPrime(int n);

int main()
{
    int cases;
    long l, u;

    prime.push_back(2);
    prime.push_back(3);
    for (int i = 5, gap = 2; i < 1000000; i += gap, gap = 6 - gap) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }

    scanf("%d", &cases);

    while(cases--) {
        scanf("%ld %ld", &l, &u);

        long maxNum = -1, maxDiv = -1;

        for (long i = l; i <= u; i++) {
            vector<int> f;
            int num = i;
            int d = 1;

            for (int next : prime) {
                int count = 0;
                while (num % next == 0) {
                    num /= next;
                    count++;
                }

                f.push_back(count);

                if (num == 1) {
                    break;
                }
            }

            for (int next : f) {
                d *= (next + 1);
            }

            if(d > maxDiv) {
                maxNum = i;
                maxDiv = d;
            }
        }

        printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n", l, u, maxNum, maxDiv);
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
