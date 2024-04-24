#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mod = 1000000007;
int color[100010];
long long ans[100010];
int black_below[100010];
vector<pair<int, int>> graph[100010];

void dfs_1(int node, int parent){
    black_below[node] = color[node];
    for (auto& nei_pair : graph[node]){
        int nei = nei_pair.first, weight = nei_pair.second;
        if (nei != parent){
            dfs_1(nei, node);
            black_below[node] += black_below[nei]; //该node下的所有black
            ans[1] = (ans[1] + static_cast<long long>(black_below[nei]) * weight) % mod;
        }
    }
}

void dfs_2(int node, int parent, long long total_black, long long weight_from_parent){
    if (node != 1) {
        ans[node] = (ans[parent] - static_cast<long long>(black_below[node]) * weight_from_parent
                    + static_cast<long long>(total_black - black_below[node]) * weight_from_parent) % mod;
        if (ans[node] < 0) ans[node] += mod; //基于计算出的ans_1，更新节点1相邻节点的ans值
    }
    for (auto& nei_pair : graph[node]){
        int nei = nei_pair.first, weight = nei_pair.second;
        if (nei != parent) {
            dfs_2(nei, node, total_black, weight);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    fill(color, color + n + 1, 0);
    fill(ans, ans + n + 1, 0);
    fill(black_below, black_below + n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        graph[i].clear();
    }

    for (int i = 1; i <= n; ++i){
        cin >> color[i];
    }

    for (int i = 1; i < n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    dfs_1(1, -1);

    long long total_black = 0;
    for (int i = 1; i <= n; ++i){
        total_black += color[i];
    }

    dfs_2(1, -1, total_black, 0);

    for (int i = 1; i <= n; ++i){
        cout << ans[i] << '\n';
    }

    return 0;
}
