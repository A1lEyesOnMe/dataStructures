#include <iostream>
#include <vector>
#include <list>

class SparseGraph {
private:
    int n;               // 节点数量
    int m;               // 边数量
    bool directed;       // 是否为有向图
    std::vector<std::list<int>> g;  // 邻接表表示的图

public:
    SparseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
        // 初始化邻接表
        g.resize(n);
    }

    ~SparseGraph() {}

    int V() const { return n; }    // 返回节点数量
    int E() const { return m; }    // 返回边数量

    void addEdge(int v, int w) {
        // 添加边
        g[v].push_back(w);

        // 如果是无向图，还需要在w和v之间添加一条边
        if (!directed && v != w) {
            g[w].push_back(v);
        }

        m++;  // 更新边的数量
    }

    bool hasEdge(int v, int w) const {
        // 查询是否存在边
        for (int node : g[v]) {
            if (node == w) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    SparseGraph graph(5, false);  // 无向图，5个节点

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    std::cout << "Graph has " << graph.V() << " vertices and " << graph.E() << " edges." << std::endl;

    std::cout << "Edges in the graph:" << std::endl;
    for (int i = 0; i < graph.V(); ++i) {
        for (int node : graph.g[i]) {
            if (i < node) {
                std::cout << i << " - " << node << std::endl;
            }
        }
    }

    return 0;
}
