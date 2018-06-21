#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Elephant {
    int id;
    int w;
    int s;
};

vector<Elephant> elephants;

bool cmp(const Elephant &a, const Elephant &b);

int main()
{
    int w, s;
    int id = 0;

    while (scanf("%d %d", &w, &s) != EOF) {
        Elephant el;

        el.w = w;
        el.s = s;
        el.id = ++id;

        elephants.push_back(el);
    }

    sort(elephants.begin(), elephants.end(), cmp);

    int lis[elephants.size()];
    int link[elephants.size()];
    int maxIdx, maxLen = 0;

    for (int i = 0; i < elephants.size(); i++) {
        lis[i] = 1;
        link[i] = -1;
        for (int j = 0; j < i; j++) {
            if (elephants[i].s > elephants[j].s && elephants[i].w < elephants[j].w && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                link[i] = j;
            }
        }

        if (lis[i] > maxLen) {
            maxLen = lis[i];
            maxIdx = i;
        }
    }

    printf("%d\n", maxLen);

    int curr = maxIdx;
    while (curr != -1) {
        printf("%d\n", elephants[curr].id);
        curr = link[curr];
    }
}

bool cmp(const Elephant &a, const Elephant &b)
{
    if (a.w == b.w) {
        return a.s < b.s;
    }

    return a.w > b.w;
}
