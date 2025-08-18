from itertools import permutations
from functools import cmp_to_key

def solution(numbers):
    answer = ''
    
    # temp = map(str, numbers)
    # k = list(temp)
    # print(k)
    # print(k.sort())
    
    
    # max = 0
    # tmp1 = ''
    # for k in list(permutations(numbers)):
    #     # tmp1 = ''
    #     tmp= tmp1.join(map(str,k))
    #     # print(answer)
    #     if max < int(tmp):
    #         max = int(tmp)
    #         answer = tmp
      
        
    
    strs = list(map(str, numbers))
    
    def cmp(a, b):
        if a + b > b + a:  
            return -1
        elif a + b < b + a:
            return 1
        else:
            return 0

    strs.sort(key=cmp_to_key(cmp))


    if strs[0] == '0':
        return '0'
    return ''.join(strs)
