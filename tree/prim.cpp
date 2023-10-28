#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define V 5

// 用邻接矩阵表示图
int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};

void primMST() {
    // 存储最小生成树的边
    vector<pair<int, int>> edges;

    // 存储顶点的权值
    vector<int> key(V, INT_MAX);

    // 存储顶点是否包含在最小生成树中
    vector<bool> inMST(V, false);

    // 优先队列，根据权值排序
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 从第一个顶点开始
    int src = 0;
    pq.push({0, src});
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
                edges.push_back({u, v});
            }
        }
    }

    // 打印最小生成树的边
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : edges) {
        cout << edge.first << " - " << edge.second << "\n";
    }
}

int main() {
    primMST();

    return 0;
}
