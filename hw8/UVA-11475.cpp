#include <cstdio>
#include <cstring>

int f[100005];

int KMP(char *s, char *r);

int main()
{
    char str[100005];
    char rstr[100005];

    while (scanf("%s", str) != EOF) {
        int length  = strlen(str);

        for (int i = length - 1; i >= 0; i--) {
            rstr[length - 1 - i] = str[i];
        }
        rstr[length] = '\0';

        int cut = KMP(str, rstr);

        printf("%s%s\n", str, rstr + cut + 1);

    }
}

int KMP(char *s, char *r)
{
    f[0] = -1;

    for (int i = 1, curPos = -1; r[i]; i++) {
        while (curPos >= 0 && r[curPos + 1] != r[i]) {
            curPos = f[curPos];
        }

        if (r[i] == r[curPos + 1]) {
            curPos++;
        }

        f[i] = curPos;
    }

    int i, curPos;

    for (i = 0, curPos = -1; s[i]; i++) {
        while (curPos >= 0 && r[curPos + 1] != s[i]) {
            curPos = f[curPos];
        }

        if (r[curPos + 1] == s[i]) {
            curPos++;
        }
    }

    return curPos;
}
