#include <algorithm>
#include <cstdio>

using namespace std;

struct Combo {
    int items[6];
    int price;
};

int numItems, numCombos, numOrders;
int cost[6];
Combo combos[8];

int bestPrice(int order[]);

int main()
{
    int order[6];

    while(scanf("%d", &numItems) != EOF) {
        for (int i = 0; i < numItems; i++) {
            scanf("%d", cost + i);
        }

        scanf("%d", &numCombos);

        for (int i = 0; i < numCombos; i++) {
            for (int j = 0; j < numItems; j++) {
                scanf("%d", &combos[i].items[j]);
            }

            scanf("%d", &combos[i].price);
        }

        scanf("%d", &numOrders);

        while (numOrders--) {
            for (int i = 0; i < numItems; i++) {
                scanf("%d", order + i);
            }

            printf("%d\n", bestPrice(order));
        }
    }
}

int bestPrice(int order[])
{
    int minimum = 1000000;
    for (int i = 0; i < numCombos; i++) {
        bool check = true;
        for (int j = 0; j < numItems; j++) {
            if (order[j] < combos[i].items[j]) {
                check = false;
                break;
            }
        }

        if (check) {
            for (int j = 0; j < numItems; j++) {
                order[j] -= combos[i].items[j];
            }

            minimum = min(minimum, combos[i].price + bestPrice(order));

            for (int j = 0; j < numItems; j++) {
                order[j] += combos[i].items[j];
            }
        }
    }

    if (minimum == 1000000) {
        minimum = 0;
        for (int i = 0; i < numItems; i++) {
            minimum += order[i] * cost[i];
        }
    }

    return minimum;
}
