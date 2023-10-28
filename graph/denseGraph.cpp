#include <iostream>
#include <vector>

class DenseGraph {
private:
    int n;               // 节点数量
    int m;               // 边数量
    bool directed;       // 是否为有向图
    std::vector<std::vector<bool>> g;  // 邻接矩阵的值用 true 和 false 表示

public:
    DenseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
        // 初始化邻接矩阵，所有元素设为false
        g.assign(n, std::vector<bool>(n, false));
    }

    ~DenseGraph() {}

    int V() const { return n; }    // 返回节点数量
    int E() const { return m; }    // 返回边数量

    void addEdge(int v, int w) {
        // 添加边，检查是否已经存在边
        if (hasEdge(v, w)) {
            return;
        }

        g[v][w] = true;

        // 如果是无向图，还需要在w和v之间添加一条边
        if (!directed) {
            g[w][v] = true;
        }

        m++;  // 更新边的数量
    }

    bool hasEdge(int v, int w) const {
        // 查询是否存在边
        return g[v][w];
    }
};

int main() {
    DenseGraph graph(5, false);  // 无向图，5个节点

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    std::cout << "Graph has " << graph.V() << " vertices and " << graph.E() << " edges." << std::endl;

    std::cout << "Edges in the graph:" << std::endl;
    for (int i = 0; i < graph.V(); ++i) {
        for (int j = i + 1; j < graph.V(); ++j) {
            if (graph.hasEdge(i, j)) {
                std::cout << i << " - " << j << std::endl;
            }
        }
    }

    return 0;
}
