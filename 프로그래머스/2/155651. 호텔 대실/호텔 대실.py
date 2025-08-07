import heapq 

def solution(book_time):

    def to_minutes(t):
        h, m = map(int, t.split(':'))
        return h * 60 + m

    intervals = sorted(
        [(to_minutes(start), to_minutes(end)) for start, end in book_time],
        key=lambda x: x[0]
    )
    heap = []

    for start, end in intervals:
        if heap and heap[0] <= start:
            heapq.heappop(heap)
        heapq.heappush(heap, end + 10)

    return len(heap)