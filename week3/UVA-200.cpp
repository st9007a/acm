#include <iostream>
#include <string>
#include <vector>

using namespace std;

int rule[26][26] = {0};
int used[26] = {0};
int total = 0;

vector<char> ans;

bool dfs(char key);

int main()
{
    string a, b;

    cin >> a;

    while (cin >> b) {
        if (b == "#") {
            break;
        }

        int length = a.length() > b.length() ? b.length() : a.length();

        for (int i = 0; i < length; i++) {
            if (a[i] != b[i]) {
                rule[a[i] - 'A'][b[i] - 'A'] = 1;
                used[a[i] - 'A'] = 1;
                used[b[i] - 'A'] = 1;
                break;
            }
        }

        a = b;

    }

    for (int i = 0; i < 26; i++) {
        total += used[i];
    }

    for (int i = 0; i < 26; i++) {
        if (used[i] == 1) {
            ans.push_back(i + 'A');
            if (dfs(i + 'A')) {
                for (int j = 0; j < ans.size(); j++) {
                    cout << ans[j];
                }

                break;
            } else {
                ans.pop_back();
            }
        }
    }

    cout << endl;
}

bool dfs(char key)
{
    if (ans.size() == total) {
        return true;
    }

    for (int i = 0; i < 26; i++) {
        if (rule[key - 'A'][i] == 0) {
            continue;
        }

        ans.push_back(i + 'A');

        if (dfs(i + 'A')) {
            return true;
        } else {
            ans.pop_back();
        }
    }

    return false;

}
