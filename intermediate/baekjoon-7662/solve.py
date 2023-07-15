from typing import Optional
import sys
import heapq

input = sys.stdin.readline


def pop(q, removed, qt):
    while q:
        v, idx = heapq.heappop(q)
        if qt == "max":
            v = -v
        if not removed[idx]:
            removed[idx] = True
            return v
    return None

def solve():
    n = int(input())
    cnt = 0
    min_q, max_q = [], []
    is_removed = [False] * n

    for _ in range(n):
        s = input()[:-1].split()
        match s[0]:
            case "I":
                v = int(s[1])
                heapq.heappush(min_q, (v, cnt))
                heapq.heappush(max_q, (-v, cnt))
                cnt += 1
            case "D":
                match int(s[1]):
                    case 1:
                        pop(max_q, is_removed, "max")
                    case -1:
                        pop(min_q, is_removed, "min")

    max_v = pop(max_q, is_removed, "max")
    min_v = pop(min_q, is_removed, "min")
    if max_v is None and min_v is None:
        print('EMPTY')
        return
    elif min_v is None:
        min_v = max_v
    elif max_v is None:
        max_v = min_v
    print(f'{max_v} {min_v}')

t = int(input())
for _ in range(t):
    solve()