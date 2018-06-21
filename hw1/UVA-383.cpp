#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct Node {
    vector<int> conn;
};

map<string, int> record;

int BFS(int start, int end, Node network[]);

int main()
{
    int cases, no = 1;
    int m, n ,p;
    string node1, node2;

    cout << "SHIPPING ROUTES OUTPUT\n\n";

    cin >> cases;
    while (cases--) {
        cout << "DATA SET  " << no++ << "\n\n";
        cin >> m >> n >> p;

        Node network[30];
        int cost;

        for (int i = 0; i < m; i++) {
            cin >> node1;
            record[node1] = i;
        }

        for (int i = 0; i < n; i++) {
            cin >> node1 >> node2;

            network[record[node1]].conn.push_back(record[node2]);
            network[record[node2]].conn.push_back(record[node1]);
        }

        for (int i = 0; i < p; i++) {
            cin >> cost >> node1 >> node2;

            int leg = BFS(record[node1], record[node2], network);
            if (leg) {
                cout << "$" << cost * leg * 100 << "\n";
            } else {
                cout << "NO SHIPMENT POSSIBLE\n";
            }
        }
        cout << endl;
    }
    cout << "END OF OUTPUT\n";
}

int BFS(int start, int end, Node network[])
{
    queue<int> q;
    int visited[1000] = {0};

    q.push(start);

    while (!q.empty()) {
        int curr = q.front();

        q.pop();

        for (int next : network[curr].conn) {
            if (visited[next] == 0) {
                visited[next] = visited[curr] + 1;
                if (next == end) {
                    return visited[next];
                }
                q.push(next);
            }
        }
    }

    return 0;
}
