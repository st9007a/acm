#include <cstdio>
#include <vector>

using namespace std;

vector<int> tracks;
vector<int> ans, trueAns;

void bt(int dim, int sum, int &currMax, int max);

int main()
{

    int n, count;

    while (scanf("%d %d", &n, &count) != EOF) {
        int tmp, currMax = 0;

        tracks.clear();
        ans.clear();
        trueAns.clear();

        for (int i = 0; i < count; i++) {
            scanf("%d", &tmp);
            tracks.push_back(tmp);
        }

        bt(0, 0, currMax, n);

        for (int next : trueAns) {
            printf("%d ", next);
        }
        printf("sum:%d\n", currMax);
    }
}

void bt(int dim, int sum, int &currMax, int max)
{
    if (sum > currMax) {
        currMax = sum;
        trueAns = ans;
    }

    for (int i = dim; i < tracks.size(); i++) {
        if (sum + tracks[i] <= max) {
            ans.push_back(tracks[i]);
            sum += tracks[i];

            bt(i + 1, sum, currMax, max);

            ans.pop_back();
            sum -= tracks[i];
        }
    }
}
