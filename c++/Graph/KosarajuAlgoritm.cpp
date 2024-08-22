#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<stack>
#include<cstring> 

using namespace std;// input adjacency list

unordered_map<int, vector<int>> adj;
unordered_map<int, vector<int>> r_adj;
bool visited[100];
stack<int> st;
int number_of_edges, number_of_vertices;

/**
 * The function takes user input for the number of vertices and edges, and then creates adjacency lists
 * for a directed graph.
 * Enter your inputs as a edges list and we'll use it as a adjacency list
 */
void input(){
    cout << "Number of vertices: ";
    cin >>  number_of_vertices;
    cout << "Number of edges: ";
    cin >> number_of_edges;
    cout << '\n';
    for ( int i = 0; i < number_of_edges; i++){
        int x, y; cin >> x >> y;
        
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}

void dfsFirst(int vertices){
    visited[vertices] = true;
    for ( int vertex : adj[vertices]){
        if( visited[vertex] == false ){
            dfsFirst(vertex);
        }
    }
    st.push(vertices);
}

void dfsSecond(int vertices){
    visited[vertices] = true;
    cout << vertices << ' ';
    for (int vertex : r_adj[vertices]){
        if ( !visited[vertex]){
            dfsSecond(vertex);
        }
    }
}

/**
 * The function `strongConnectedComponent` finds and prints all strongly connected components in a
 * graph.
 */
void strongConnectedComponent(){

    int number_component_on_line = 0;

    for (int i = 0; i < number_of_vertices; i++){
        if ( !visited[i]){
            dfsFirst(i);
        }
    }

    //turn all vertices into false, prepare for the next process
    for (bool& erase : visited){
        erase = false;
    }

    while (!st.empty()){
        int temp = st.top();
        st.pop();
        if (!visited[temp]){
            if (number_component_on_line){
                cout << '\n';
            }
            dfsSecond(temp);
            number_component_on_line++;
        }

    }

    if (number_component_on_line){
        cout << '\n';
    }
}

int main(){
    input();
    cout << '\n';
    strongConnectedComponent();
    

    return 0;
}