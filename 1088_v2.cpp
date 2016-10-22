#include <iostream>
#include <cstring>
using namespace std;

const int max_length = 120;
const int max_height = 20000;
const int delta_x[4] = {0, 1, 0, -1};
const int delta_y[4] = {1, 0, -1, 0};

int mountain[max_length][max_length];
int path[max_length][max_length];
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

int find_path(int r, int c) {
    if (path[r][c] > 0) {
        return path[r][c];
    }
    int path_temp = 1;
    for (int k = 0; k < 4; k++) {
        int r_tar = r + delta_x[k];
        int c_tar = c + delta_y[k];
        if (mountain[r_tar][c_tar] < mountain[r][c]) {
            path_temp = max(find_path(r_tar, c_tar) + 1, path_temp);
        }
    }
    path[r][c] = path_temp;
    return path_temp;
}

int main() {
    cin >> R >> C;
    memset(path, -1, sizeof(path));
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
            int path_temp = find_path(i, j);
            long_path_dis = max(long_path_dis, path_temp);
        }
    }
    cout << long_path_dis << endl;
    return 0;
}
