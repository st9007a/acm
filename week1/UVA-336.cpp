#include <cstdio>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    vector<int> conn;
};

map<int, int> record;

int BFS(int start, int ttl, Node network[]);

int main()
{

    int pairs;
    int node1, node2;
    int start, ttl;

    int cases = 0;

    while (scanf("%d", &pairs)) {
        if (pairs == 0) {
            break;
        }

        Node network[1000];
        int numOfNodes = 0;

        record.clear();

        for (int i = 0; i < pairs; i++) {
            scanf("%d %d", &node1, &node2);

            if (record.find(node1) == record.end()) {
                record[node1] = numOfNodes++;
            }

            if (record.find(node2) == record.end()) {
                record[node2] = numOfNodes++;
            }

            network[record[node1]].conn.push_back(record[node2]);
            network[record[node2]].conn.push_back(record[node1]);
        }

        while (scanf("%d %d", &start, &ttl)) {
            if (start == 0 && ttl == 0) {
                break;
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++cases, numOfNodes - BFS(start, ttl, network), start, ttl);
        }

    }

}

int BFS(int start, int ttl, Node network[])
{

    queue<int> q;
    int visited[1000] = {0};
    int numOfReach = 1;

    q.push(record[start]);
    visited[record[start]] = 1;

    while (!q.empty()) {
        int curr = q.front();

        if (visited[curr] > ttl) {
            return numOfReach;
        }

        q.pop();

        for (int node : network[curr].conn) {
            if (visited[node] == 0) {
                visited[node] = visited[curr] + 1;
                q.push(node);
                numOfReach++;
            }
        }
    }
    return numOfReach;
}
