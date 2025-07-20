def solution(participant, completion):
    
    part_dict = dict()
    for part in participant:
        try:
            part_dict[part] +=1
        except:
            part_dict[part] =1 
    
    for comp in completion:
        part_dict[comp] -= 1
        

    for k, v in part_dict.items():
        if v == 1:
            return k