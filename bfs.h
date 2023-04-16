#include "solutionPrinter.h"


// Function to perform a BFS search for solving the puzzle
void bfs(StateNode *src, vector<vector<int>> &board_final)
{
    // Create a queue and add the initial state
    queue<StateNode *> q;
    q.push(src);

    // Dimension of the puzzle
    int n = src->n;

    // Visited map to keep track of already visited states
    map<vector<vector<int>>, int> vis;

    // While there are still StateNodes in the queue
    while (!q.empty())
    {
        // Get the current state from the front of the queue
        StateNode *curr = q.front();
        q.pop();

        // Get the current position of the blank tile
        int curr_x = curr->blank.first;
        int curr_y = curr->blank.second;

        // If the current board state is same as the final state
        if (curr->board == board_final)
        {
            // Print the number of moves required to reach solution state
            cout << "Congratulations! We've found the solution using BFS! " << endl;
            cout << "You'll be happy to know that it only took us ";
            cout << curr->level << " moves to get there! :) " << endl;

            // Print the solution
            print_solution(curr);
            return;
        }

        // If the current state is already visited, skip it
        if (vis[curr->board] == 1)
            continue;

        // Mark the current state as visited
        vis[curr->board] = 1;

        // Iterate over all possible movements of blank tile
        for (int k = 0; k < 4; k++)
        {
            // Calculate the next position of the blank tile
            int nx = curr_x + dx[k];
            int ny = curr_y + dy[k];

            // Check if the next position is valid
            if (nx >= 0 and ny >= 0 and nx < n and ny < n)
            {
                // Create the next state by swapping the blank tile and its neighbor
                vector<vector<int>> board = curr->board;
                StateNode *next_pos = new StateNode(make_pair(curr_x, curr_y), make_pair(nx, ny), curr->level + 1, n, board, curr);

                q.push(next_pos);
            }
        }
    }

    // If no solution is found
    cout << "Unfortunately, no solution could be found :(" << endl;
}
