#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct StringArray {
    int size;
    string el[1005];
};

StringArray stringSplit(string str);

int main()
{
    int cases  = 0;

    while (!cin.eof()) {
        cases++;

        string str1, str2;

        getline(cin, str1);
        getline(cin, str2);

        StringArray sa1 = stringSplit(str1);
        StringArray sa2 = stringSplit(str2);

        printf("%2d. ", cases);
        if (str1.empty() || str2.empty()) {
            printf("Blank!\n");
            continue;
        }

        int lcs[1005][1005] = {0};

        for (int i = 1; i <= sa1.size; i++) {
            for (int j = 1; j <= sa2.size; j++) {
                if (sa1.el[i - 1] == sa2.el[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        printf("Length of longest match: %d\n", lcs[sa1.size][sa2.size]);
    }
}

StringArray stringSplit(string str)
{
    StringArray sa;
    int len = str.size();

    sa.size = 0;

    for (int i = 0; i < len; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            sa.el[sa.size] += str[i];

            if (i == len - 1) {
                sa.size++;
            }
        } else if (!sa.el[sa.size].empty()){
            sa.size++;
        }
    }

    return sa;
}

