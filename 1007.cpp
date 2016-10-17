#include <cstdio>
#include <cstring>
#include <cstdlib>

char* mystrdup(const char *buf) {
    int n = strlen(buf);
    char *a = (char*)malloc(n + 1);
    memcpy(a, buf, n);
    a[n] = '\0';
    return a;
}

struct record {
    int value;
    char *str;
}recs[200];

int inline char2rank(char c) {
    return (c == 'A')?
                0:
                (
                    (c == 'C')?
                        1:
                        (
                            (c == 'G')?2:3
                        )
                );
}

int cal(const char buf[], const int len) {
    int countArr[4] = {0, 0, 0, 0};
    countArr[char2rank(buf[0])] ++;
    int res = 0;
    for (int i = 1; i < len; i++) {
        // printf("debug %d\n", char2rank(buf[i]));
        for (int j = char2rank(buf[i]) + 1; j < 4; j++) {
            res += countArr[j];
        }
        countArr[char2rank(buf[i])] ++;
    }
    return res;
}

int com(const void *a1, const void *a2) {
    record *t1 = (record*)a1;
    record *t2 = (record*)a2;
    return (t1->value == t2->value)?
                0:
                (
                    (t1->value > t2->value)?1:-1
                );
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    char buffer[n + 1];
    for (int i = 0; i < m; i++) {
        scanf("%s", buffer);
        recs[i].str = mystrdup(buffer);
        recs[i].value = cal(buffer, n);
    }
    qsort(recs, m, sizeof(record), com);
    for (int i = 0; i < m; i++) {
        printf("%s\n", recs[i].str);
        // printf("%d\n", recs[i].value);
    }
}
