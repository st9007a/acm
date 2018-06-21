#include <iostream>
#include <string>
#include <vector>

using namespace std;

string seq1[110], seq2[110];
vector<string> ans;

int main()
{
    string word;
    while (1) {
        int n = 0, m = 0;

        while (cin >> seq1[n] && seq1[n] != "#") {
            n++;
        }
        while (cin >> seq2[m] && seq2[m] != "#") {
            m++;
        }

        if (n == 0) {
            break;
        }

        int pre[110][110], lcs[110][110] = {0};
        ans.clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (seq1[i] == seq2[j]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                    pre[i][j] = 0;
                } else {
                    if (lcs[i - 1][j] > lcs[i][j - 1]) {
                        lcs[i][j] = lcs[i - 1][j];
                        pre[i][j] = 1;
                    } else {
                        lcs[i][j] = lcs[i][j - 1];
                        pre[i][j] = 2;
                    }
                }
            }
        }

        int i = n - 1, j = m - 1;
        while (i  != -1 && j != -1) {
            if (pre[i][j] == 0) {
                ans.push_back(seq1[i]);
                i--;
                j--;
            } else if (pre[i][j] == 1) {
                i--;
            } else {
                j--;
            }
        }

        if (!ans.empty()) {
            cout << ans.back();

            for (int i = ans.size() - 2; i >= 0; i--) {
                cout << " " << ans[i];
            }
        }
        cout << endl;

    }
}
