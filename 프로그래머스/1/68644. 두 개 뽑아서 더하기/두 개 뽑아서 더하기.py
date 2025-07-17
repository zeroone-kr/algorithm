def solution(numbers):
    answer = []
    
    for idx1 in range(len(numbers)):
        for idx2 in range(idx1+1, len(numbers)):
            answer.append(numbers[idx1] + numbers[idx2])
            
    return sorted(set(answer))