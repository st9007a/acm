#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str1, str2;

    while (getline(cin, str1) && getline(cin, str2)) {
        int lcs[1001][1001] = {0};

        for (int i = 1; i <= str1.length(); i++) {
            for (int j = 1; j <= str2.length(); j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        cout << lcs[str1.length()][str2.length()] << endl;
    }
}
