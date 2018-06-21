#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases;
    string s;

    cin >> cases;

    while (cases--) {
        cin >> s;

        for (int i = 1; i <= s.length(); i++) {
            bool flag = true;

            for (int j = 0; j < i; j++) {
                for (int k = i + j; k < s.length(); k += i) {
                    if (s[k] != s[j]) {
                        flag = false;
                        goto after_check;
                    }
                }
            }
after_check:
            if (flag && s.length() % i == 0) {
                cout << i << '\n';

                if (cases) {
                    cout << endl;
                }
                break;
            }
        }
    }
}
