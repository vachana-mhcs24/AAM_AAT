#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, a, b, M = 1000000007, f = 0, r = 0;
    if (scanf("%d%d", &n, &m) != 2) return 0;

    int *head = malloc((n + 1) * sizeof(int));
    int *deg = calloc(n + 1, sizeof(int));
    int *dp = calloc(n + 1, sizeof(int));
    int *q = malloc((n + 1) * sizeof(int));
    int *to = malloc(m * sizeof(int));
    int *nxt = malloc(m * sizeof(int));

    for (int i = 0; i <= n; i++) head[i] = -1;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        to[i] = b;
        nxt[i] = head[a];
        head[a] = i;
        deg[b]++;
    }

    dp[1] = 1;
    for (int i = 1; i <= n; i++)
        if (!deg[i]) q[r++] = i;

    while (f < r) {
        int u = q[f++];
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            dp[v] = (dp[v] + dp[u]) % M;
            if (!--deg[v]) q[r++] = v;
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
