#include <cstdio>
#include <vector>

using namespace std;

struct Coin {
    int price;
    int count;
    int visited;
};

vector<Coin> coins;
bool exist = false;

void bt(int dim, int sum, int total);

int main()
{
    int t, n;

    while (scanf("%d %d", &t, &n) != EOF) {
        if (t == 0 && n == 0) {
            break;
        }
        printf("Sums of %d:\n", t);

        coins.clear();
        int tmp;

        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);

            if (coins.size() == 0 || tmp != coins.back().price) {
                Coin c = { .price = tmp, .count = 1, .visited = 0 };
                coins.push_back(c);
            } else {
                coins.back().count++;
            }
        }

        exist = false;
        bt(0, 0, t);

        if (!exist) {
            printf("NONE\n");
        }
    }
}

void bt(int dim, int sum, int total)
{
    if (sum == total) {
        int flag = 0;
        for (Coin c : coins) {
            for (int i = 0; i < c.visited; i++) {
                if (flag) {
                    printf("+%d", c.price);
                } else {
                    printf("%d", c.price);
                    flag = 1;
                }
            }
        }
        printf("\n");
        exist = true;
        return;
    } else if (dim < coins.size()) {
        for (int i = dim; i < coins.size(); i++) {
            if (coins[i].count > coins[i].visited && sum + coins[i].price <= total) {
                coins[i].visited++;
                sum += coins[i].price;

                bt(i, sum, total);

                coins[i].visited--;
                sum -= coins[i].price;
            }
        }
    }
}
