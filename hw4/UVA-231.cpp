#include <cstdio>
#include <vector>

using namespace std;

int lis[100000];

int main()
{
    int cases = 1;
    int num;

    while (scanf("%d", &num) && num != -1) {
        vector<int> height;
        height.push_back(num);

        while (scanf("%d", &num) && num != -1) {
            height.push_back(num);
        }

        int count = 0;

        for (int i = height.size() - 1; i >= 0; i--) {
            lis[i] = 1;
            for (int j = height.size() - 1; j > i; j--) {
                if (height[j] <= height[i] && lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                }
            }

            if (count < lis[i]) {
                count = lis[i];
            }
        }

        if (cases != 1) {
            printf("\n");
        }

        printf("Test #%d:\n  maximum possible interceptions: %d\n", cases++, count);

    }

}
