def solution(array, commands):
    answer = []
    
    for comm in commands:
        i, j, k = comm[0], comm[1], comm[2]
        
        temp = sorted(array[i-1:j])
        answer.append(temp[k-1])
        
    return answer