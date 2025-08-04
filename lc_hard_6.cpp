// #lc-hard-6

#include "markers.h"

#include <cmath>
#include <string>
#include <vector>
using std::vector;
using std::string;

// Passed 9 test cases on LC.
vector<vector<string>> nqueens(int N);

int main()
{
    __BEGIN

    for (const vector<string>& solution : nqueens(4)) {
        for (const string &row : solution) {
            std::cout << row << std::endl;
        }
        std::cout << "---" << std::endl;
    }

    __END
}

inline bool are_attacking(int i1, int j1, int i2, int j2)
{
    return i1 == i2 || j1 == j2 || std::abs(i1-i2) == std::abs(j1-j2);
}

// board[i] | i=row, board[i]=column
// row, col is where the last queen was placed
// only tests the last queen agains all others
bool test_board(vector<int> board, int row, int col)
{
    for (int i = 0; i < row; ++i) {
        if (are_attacking(i, board[i], row, col)) {
            return false;
        }
    }
    return true;
}

void try_solve_nqueens(int N, vector<int>& board, int row, vector<vector<string>>& solutions)
{
    for (int i = 0; i < N; ++i) {
        if (test_board(board, row, i)) {
            board[row] = i;
            if (row == N-1) {
                vector<string> sol(N, string(N, '.'));
                for (int i = 0; i < N; ++i) {
                    sol[i][board[i]] = 'Q';
                }
                solutions.push_back(sol);
            }
            else {
                try_solve_nqueens(N, board, row+1, solutions);
            }
            board[row] = -1;
        }
    }
}

vector<vector<string>> nqueens(int N)
{
    if (N < 1) return {};
    if (N == 1) return {{ "Q" }};

    vector<vector<string>> solutions;
    for (int i = 0; i < N; ++i) {
        vector<int> board(N, -1);
        board[0] = i;
        try_solve_nqueens(N, board, 1 /* row */, solutions);
    }

    return solutions;
}
