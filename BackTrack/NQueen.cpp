#include <iostream>
#include <vector>
using namespace std;

void find(int row, int n, vector<vector<string>>& ans, vector<string>& Board,
          vector<bool>& column, vector<bool>& LeftDig, vector<bool>& RightDig) {
    // Base condition
    if (row == n) {
        ans.push_back(Board);
        return;
    }

    // Placing the queen on the board
    for (int j = 0; j < n; j++) {
        if (column[j] == 0 && LeftDig[n - 1 + j - row] == 0 && RightDig[row + j] == 0) {
            Board[row][j] = 'Q';
            column[j] = 1;
            LeftDig[n - 1 + j - row] = 1;
            RightDig[row + j] = 1;

            find(row + 1, n, ans, Board, column, LeftDig, RightDig);

            // Backtracking
            column[j] = 0;
            LeftDig[n - 1 + j - row] = 0;
            RightDig[row + j] = 0;
            Board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> Board(n, string(n, '.'));
    vector<bool> column(n, 0);
    vector<bool> LeftDig(2 * n - 1, 0);
    vector<bool> RightDig(2 * n - 1, 0);
    find(0, n, ans, Board, column, LeftDig, RightDig);
    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Number of solutions: " << solutions.size() << endl;
    for (int i = 0; i < solutions.size(); i++) {
        for (int j = 0; j < solutions[i].size(); j++) {
            cout << solutions[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}