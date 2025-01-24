from collections import deque

def is_valid_move(x, y, rows, cols, visited, grid, silas_power):
    if x < 0 or x >= rows or y < 0 or y >= cols:
        return False
    if visited[x][y]:
        return False
    if grid[x][y] == '#':
        return False
    if grid[x][y].isdigit() and int(grid[x][y]) > silas_power:
        return False
    return True

def bfs(start_x, start_y, rows, cols, grid, silas_power):
    visited = [[False for _ in range(cols)] for _ in range(rows)]
    queue = deque([(start_x, start_y, 0)])  # (x, y, steps)
    visited[start_x][start_y] = True

    while queue:
        x, y, steps = queue.popleft()

        if grid[x][y] == 'K':
            return steps

        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if is_valid_move(nx, ny, rows, cols, visited, grid, silas_power):
                visited[nx][ny] = True
                queue.append((nx, ny, steps + 1))

    return -1  # Não encontrou o caminho

def main():
    silas_power = int(input())
    rows, cols = map(int, input().split())
    grid = []

    start_x, start_y = -1, -1

    for i in range(rows):
        line = input().split()
        grid.append(line)
        for j in range(cols):
            if line[j] == 'S':
                start_x, start_y = i, j

    result = bfs(start_x, start_y, rows, cols, grid, silas_power)

    if result == -1:
        print("N")
    else:
        print(result)

if __name__ == "__main__":
    main()

