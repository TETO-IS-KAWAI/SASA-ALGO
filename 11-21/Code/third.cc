#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);
long long d[21][21];
int n, m;

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        if (w < d[u][v]) d[u][v] = w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (d[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (d[k][j] == INF) continue;
                long long nd = d[i][k] + d[k][j];
                if (nd < d[i][j]) d[i][j] = nd;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) printf("-");
            else printf("%lld", d[i][j]);
            if (j < n) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
