#include <iostream>
#include <string>

using namespace std;

int pi[1000005] = {-1};

int main()
{
    string s;

    while (cin >> s) {
        if (s == ".") {
            break;
        }

        int len = s.length();
        int curPos = -1;

        for (int i = 1; i < len; i++) {
            while (curPos != -1 && s[curPos + 1] != s[i]) {
                curPos = pi[curPos];
            }

            if (s[curPos + 1] == s[i]) {
                curPos++;
            }

            pi[i] = curPos;
        }

        int period = len - pi[len - 1] - 1;
        cout << (len % period == 0 ? len / period : 1) << endl;

    }
}
