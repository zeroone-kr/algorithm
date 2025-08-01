def solution(points, routes):
    # 1-based → 좌표 매핑
    pts = {i+1: tuple(p) for i, p in enumerate(points)}
    
    all_paths = []  # 각 로봇의 시간별 위치 시퀀스
    for route in routes:
        path = []
        # 출발점 추가
        cur_r, cur_c = pts[route[0]]
        path.append((cur_r, cur_c))
        # 경로 따라 세그먼트별로 뽑아내기
        for next_pt in route[1:]:
            tgt_r, tgt_c = pts[next_pt]
            # r좌표부터 맞춰가고, 그 다음에 c좌표
            while cur_r != tgt_r:
                cur_r += 1 if tgt_r > cur_r else -1
                path.append((cur_r, cur_c))
            while cur_c != tgt_c:
                cur_c += 1 if tgt_c > cur_c else -1
                path.append((cur_r, cur_c))
        all_paths.append(path)
    
    # 2) 시간별 충돌 세기
    total = 0
    max_t = max(len(p) for p in all_paths)
    for t in range(max_t):
        cnt = {}
        for path in all_paths:
            if t < len(path):
                cnt[path[t]] = cnt.get(path[t], 0) + 1
        # 한 좌표에 2대 이상이면 1회 위험
        for v in cnt.values():
            if v >= 2:
                total += 1
    
    return total
