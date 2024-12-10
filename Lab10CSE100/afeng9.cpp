//chmod 700 Grade
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Graph {
private:
    int V;  // Number of vertices
    std::vector<std::vector<int> > adj;     // Adjacent list for original graph
    std::vector<std::vector<int> > transpose;  // Adjacent list for transposed graph
    
    // Helper functions for Kosaraju's algorithm
    void fillOrder(int v, std::vector<bool>& visited, std::stack<int>& Stack) {
        visited[v] = true;
        
        for (size_t j = 0; j < adj[v].size(); j++) {
            int i = adj[v][j];
            if (!visited[i]) {
                fillOrder(i, visited, Stack);
            }
        }
        Stack.push(v);
    }
    
    void DFSUtil(int v, std::vector<bool>& visited, std::vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        
        for (size_t j = 0; j < transpose[v].size(); j++) {
            int i = transpose[v][j];
            if (!visited[i]) {
                DFSUtil(i, visited, component);
            }
        }
    }

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
        transpose.resize(V);
    }
    
    void addEdge(int v, int w) {
        if (v >= 0 && v < V && w >= 0 && w < V) {
            adj[v].push_back(w);
            transpose[w].push_back(v);
        }
    }
    
    std::vector<int> findSCCs() {
        std::vector<int> sccIds(V);
        std::stack<int> Stack;
        std::vector<bool> visited(V, false);
        
        // First DFS to fill the stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                fillOrder(i, visited, Stack);
            }
        }
        
        // Reset visited array for second DFS
        std::fill(visited.begin(), visited.end(), false);
        
        // Process vertices in order of finishing time
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();
            
            if (!visited[v]) {
                std::vector<int> component;
                DFSUtil(v, visited, component);
                
                // Find minimum vertex ID in this component
                int minId = *std::min_element(component.begin(), component.end());
                
                // Assign SCC ID to all vertices in this component
                for (size_t j = 0; j < component.size(); j++) {
                    int vertex = component[j];
                    sccIds[vertex] = minId;
                }
            }
        }
        
        return sccIds;
    }
};

int main() {
    int V, E;
    std::cin >> V >> E;
    
    Graph g(V);
    
    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v;
        std::cin >> u >> v;
        if (u >= 0 && u < V && v >= 0 && v < V) {
            g.addEdge(u, v);
        }
    }
    
    // Find and output SCCs
    std::vector<int> sccIds = g.findSCCs();
    
    // Output SCC IDs - modified to print each ID on a new line
    for (int i = 0; i < V; i++) {
        std::cout << sccIds[i] << std::endl;  // Changed to print each ID on a new line
    }
    
    return 0;
}
