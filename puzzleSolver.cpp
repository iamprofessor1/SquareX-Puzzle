// include necessary header files
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <stack>
using namespace std;

// dx and dy arrays used to define the possible movements of the blank tile
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
// include user-defined header files
#include "stateModeling.h" // assuming StateNode.h file is present in the same directory
#include "bfs.h"           // assuming bfs.h file is present in the same directory
#include "A_star.h"        // assuming A_star.h file is present in the same directory

// function to solve the puzzle
void solve()
{
    cout << "---***---Welcome to SquareXPuzzle-Game Solver---***----" << endl;
    // get the size of the board n*n;
    cout << "? Please Enter the size of board in the form of N X N" << endl;
    int n;
    cin >> n >> n;
    cout << "The board size is " << n << " X " << n << endl;
    // create vector for initial and final board configurations
    cout << "? Enter the board" << endl;
    vector<vector<int>> board_initial;
    vector<vector<int>> board_final;
    board_initial.resize(n, vector<int>(n, 0));
    board_final.resize(n, vector<int>(n, 0));

    // store the position of the blank tile
    pair<int, int> blank;

    // take input the initial board configuration
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board_initial[i][j];
            if (board_initial[i][j] == 0)
            {
                // set the position of the blank tile
                blank = {i, j};
            }
        }
    }

    // set the final board configuration
    int start = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board_final[i][j] = start++;

    board_final[n - 1][n - 1] = 0; // set the position of the blank tile in the final board

    // create the initial StateNode
    StateNode *src = new StateNode(blank, blank, 0, n, board_initial, NULL);







    // ---- Here is the solution ---- ///

    cout << "---***---Now pick a choice by which you want to solve---***----" << endl;
    cout << "? Enter 1 for BFS and 2 for A*(Star)" << endl;
    int choice;
    cin >> choice;
    clock_t start_clock = clock();

    switch (choice)
    {
        // solve the puzzle using BFS
    case 1:
        bfs(src, board_final);
        break;

        // solve the puzzle using A*
    case 2:
        A_Star(src);
        break;
    default:
        cout << "Please Enter Correct Choice (1 or 2) !!!! " << endl;
        break;
    }

    // --- Here is the time module ---//
    clock_t end_clock = clock();
    cout << "Time taken to execute using the approach " << (choice == 1 ? "BFS :-> " : choice == 2 ? "A*(A_star) :-> "
                                                                                                   : " of Wrong Choice :-> ")
         << (double)(end_clock - start_clock) / CLOCKS_PER_SEC << " seconds" << endl;

    // ------------------------------------------------------------------------ //
}

int main()
{
    // set I/O operations to run faster
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // For getting puzzle input from input.txt file
    // freopen("inputPuzzle.txt", "r", stdin);

    // // Printing the solution steps in output.txt file
    // freopen("outputSolution.txt", "w", stdout);

    // call the solve function to solve the puzzle
    solve();

    return 0;
}