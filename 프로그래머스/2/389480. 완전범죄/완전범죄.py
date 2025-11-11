def solution(info, n, m):

    dp = [[False] * m for _ in range(n)]
    dp[0][0] = True

    for ai, bi in info:
        nxt = [[False] * m for _ in range(n)]
        for a in range(n):
            row = dp[a]
            for b in range(m):
                if not row[b]:
                    continue

                na = a + ai
                if na < n:
                    nxt[na][b] = True

                nb = b + bi
                if nb < m:
                    nxt[a][nb] = True
        dp = nxt


    for a in range(n):
        if any(dp[a][b] for b in range(m)):
            return a
    return -1