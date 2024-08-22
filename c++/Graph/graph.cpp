#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;
// class graph{
//     public:
//     vector<pair<int,int>> edges_list; // stored all edges 
//     vector<vector<bool>>  adjacency_matrix;// 2D array stored the relation between all  edges( able to match or not)
//     // vector<vector<int>>   adjacency_list;// adj list is a 2D array stored the nodes adjacency with it
//     unordered_map<int,vector<int>> adj_list;// same as the above
// };

class Solution{
    public:
    // some representation of graph, sample for traversal
    unordered_map<int, vector<int>> im_graph;
    unordered_set<int> visited;
    int count = 0;

    void initAdjList(){
        this -> im_graph[0] = {1,2};
        this -> im_graph[1] = {0,2,3};
        this -> im_graph[2] = {0,1,4};
        this -> im_graph[3] = {1,4};
        this -> im_graph[4] = {2,3,5};
        this -> im_graph[5] = {4,6};
    }

    vector<vector<int>> initEdgeList(){
        vector<vector<int>> sample ;
        sample = {
                    {0,1},
                    {0,2},
                    {1,2},
                    {1,3},
                    {2,4},
                    {3,4},
                    {4,5},
                    {5,6},
                    {6,7},
                    {7,8},
                };
        
        return sample;
    }
    vector<pair<int, int>> initEdgeListTwo(){
        vector<pair<int, int>> sampleTwo;
        sampleTwo = {
                        {0,1},  
                        {0,2},
                        {1,2},
                        {1,3},
                        {2,4},
                        {3,4},
                        {4,5},
                        {5,6},
                        {6,7},
                        {7,8}
                    };
        return sampleTwo;
    }
    vector<vector<bool>> initAdjMatrix(){
        return {
                {false, true, false, false, false, false, false, false, false},
                {true, false, true, true, false, false, false, false, false},
                {false, true, false, false, false, false, false, false, false},
                {false, true, false, false, true, false, false, true, false},
                {false, false, false, true, false, true, false, false, false},
                {false, false, false, false, true, false, true, false, false},
                {false, false, false, false, false, true, false, true, false},
                {false, false, false, false, false, false, true, false, true},
                {false, false, false, false, false, false, false, true, false}
                };
    }

    void dfsOnGraph(int vertices){
        cout << vertices << ' ';
        visited.insert(vertices);
        for (int vertex : im_graph[vertices]){
            if (visited.find(vertex) == visited.end()){
                dfsOnGraph(vertex);
            }
        }
    }

    void bfsTraversal(int vertices){
        queue<int> queue;
        queue.push(vertices);
        visited.insert(vertices);
        while (!queue.empty())
        {
            int vertices = queue.front();
            cout << vertices << ' ';
            queue.pop();
            for( int vertex : im_graph[vertices]){
                if (visited.find(vertex) == visited.end()){
                    queue.push(vertex);
                    visited.insert(vertex);
                }
            }
        }
    }
    bool checkWayUV(int u, int v){
        dfsOnGraph(u);
        return (visited.find(u) == visited.end()) ? false : true;
    }

    void connectedComponent(int u){
        visited.insert(u);
        for (auto& pair : im_graph){
            if(visited.find(pair.first) == visited.end()){
                this -> count++;
                dfsOnGraph(pair.first);
            }
        }
    }

    vector<int> findSmallestSetOfVertices(vector<vector<int>> edges){
        vector<int> in_degree(9);// 9 is the number of different vertices
        for (vector<int>& edge : edges){
            in_degree[edge[1]]++;
        }

        vector<int> ans;
        for (  int i = 0; i < 9; i++ ){
            if (in_degree[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }

    

    void convertAdjMatrixToAdjList(vector<vector<bool>> matrices){
        for (int i = 0; i < matrices.size(); i++){
            for ( int j = i + 1; j < matrices.size(); j++){
                if (matrices[i][j] == true){
                    this -> im_graph[i].push_back(j);
                    this -> im_graph[j].push_back(i);

                    // 
                }
            }
        }
    }

    void convertEdgeListToAdjList(vector<vector<int>> edges){
        unordered_map<int, vector<int>> temp_graph;
        for (vector<int>& edge : edges){
            int x = edge[0], y = edge[1];
            temp_graph[x].push_back(y);
            // temp_graph[y].push_back(x) -- uncomment this line if the graph is undirected
        }
        // return temp_graph;
        this -> im_graph = temp_graph;
    }
    void convertEdListTwo(vector<pair<int, int>> edges){
        unordered_map<int, vector<int>> temp_graph;
        for (pair<int, int>& edge : edges){
            temp_graph[edge.first].push_back(edge.second);
        }
        this -> im_graph = temp_graph;

    } 

    void supported(vector<int> vertices){
        for (int vertex : vertices){
            cout << vertex <<' ';
        }
    }
    
    void visualizeGraph(unordered_map<int, vector<int>>& sample){
        for (auto& vertices : sample){
            cout << vertices.first << " : " ;
            supported(vertices.second);
            cout << '\n';
        }
    }
};

int main(){

    Solution graph;
    
    
    for(int i : graph.visualizeGraph(graph.convertEdgeListToAdjList(graph.initEdgeList()))){
        cout << i << " ";
    }





    return 0;
}