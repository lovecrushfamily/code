#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main() {

    int no_vertices, no_edges;

    cout << "No. vertices: ";
    cin >> no_vertices;
    cout << "No. edges: ";
    cin >> no_edges;



    unordered_map<int, vector<vector<int>>> adjacency_list;
    adjacency_list[1] = {{2,3}, {3,4}, {4,5}};
    for( auto& adjacency_edge : adjacency_list){
        cout << adjacency_edge.
    }

    cout << adjacency_list[1][1][1];


    for (int i = 0; i < no_vertices; i++){
        for( int j = 0; i < no_vertices[i].lenght; j++){
            
        }
    }

    cout << "hee" << endl;



}