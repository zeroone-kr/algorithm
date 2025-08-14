from collections import deque

def solution(arr):
    
    answer = []
    
    cur = arr[0]
    answer.append(cur)
    for E in arr:
        if cur != E:
            answer.append(E)
            cur = E
    
    return answer