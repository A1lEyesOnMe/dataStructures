#include <iostream>
#include <vector>
#include <stack>

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

    void DFS(int startVertex) {
        std::vector<bool> visited(V, false); // 记录节点是否被访问过
        std::stack<int> stack;

        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

            if (!visited[currentVertex]) {
                std::cout << currentVertex << " ";
                visited[currentVertex] = true;

                for (int neighbor : adjList[currentVertex]) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
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

    std::cout << "Depth-First Traversal starting from vertex 0:" << std::endl;
    graph.DFS(0);

    return 0;
}
