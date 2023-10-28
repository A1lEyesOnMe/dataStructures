#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int V; // 顶点数
    std::vector<std::vector<int>> adjList; // 邻接表

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // 无向图需要双向添加
    }

    void BFS(int startVertex) {
        std::vector<bool> visited(V, false); // 记录节点是否被访问过
        std::queue<int> queue;

        queue.push(startVertex);
        visited[startVertex] = true;

        while (!queue.empty()) {
            int currentVertex = queue.front();
            queue.pop();

            std::cout << currentVertex << " ";

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    queue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    std::cout << "Breadth-First Traversal starting from vertex 0:" << std::endl;
    graph.BFS(0);

    return 0;
}
