#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Edge{
    int source;
    int destination;
    int weight;
};

void bellmanFord(vector<Edge>& Graph,int numberOfVertices, int start){

    vector<int> distances(numberOfVertices, INT_MAX);
    distances[start] = 0;

    for (int i = 1; i < numberOfVertices ;i++ ){
        for (const auto& edge : Graph){
            int sour = edge.source;
            int des = edge.destination;
            int wei = edge.weight;

            if (distances[sour] != INT_MAX && distances[sour] + wei < distances[des]){
                distances[des] = distances[sour] + wei;
            }
        }
    }

    for (const auto& edge : Graph){
        int sour = edge.source;
        int des = edge.destination;
        int wei = edge.weight;

        if (distances[sour] != INT_MAX && distances[sour] + wei < distances[des] ){
            cout << "Graph contains a negative-weight cycle\n";
            return;
        }
    }

    for (int i = 0; i < numberOfVertices; ++i){
        cout << "Distance from source to vertex " << i << " is " << distances[i] << '\n';
    }
    return;
}


int main(){
    vector<Edge> edgesList = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, -2},
        {1, 3, 2},
        {1, 4, 4},
        {2, 5, 2},
        {3, 4, 3},
        {3, 6, 2},
        {4, 6, 1},
        {5, 6, -3},
        // {6, 1, 2} //uncomment this if you wanna see a negative-weight cycle
    };

    int start = 0;
    int numberOfVertices = 7;
    bellmanFord(edgesList, numberOfVertices, start);
    
    return 0;
}