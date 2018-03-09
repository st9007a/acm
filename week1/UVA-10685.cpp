#include <map>
#include <iostream>
#include <string>

using namespace std;

int set[5001];
int num[5001];

map<string, int> mapToNum;

int FindRoot(int x);
void UnionSet(int x, int y);
int MaxNumInSet(int x);

int main()
{

	int c, r;
    string name;

    while (cin >> c >> r) {
        if (c == 0 && r == 0) {
            break;
        }

		mapToNum.clear();

        for (int i = 1; i <= c; i++) {
			cin >> name;
			mapToNum[name] = i;
			num[i] = 1;
			set[i] = i;
		}

		while(r--) {
			cin >> name;
			int x = mapToNum[name];

			cin >> name;
			int y = mapToNum[name];

			UnionSet(x, y);
		}

		cout << MaxNumInSet(c) << "\n";
    }

    return 0;
}

int FindRoot(int x)
{
	if (set[x] == x) {
		return x;
	}

	return set[x] = FindRoot(set[x]);
}

void UnionSet(int x, int y)
{
	x = FindRoot(x);
	y = FindRoot(y);

	if (x != y) {
		set[x] = y;
		num[y] += num[x];
	}
}

int MaxNumInSet(int x)
{
	int max = 0;
	for (int i = 1; i <= x; i++) {
		if (num[i] > max) {
			max = num[i];
		}
	}

	return max;
}
