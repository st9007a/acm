#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int cases, queries;
    char q[1001];
    char s[100001];

    cin >> cases;

    while (cases--) {
        cin >> s;
        cin >> queries;

        while (queries--) {
            cin >> q;
            if (NULL == strstr(s, q)) {
                cout << "n\n";
            } else {
                cout << "y\n";
            }
        }
    }

}
