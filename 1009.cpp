#include <cstdio>

int const max_length = 1200;
struct Node {
    int v;
    int l;
    Node(int v, int l):v(v), l(l) {}
}tables[max_length];
int now_length = 0;

int width;
Node last_line[max_length];
int last_line_length = 0;
Node this_line[max_length];
int this_line_length = 0;
Node next_line[max_length];
int next_line_length = 0;

void input() {
    now_length = 0;
    int v, l;
    while (1) {
        scanf("%d %d\n", &v, &l);
        if (v == 0 && l == 0) break;
        tables[now_length ++] = Node(v, l);
    }
    return ;
}

void calculate() {
    return ;
}

int main() {
    while (1) {
        scanf("%d\n", &width);
        if (width) {
            printf("%d\n", width);
            input();
            calculate();
        } else {
            printf("0\n");
            break;
        }
    }
    return ;
}
