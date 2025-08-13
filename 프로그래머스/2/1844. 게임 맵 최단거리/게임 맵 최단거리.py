from collections import deque

def solution(maps):
    answer = -1
    start = (0, 0, 1)
    maxR, maxC = len(maps) , len(maps[0])
    end = (maxR-1, maxC-1)
    
    dr = [-1,1, 0, 0 ]
    dc = [0, 0, -1, 1]
    
    q = deque()
    visited = [ [0]*maxC for _ in range(maxR) ]
    q.append(start)
    visited[0][0] = 1

    while q:
        cur = q.popleft()
        r, c, d = cur[0], cur[1], cur[2]
        
        if (r,c ) == end:
            return d
        
        for i in range(4):
            newr = r + dr[i]
            newc = c + dc[i]    
            
            if 0 <= newr < maxR and 0 <= newc < maxC:
                if visited[newr][newc] == 0 and maps[newr][newc]:
                    q.append((newr,newc, d+1))
                    visited[newr][newc] = 1
                    
    return answer