#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> Vertex_Weight;

int number_of_vertices = 9;
vector<vector<Vertex_Weight>> graph(number_of_vertices);
int start = 0;
int MAX = 10000;
// int visited

void initAdjacencyList(){
    // Undirected Weighed Graph

    graph[0].push_back(make_pair(1, 2));
    graph[0].push_back(make_pair(3, 5));
    graph[1].push_back(make_pair(2, 3));
    graph[1].push_back(make_pair(4, 1));
    graph[2].push_back(make_pair(5, 7));
    graph[3].push_back(make_pair(6, 4));
    graph[4].push_back(make_pair(3, 2));
    graph[4].push_back(make_pair(7, 6));
    graph[5].push_back(make_pair(8, 3));
    graph[6].push_back(make_pair(9, 2));
    graph[7].push_back(make_pair(5, 4));
    graph[7].push_back(make_pair(9, 5));
}

vector<int> dijkstra(int start){

    vector<int> distance(number_of_vertices, MAX);
    distance[start] = 0; 

    priority_queue<Vertex_Weight, vector<Vertex_Weight>, greater<Vertex_Weight>> queue;
    queue.push(make_pair(start, 0));

    while (!queue.empty())
    {
        /* code */
        int vertex = queue.top().first;
        int weight = queue.top().second;
        queue.pop();

        if (weight > distance[vertex]){
            continue;
        }

        for (auto& neighbor : graph[vertex]){
            int ver  = neighbor.first;
            int wei = neighbor.second;

            int new_dist = distance[vertex] + wei;
            if (new_dist < distance[ver]){
                distance[ver] = new_dist;
                queue.push( make_pair(ver, new_dist));
            }
        }
    }
    return distance;
    

}

void print(vector<int> dist){

    cout << "\nSmallest distance from Vertex 0 :\n";
    for (int i = 0; i < dist.size(); i++){
        cout << "to " << i << " : " << dist[i] << '\n';
    }
}

int main(){

    initAdjacencyList();
    print(dijkstra(0));

}