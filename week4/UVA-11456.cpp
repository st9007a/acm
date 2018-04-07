#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int cases;

    scanf("%d", &cases);

    while (cases--) {
        int num;

        scanf("%d", &num);

        if (num == 0) {
            printf("0\n");
            continue;
        }

        int cars[num * 2];

        for (int i = 0; i < num; i++) {
            int tmp;

            scanf("%d", &tmp);

            cars[num - i - 1] = cars[num + i] = tmp;
        }

        vector<int> v;

        v.push_back(cars[0]);
        for (int i = 1; i < num * 2; i++) {
            if (cars[i] > v.back()) {
                v.push_back(cars[i]);
            } else {
                *lower_bound(v.begin(), v.end(), cars[i]) = cars[i];
            }
        }

        printf("%d\n", v.size());
    }
}
