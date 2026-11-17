import sys
from collections import deque
d = sys.stdin.buffer.read().split()
n, m = int(d[0]), int(d[1])
adj = [[] for _ in range(n + 1)]
deg = [0] * (n + 1)
for i in range(m):
    a, b = int(d[2 + 2*i]), int(d[3 + 2*i])
    adj[a].append(b); deg[b] += 1
dp = [0] * (n + 1); dp[1] = 1
q = deque(v for v in range(1, n + 1) if not deg[v])
while q:
    u = q.popleft()
    for v in adj[u]:
        dp[v] = (dp[v] + dp[u]) % (10**9 + 7)
        deg[v] -= 1
        if not deg[v]: q.append(v)
print(dp[n])