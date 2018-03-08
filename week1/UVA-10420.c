#include <stdio.h>
#include <string.h>

struct country { char name[76]; };

struct country c[2001] = {0};

int main()
{
    int count, count_cpy;
    int cptr = 0;
    char line[76] = {0};

    scanf("%d", &count);
    fgets(line, 76, stdin);

    while(cptr < count) {
        int ptr = 0;
        int start, end;

        fgets(line, 76, stdin);

        while (line[ptr] == ' ') {
            ptr++;
        }
        start = ptr;

        while (line[ptr] != ' ') {
            ptr++;
        }
        end = ptr;

        strncpy(c[cptr].name, line + start, end - start);
        cptr++;
    }

    for (int i = cptr - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(c[j].name, c[j + 1].name) > 0) {
                char tmp[76];
                strncpy(tmp, c[j].name, 76);
                strncpy(c[j].name, c[j + 1].name, 76);
                strncpy(c[j + 1].name, tmp, 76);
            }
        }
    }

    for (int i = 0; i < cptr;) {
        int j;
        int total = 1;
        for (j = i + 1; j < cptr; j++) {
            if (strcmp(c[i].name, c[j].name)) {
                break;
            }
            total++;
        }
        printf("%s %d\n", c[i].name, total);
        i = j;
    }

    return 0;
}
