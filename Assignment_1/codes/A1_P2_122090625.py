MOD = 998244353

def num_rec(a, b):
    if a <= 0 or b <= 0:
        return 0
    return a * b * (a + 1) * (b + 1) // 4

n, m, p = map(int, input().split())
result = 0

for _ in range(p):
    x, y, k = map(int, input().split())

    total = num_rec(m, n)
    left = num_rec(n, y - 1)
    right = num_rec(n, m - y)
    up = num_rec(x - 1, m)
    down = num_rec(m, n - x)
    left_down = num_rec(y - 1, n - x)
    left_up = num_rec(x - 1, y - 1)
    right_up = num_rec(x - 1, m - y)
    right_down = num_rec(m - y, n - x)

    temp = (total - left - right - up - down + left_down + left_up + right_up + right_down) * k
    result =  (result + temp) % MOD

print(result)
