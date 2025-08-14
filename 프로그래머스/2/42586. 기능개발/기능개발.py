def solution(progresses, speeds):
    answer = []
    
    todo = []
    required_days = []
    for E in progresses:
        todo.append(100 - E)
    
    for i in range(len(todo)):
        if todo[i] % speeds[i] == 0:
            required_days.append(todo[i] // speeds[i])
        else: 
            required_days.append((todo[i] // speeds[i])+1 )
    
    # print(required_days)
    cur = required_days[0]
    i = 0
    for r in required_days:
        if cur < r: 
            answer.append(i)
            cur = r
            i =0
        i= i +1
        
    answer.append(len(progresses)-sum(answer))
    return answer