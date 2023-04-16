// Header file for solution printer module
#ifndef SOLUTIONPRINTER_H
#define SOLUTIONPRINTER_H

// Include the header file for state modeling
#include "stateModeling.h"

/*
Function to print the solution path
Input : A pointer to the current state node
Output: Prints the board configurations along with the move number
*/
void print_solution(StateNode *curr)
{
    int n = curr->n;

    // Use a stack to store the StateNodes and print the final path in reverse order
    stack<vector<vector<int>>> st;
    while (curr != NULL)
    {
        st.push(curr->board);
        curr = curr->parent;
    }

    int moves = 0;
    bool first_time = true;
    // Print the board configurations along with the move number
    while (st.size() > 0)
    {
        vector<vector<int>> board = st.top();
        st.pop();

        if (first_time)
        {
            cout << " This is puzzle you have given :- " << endl;
        }
        cout << "Move no :- " << moves++ << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "[ ";
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "] " << endl;
        }
        if (first_time)
        {
            first_time = false;
            cout << endl;
        }
        cout << endl;
    }
}

#endif // SOLUTIONPRINTER_H
