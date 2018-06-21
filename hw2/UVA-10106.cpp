#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a[256], b[256];
    int aLen, bLen;
    string aStr, bStr;

    while (cin >> aStr >> bStr) {
        aLen = aStr.length();
        bLen = bStr.length();

        for (int i = 0; i < aStr.length(); i++) {
            a[i] = aStr[aLen - i - 1] - '0';
        }

        for (int i = 0; i < bStr.length(); i++) {
            b[i] = bStr[bLen - i - 1] - '0';
        }

        int ans[512] = {0};

        for (int i = 0; i < aLen; i++) {
            for (int j = 0; j < bLen; j++) {
                ans[i + j] += a[i] * b[j];
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;
            }
        }

        int ansLen = aLen + bLen;
        while (ans[ansLen - 1] == 0 && ansLen > 1) {
            ansLen--;
        }

        for (int i = ansLen - 1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}
