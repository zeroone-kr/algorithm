n = int(input())

records=list()
for i in range(n):
    records.append(input().split())

records.sort(key=lambda x: (-int(x[1]), int(x[2]),-int(x[3]), x[0]))

for rec in records:
    print(rec[0])

