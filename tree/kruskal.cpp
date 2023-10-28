#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 用于表示图中的一条边
struct Edge {
    int src, dest, weight;
};

// 用于比较两条边的权值，以便排序
bool compareEdges(const Edge& edge1, const Edge& edge2) {
    return edge1.weight < edge2.weight;
}

class Graph {
    int V; // 顶点数
    vector<Edge> edges; // 存储边的容器

public:
    Graph(int vertices) : V(vertices) {}

    // 添加一条边到图中
    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    // 查找顶点的根节点
    int findRoot(vector<int>& parent, int i) {
        while (parent[i] != i) {
            i = parent[i];
        }
        return i;
    }

    // 将两个集合合并
    void unionSets(vector<int>& parent, int root1, int root2) {
        parent[root1] = root2;
    }

    // 执行Kruskal算法
    void kruskalMST() {
        // 按权值对边进行排序
        sort(edges.begin(), edges.end(), compareEdges);

        // 存储最小生成树的边
        vector<Edge> result;

        // 存储每个顶点的根节点
        vector<int> parent(V);

        // 初始化每个顶点为单独的集合
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }

        // 遍历所有边
        for (const Edge& edge : edges) {
            int root1 = findRoot(parent, edge.src);
            int root2 = findRoot(parent, edge.dest);

            // 如果顶点的根节点不同，说明这条边不会形成环
            if (root1 != root2) {
                result.push_back(edge);
                unionSets(parent, root1, root2);
            }
        }

        // 打印最小生成树的边
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (const Edge& edge : result) {
            cout << edge.src << " - " << edge.dest << "\n";
        }
    }
};

int main() {
    // 创建一个包含4个顶点的图
    Graph graph(4);

    // 添加边到图中
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // 执行Kruskal算法
    graph.kruskalMST();

    return 0;
}
