#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    vector<vector<pair<int, int>>> g(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    
    vector<long long> d(n + 1, INF);
    d[1] = 0;
    
    priority_queue<pair<long long, int>,
                  vector<pair<long long, int>>,
                  greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        long long cd = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (cd != d[x]) continue;
        for (auto &e : g[x]) {
            int y = e.first;
            int w = e.second;
            if (d[y] > cd + w) {
                d[y] = cd + w;
                pq.push({d[y], y});
            }
        }
    }
    
    if (d[n] == INF) printf("impossible\n");
    else printf("%lld\n", d[n]);
    
    return 0;
}
