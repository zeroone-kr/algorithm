def solution(players, m, k):
    
    n = len(players)
    arr = [ [0] * 3 for _ in range(n)]
    answer = 0
    for i in range(n):
        arr[i][0] = players[i]
        required_pc = (players[i]) // m
        need = required_pc - arr[i][1]
        
        if need > 0: 
            answer += need
            for a in range(k):
                if i+a >= n:
                    continue
                arr[i+a][1] += need 
        
    return answer