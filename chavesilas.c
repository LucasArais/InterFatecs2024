#include <stdio.h>
#include <stdlib.h>

#define MAX 80

typedef struct {
    int x, y, steps;
} Node;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int is_valid_move(int x, int y, int rows, int cols, int visited[MAX][MAX], char grid[MAX][MAX], int silas_power) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) return 0;
    if (visited[x][y]) return 0;
    if (grid[x][y] == '#') return 0;
    if (grid[x][y] >= '0' && grid[x][y] <= '9' && grid[x][y] - '0' > silas_power) return 0;
    return 1;
}

int bfs(int start_x, int start_y, int rows, int cols, char grid[MAX][MAX], int silas_power) {
    int visited[MAX][MAX] = {0};
    Node queue[MAX * MAX];
    int front = 0, rear = 0;

    queue[rear++] = (Node){start_x, start_y, 0};
    visited[start_x][start_y] = 1;

    while (front < rear) {
        Node current = queue[front++];

        if (grid[current.x][current.y] == 'K') {
            return current.steps;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (is_valid_move(nx, ny, rows, cols, visited, grid, silas_power)) {
                visited[nx][ny] = 1;
                queue[rear++] = (Node){nx, ny, current.steps + 1};
            }
        }
    }

    return -1; 
}

int main() {
    int silas_power, rows, cols;
    char grid[MAX][MAX];

    scanf("%d", &silas_power);
    scanf("%d %d", &rows, &cols);

    int start_x = -1, start_y = -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
    }

    int result = bfs(start_x, start_y, rows, cols, grid, silas_power);

    if (result == -1) {
        printf("N\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
