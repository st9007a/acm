#include <stdio.h>

int set_count;
int set[100001];

int get_num(char *line, int *i);
int find_root(int x);
void union_set(int x, int y);

int main ()
{
    int cases;
    char line[1001];

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d ", &set_count);

        for (int i = 1; i <= set_count; i++) {
            set[i] = i;
        }

        while(gets(line)) {
            if (line[0] == '\0') {
                break;
            }
            for (int i = 0; line[i];) {

                int x = get_num(line, &i);
                int y = get_num(line, &i);

                union_set(x, y);
            }
        }

        printf("%d\n", set_count);

        if (cases) {
            putchar('\n');
        }
    }

    return 0;
}

int get_num(char *line, int *i)
{
    int n = 0;
    while(line[*i] >= '0' && line[*i] <= '9') {
        n = n * 10 + (line[*i] - '0');
        (*i)++;
    }
    while (line[*i] == ' ' && line[*i] != '\0') {
        (*i)++;
    }

    return n;
}

int find_root(int x)
{
    if (set[x] == x) {
        return x;
    }

    return set[x] = find_root(set[x]);
}

void union_set(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if (x != y) {
        set[x] = y;
        set_count--;
    }
}
