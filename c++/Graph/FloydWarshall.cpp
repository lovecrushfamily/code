#include <iostream>
#include <vector>
#include<climits>

using namespace std;


void Floyd(vector<vector<int>>& matrix, int numberOfVertices){

    //Assume that Paths: second -> third;
    // If the path second -> first -> third > second -> third;
    // update path second -> third = second -> first -> third;
    // You feel me, right !

    int first, second, third;
    for ( first = 0; first < numberOfVertices; first++){
        for ( second = 0; second < numberOfVertices; second++){
            for ( third = 0; third < numberOfVertices; third++){
                if (matrix[second][first] + matrix[first][third]  < matrix[second][third] && 
                    matrix[first][third] != INT_MAX &&  matrix[second][first] != INT_MAX ){
                    matrix[second][third]  = matrix[second][first] + matrix[first][third];
                }
            }
        }
    }
    
    // visualize
    cout << "       Shortest Paths Floyd-Warshall !\n\n";
    cout << " <Ind>\t|\tDestination\n_____________________________\n Source |\t 0 -> n\n        |\n";
    int ind = 0;
    for (auto& row : matrix){
        cout << "    " << ind++ << "   |";
        for ( auto& col : row){
            cout << '\t';
            (col == INT_MAX) ? cout << "inf " : cout << col  << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    //
    vector<vector<int>> matrix = {
        {0,       100    , 50     , INT_MAX, INT_MAX},
        {INT_MAX, 0      , 50     , 50,      50},
        {INT_MAX, INT_MAX, 0      , 100,     INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0,       75},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
    
    // 
    int numberOfVertices = 5;
    int numberOfEdges = 7;
    int start = 0;
    Floyd(matrix, numberOfVertices);

    
    return 0;
}