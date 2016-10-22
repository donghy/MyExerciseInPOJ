#include <iostream>
#include <cstring>
using namespace std;

const int max_length = 120;
const int max_height = 20000;
const int delta_x[4] = {0, 1, 0, -1};
const int delta_y[4] = {1, 0, -1, 0};

int mountain[max_length][max_length];
int temp[max_length][max_length];
int R, C;

inline int max(int a, int b) {
    return (a > b)?a:b;
}

struct Pos {
    int r;
    int c;
    Pos() {};
    Pos(int r, int c):r(r), c(c) {}
};

Pos stack[max_length * max_length];
int stack_size = 0;
int find_path(int r, int c) {
    memset(temp, -1, sizeof(temp));
    stack[stack_size ++] = Pos(r, c);
    temp[r][c] = 1;
    int path = 0;
    while (stack_size > 0) {
        Pos seed = stack[-- stack_size];
        int step = temp[seed.r][seed.c];
        r = seed.r;
        c = seed.c;
        path = max(path, step);
        step ++;
        for (int i = 0; i < 4; i++) {
            int r_tar = r + delta_x[i];
            int c_tar = c + delta_y[i];
            if (mountain[r][c] > mountain[r_tar][c_tar]) {
                if (step > temp[r_tar][c_tar]) {
                    temp[r_tar][c_tar] = step;
                    stack[stack_size ++] = Pos(r_tar, c_tar);
                }
            }
        }
        // cout << stack_size << ' ' << step << endl;
    }
    return path;
}

int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> mountain[i][j];
        }
    }
    for (int i = 0; i <= R+1; i++) {
        mountain[i][0] = mountain[i][C + 1] = max_height;
    }
    for (int j = 0; j <= C+1; j++) {
        mountain[0][j] = mountain[R + 1][j] = max_height;
    }

    // for (int i = 0; i <= R+1; i++) {
    //     for (int j = 0; j <= C+1; j++) {
    //         cout << mountain[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int long_path_dis = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            bool polar_max = true;
            for (int k = 0; k < 4; k++) {
                int neibor_height = mountain[i + delta_x[k]][j + delta_y[k]];
                if (neibor_height > mountain[i][j] && neibor_height < max_height) {
                    polar_max = false;
                    break;
                }
            }
            if (polar_max) {
                // cout << "search " << i << ' ' << j << endl;
                long_path_dis = max(long_path_dis, find_path(i, j));
            }
        }
    }
    cout << long_path_dis << endl;
    return 0;
}
