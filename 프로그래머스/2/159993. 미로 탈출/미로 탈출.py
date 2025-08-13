from collections import deque

def solution(maps):
    H, W = len(maps), len(maps[0])

    # 좌표 찾기
    S = L = E = None
    for r in range(H):
        for c in range(W):
            ch = maps[r][c]
            if ch == 'S':
                S = (r, c)
            elif ch == 'L':
                L = (r, c)
            elif ch == 'E':
                E = (r, c)
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    def bfs(start, target_char):
        q = deque()
        q.append((start[0], start[1], 0))
        visited = [[False]*W for _ in range(H)]
        visited[start[0]][start[1]] = True

        while q:
            r, c, d = q.popleft()
            if maps[r][c] == target_char:
                return d
            for i in range(4):
                nr, nc = r + dx[i], c + dy[i]
                if 0 <= nr < H and 0 <= nc < W and not visited[nr][nc]:
                    if maps[nr][nc] != 'X':
                        visited[nr][nc] = True
                        q.append((nr, nc, d+1))
        return -1

    d1 = bfs(S, 'L')
    if d1 == -1:
        return -1
    d2 = bfs(L, 'E')
    if d2 == -1:
        return -1
    return d1 + d2
