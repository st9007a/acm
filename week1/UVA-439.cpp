#include <cstdio>
#include <queue>

using namespace std;

struct Position {
    int x;
    int y;
};

const int dir[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

int BFS(Position from, Position to);

int main()
{
    char start[3], end[3];
    Position s, e;

    while (scanf("%s %s", start, end) != EOF) {
        s.x = start[0] - 'a';
        s.y = start[1] - '1';
        e.x = end[0] - 'a';
        e.y = end[1] - '1';

        if (start[0] == end[0] && start[1] == end[1]) {
            printf("To get from %s to %s takes 0 knight moves.\n", start, end);
        } else {
            printf("To get from %s to %s takes %d knight moves.\n", start, end, BFS(s, e));
        }
    }
}

int BFS(Position from, Position to)
{
    queue<Position> q;
    Position curr, next;
    int visited[9][9] = {0};

    q.push(from);

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr.x == to.x && curr.y == to.y) {
            return visited[curr.x][curr.y];
        }

        for (int i = 0; i < 8; i++) {
            next.x = curr.x + dir[i][0];
            next.y = curr.y + dir[i][1];
            if (next.x < 0 || next.x >= 8 || next.y < 0 || next.y >= 8) {
                continue;
            }
            if (visited[next.x][next.y] == 0) {
                visited[next.x][next.y] = visited[curr.x][curr.y] + 1;

                q.push(next);
            }
        }

    }
    return visited[curr.x][curr.y];
}
