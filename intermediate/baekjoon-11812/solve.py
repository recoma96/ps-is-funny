import sys

input = sys.stdin.readline

mem_pow = []
mem_pow_sum = []

def set_pow(K):
    mem_pow.append(1)
    mem_pow_sum.append(1)
    x = 1
    while x <= 10**18:
        x *= K
        mem_pow.append(x)
        mem_pow_sum.append(mem_pow_sum[-1] + x)

def solve(N, K, x, y):
    def get_depth(e):
        depth = 0
        while True:
            min_v = mem_pow_sum[depth]
            if e <= min_v:
                break
            depth += 1
        return depth
    
    def get_parent(e, d):
        if e == 1:
            return 1, 0
        if e <= K + 1:
            return 1, 0
        num = (e - mem_pow_sum[d - 1] - 1) // K
        return mem_pow_sum[d - 2] + 1 + num, d - 1
    
    ans = 0

    # depth가 더 큰 값이 x
    x_d, y_d = get_depth(x), get_depth(y)
    if y_d > x_d:
        x, y = y, x
        x_d, y_d = y_d, x_d

    while x_d > y_d:
        x, x_d = get_parent(x, x_d)
        ans += 1

    while x != y:
        prev_x, prev_y = x, y
        x, x_d = get_parent(x, x_d)
        y, y_d = get_parent(y, y_d)

        if prev_x != x:
            ans += 1
        if prev_y != y:
            ans += 1

    return ans

if __name__ == "__main__":
    N, K, Q = map(int, input()[:-1].split())
    if K > 1:
        set_pow(K)
    for _ in range(Q):
        x, y = map(int, input()[:-1].split())
        if K > 1:
            print(solve(N, K, x, y))
        else:
            print(abs(x - y))