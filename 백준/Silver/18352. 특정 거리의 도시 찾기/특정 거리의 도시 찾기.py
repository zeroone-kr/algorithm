from collections import deque
import sys

input = sys.stdin.readline

city, roads, diste, start = map(int, input().split())


adjM = [[] for _ in range(city + 1)]


for _ in range(roads):
    s, d = map(int, input().split())
    adjM[s].append(d)


dist = [-1] * (city + 1)

def traverse():
    deq = deque()
    deq.append(start)
    dist[start] = 0

    while deq:
        src = deq.popleft()

        for v in adjM[src]:
            if dist[v] != -1:
                continue
            dist[v] = dist[src] + 1
            deq.append(v)

traverse()

found = False

for i in range(1, city + 1):
    if dist[i] == diste:
        print(i)
        found = True

if not found:
    print(-1)