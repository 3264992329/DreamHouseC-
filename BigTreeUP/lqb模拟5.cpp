#include <stdio.h>

#define ROWS 30
#define COLS 40

// 检查坐标是否在矩阵内，并且该位置是否是 0
int is_valid(int x, int y, int matrix[ROWS][COLS]) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && matrix[x][y] == 0;
}

// 进行传染
void infect(int x, int y, int matrix[ROWS][COLS]) {
    matrix[x][y] = 2;  // 将当前位置设为 2

    // 上下左右四个方向传染
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny, matrix)) {
            infect(nx, ny, matrix);  // 递归地传染周围的 0
        }
    }
}

int count_twos(int matrix[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 2) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int matrix[ROWS][COLS] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1}
    };

    // 开始传染过程
    infect(0, 0, matrix);

    int result = count_twos(matrix);
    printf("最终矩阵中有 %d 个 2\n", result);

    return 0;
}
``

