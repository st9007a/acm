#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string c1, c2;
    int cases = 1;

    while (getline(cin, c1)) {
        if (c1[0] == '#') {
            break;
        }

        getline(cin, c2);

        int lcs[101][101] = {0};

        for (int i = 1; i <= c1.length(); i++) {
            for (int j = 1; j <= c2.length(); j++) {
                if (c1[i - 1] == c2[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        cout << "Case #" << cases++ << ": you can visit at most " << lcs[c1.length()][c2.length()] << " cities." << endl;
    }
}
