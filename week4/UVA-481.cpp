#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector<int> seq, pos;
stack<int> ans;

int main()
{
    int num, maxL = 0, idx = -1;

    while (scanf("%d", &num) != EOF) {
        seq.push_back(num);
    }

    vector<int> v;
    v.push_back(seq[0]);
    pos.push_back(0);

    for (int i = 1; i < seq.size(); i++) {
        int n = seq[i];

        if (n > v.back()) {
            v.push_back(n);
            pos.push_back(v.size() - 1);
        } else {
            auto ptr = lower_bound(v.begin(), v.end(), n);
            *ptr = n;
            pos.push_back(ptr - v.begin());
        }
    }

    printf("%d\n-\n", v.size());

    int currPos;
    for (int i = pos.size() - 1; i >= 0; i--) {
        if (pos[i] == v.size() - 1) {
            currPos = i;
            ans.push(seq[i]);
            break;
        }
    }

    int curr = v.size() - 2;
    for (int i = currPos - 1; i >= 0; i--) {
        if (pos[i] == curr && seq[i] < ans.top()) {
            ans.push(seq[i]);
            curr--;
        }
    }

    while (!ans.empty()) {
        printf("%d\n", ans.top());
        ans.pop();
    }

}
