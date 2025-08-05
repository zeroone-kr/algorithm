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
    left = 0
    curr_sum = 0
    best_len = float('inf')
    answer = [0, 0]

    for right in range(n):
        curr_sum += sequence[right] 

        while curr_sum > k and left <= right:
            curr_sum -= sequence[left]
            left += 1

        if curr_sum == k:
            if right - left < best_len:
                best_len = right - left
                answer = [left, right]
            # ※ 같은 길이의 구간이 나와도 갱신하지 않으므로
            #    최초(=시작 인덱스가 가장 작은) 구간이 유지됩니다.

    return answer