#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

int n, m;
const long long INF = (1LL << 60);

int main() {
    scanf("%d%d", &n, &m);

    vector<Edge> e(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
    }

    vector<long long> d(n + 1, INF);
    d[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int x = e[j].u, y = e[j].v;
            long long w = e[j].w;
            if (d[x] == INF) continue;
            if (d[y] > d[x] + w) d[y] = d[x] + w;
        }
    }

    bool cyc = false;
    for (int j = 0; j < m; j++) {
        int x = e[j].u, y = e[j].v;
        long long w = e[j].w;
        if (d[x] == INF) continue;
        if (d[y] > d[x] + w) {
            cyc = true;
            break;
        }
    }

    if (cyc) printf("cycle\n");
    else printf("%lld\n", d[n]);

    return 0;
}
