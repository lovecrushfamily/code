#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


void initialize() {
    
}
void bfs(int startedVertex, vector<vector<int>>& adjacency_matrix) {
    queue<int> vertex_store;
    vector<int> visited;
    for(int i = 0; i < adjacency_matrix.size(); i++)
    {
        visited.push_back(0);
    }

    vertex_store.push(startedVertex);
    visited[startedVertex] = 1;

    while (!vertex_store.empty()) {
        int temp = vertex_store.front();
        cout << temp << ' ';
        vertex_store.pop();

        for (int i = 0; i < adjacency_matrix[temp].size(); i++) {
            if (visited[i] == 0 && adjacency_matrix[temp][i] == 1) {
                vertex_store.push(i);
                visited[i] = 1; 
            }
        }
    }
}

int main() {

    int vertices,  edge;
    vector<vector<int>> adjacency_matrix;

    adjacency_matrix = {
                {0, 1, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 1, 1, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 1, 0, 0, 1, 0},
                {0, 0, 0, 1, 0, 1, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 1, 0},
                {0, 0, 0, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 1, 0}
                };

    bfs(6, adjacency_matrix); // Start BFS from vertex 0
    cout << endl;
    return 0;
}