def solution(sequence, k):
    answer = []
#     sum=0 
#     indexes = []
#     for i in range(0, len(sequence)):
#         for j in range(i, len(sequence)):
#             indexes.append((i,j)) 
    
#     _min = 1000000000000
#     for start, end in indexes:
#         sum=0 
#         for i in range(start, end+1):
#             sum = sum + sequence[i]
#         if sum == k:
#             if end-start < _min:
#                 _min = end-start
#                 answer = (start, end)
    
    
    n = len(sequence)
    left =0 
    current_sum =0 
    min_length = float('inf')
    answer  = [0,0]
    
    for right in range(n):
        current_sum += sequence[right]
        
        while current_sum >= k:
            
            if current_sum == k:
                length = right - left + 1
                
                if length < min_length:
                    min_length = length
                    
                    answer = [left, right]
    
            current_sum = current_sum - sequence[left]
            left = left + 1
    
    return answer