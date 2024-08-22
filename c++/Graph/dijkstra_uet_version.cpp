#include<iostream>
#include<vector>

using namespace std;

int maximum = 1000000;

struct Edge{
    int vertex;
    int weight;
};
int number_of_vertices = 5;// default value
int start = 0;
vector<vector<Edge>> Edges(number_of_vertices);


void init(){
    Edge edge1, edge2, edge3, edge4, edge5;

    edge1.vertex = 1;
    edge1.weight = 100;
    Edges[0].push_back(edge1);
    edge1.vertex = 2;
    edge1.weight = 50;
    Edges[0].push_back(edge1);
    
    edge2.vertex = 2;
    edge2.weight = 50;
    Edges[1].push_back(edge2);
    edge2.vertex = 3;
    edge2.weight = 50;
    Edges[1].push_back(edge2);
    edge2.vertex = 4;
    edge2.weight = 50;
    Edges[1].push_back(edge2);
    
    edge3.vertex = 3;
    edge3.weight = 100;
    Edges[2].push_back(edge3);
    
    edge4.vertex = 4;
    edge4.weight = 75;
    Edges[3].push_back(edge4);
    

}
void print(){
    for (int i = 0; i < number_of_vertices; i++) {
        cout << "Cac canh ke voi đinh " << i << ": ";
        for (int j = 0; j < Edges[i].size(); j++) {
            cout << "(" << Edges[i][j].vertex << ", " << Edges[i][j].weight << ") ";
        }
        cout << endl;
    }
}


vector<int> dijkstra(int start){
    vector<int> dist(number_of_vertices, maximum);
    vector<int> trace(number_of_vertices, -1);
    vector<bool> visited(number_of_vertices, false);
    dist[start] = 0;

    for (int i = 0; i < number_of_vertices; i++){
        int bestVertex;
        int MAXI = maximum;

        for (int vertex = 0; vertex < number_of_vertices; vertex++){
            if (dist[vertex] < maximum && visited[vertex] == false){
                bestVertex = vertex;
                MAXI = dist[vertex];
            }
        }

        visited[bestVertex] = true;
        for (auto edge : Edges[bestVertex]){
            int tempVertex = edge.vertex;
            int weight = edge.weight;
            if (dist[tempVertex] > dist[bestVertex] + weight){
                dist[tempVertex] = dist[bestVertex] + weight;
                trace[tempVertex] = bestVertex;
            }
        }
    }
    return dist;
}

int main(){
    
    init();
    cout << "\nSmallest distance from Vertex 0 :\n";
    vector<int> dist = dijkstra(0);
    
    for (int i = 0; i < dist.size(); i++){
        cout << "to " << i << " : " << dist[i] << '\n';
    }
}