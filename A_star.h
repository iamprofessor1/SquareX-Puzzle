#include "Heuristics.h"
#include "solutionPrinter.h"

// Custom comparison function for the priority queue
struct prioritize
{
    bool operator()(const StateNode *p1, const StateNode *p2) const
    {
        // Compare nodes based on their total cost plus level
        return (p1->cost + p1->level) > (p2->cost + p2->level);
    }
};

// A* algorithm implementation
void A_Star(StateNode *src)
{
    priority_queue<StateNode *, std::vector<StateNode *>, prioritize> pq; // Priority queue for node exploration
    int n = src->n;                                                       // Size of the puzzle board
    src->cost = heuristic_manhattan(src->board);                          // Initial heuristic cost estimation
    pq.push(src);                                                         // Push the source node into the priority queue

    map<vector<int>, int> vis; // Map to keep track of visited states

    while (!pq.empty())
    {
        StateNode *curr = pq.top();      // Get the node with the highest priority
        pq.pop();                        // Remove the top node from the priority queue
        int curr_x = curr->blank.first;  // X-coordinate of the blank tile
        int curr_y = curr->blank.second; // Y-coordinate of the blank tile

        vector<int> ans; // Vector to store the current state's puzzle configuration
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans.push_back(curr->board[i][j]); // Copy the puzzle configuration into the vector
            }
        }

        if (curr->cost == 0)
        {
            cout << "Congratulations! We've found the solution using A* ( A_star)! " << endl;
            cout << "You'll be happy to know that it only took us ";
            cout << curr->level << " moves to get there! :) " << endl;
            // Print the solution
            print_solution(curr);
            return;
        }

        if (vis[ans] == 1)
            continue; // Skip if the state has already been visited

        vis[ans] = 1; // Mark the current state as visited

        for (int k = 0; k < 4; k++)
        {
            int nx = curr_x + dx[k]; // Calculate next X-coordinate
            int ny = curr_y + dy[k]; // Calculate next Y-coordinate

            if (nx >= 0 and ny >= 0 and nx < n and ny < n)
            {
                vector<vector<int>> board = curr->board;                                                                            // Create a copy of the current board
                StateNode *next_pos = new StateNode(make_pair(curr_x, curr_y), make_pair(nx, ny), curr->level + 1, n, board, curr); // Create a new state node for the next position

                next_pos->cost = heuristic_manhattan(next_pos->board); // Update the heuristic cost for the new state

                vector<int> tmp;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        tmp.push_back(next_pos->board[i][j]); // Copy the puzzle configuration into the vector
                    }
                }

                if (!vis[tmp])
                {
                    pq.push(next_pos); // Push the new state into the priority queue if not visited before
                }
            }
        }
    }
    // If no solution is found
    cout << "Unfortunately, no solution could be found :(" << endl;
}
