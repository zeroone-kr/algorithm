def solution(numbers):
    strs = list(map(str, numbers))
    strs.sort(key=lambda x: x*4, reverse=True)
    return '0' if strs[0] == '0' else ''.join(strs)
