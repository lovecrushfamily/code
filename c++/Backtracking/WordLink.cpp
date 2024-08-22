#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m;
int n;
string target;
vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// bool backtrack(int row, int col, int i, vector<vector<bool>>& seen, vector<vector<char>>& board);

bool valid(int row, int col) {
    return 0 <= row && row < m && 0 <= col && col < n;
}

bool backtrack(int row, int col, int i, vector<vector<bool>>& seen, vector<vector<char>>& board) {
    if (i == target.size()) {
        return true;
    }

    for (vector<int> direction : directions) {
        int nextRow = row + direction[0], nextCol = col + direction[1];
        if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
            if (board[nextRow][nextCol] == target[i]) {
                seen[nextRow][nextCol] = true;
                if (backtrack(nextRow, nextCol, i + 1, seen, board)) {
                    return true;
                }
                seen[nextRow][nextCol] = false;
            }
        }
    }

    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();
    target = word;

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == word[0]) {
                vector<vector<bool>> seen(m, vector<bool>(n, false));
                seen[row][col] = true;
                if (backtrack(row, col, 1, seen, board)) {
                    return true;
                }
            }
        }
    }

    return false;
}


int main() {
    vector<vector<char>> board {
        {'t', 'e', 'k', '4', '7'},
        {'a', 'b', 'c', 'd', 'u'},
        {'e', 'f', 'g', 'h', 'e'},
        {'i', 'j', 'k', 'l', 'y'},
        {'m', 'n', 'o', 'p', 'i'}
    };

    cout << exist(board, "cgk");

    return 0;
}