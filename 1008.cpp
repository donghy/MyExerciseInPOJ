#include <cstdio>
#include <cstring>

int const month_size = 19;
const char* months[month_size] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

int const word_size = 20;
const char* words[word_size] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int findMonth(const char* word) {
    for(int i = 0; i < month_size; i++) {
        if (strcmp(word, months[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int inline findDays(int month_rank) {
    return month_rank * 20;
}

int const hYear = 365;
int const tYear = 260;

int main() {
    int N;
    char mon[12];
    int number, year;
    scanf("%d\n", &N);
    printf("%d\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d. %s %d", &number, mon, &year);
        // printf("%d %s %d\n", number, word, year);
        int d = number + findDays(findMonth(mon)) + year * hYear;
        printf("%d %s %d\n", (d % tYear) % 13 + 1, words[(d % tYear) % 20], d / tYear);
    }
    return 0;
}
