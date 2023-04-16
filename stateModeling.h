// Header file for state modeling
#ifndef STATEMODELING_H
#define STATEMODELING_H

// A struct representing a state StateNode in the puzzle
struct StateNode
{
    pair<int, int> blank;      // Coordinates of the blank tile
    pair<int, int> next;       // Coordinates of the next tile to move
    int level;                 // The depth of the StateNode in the search tree
    int n;                     // The size of the board (i.e., n x n)
    vector<vector<int>> board; // The board configuration
    StateNode *parent;                // Pointer to the parent StateNode

    // Constructor for the StateNode struct
    StateNode(pair<int, int> blank, pair<int, int> next, int level, int n, vector<vector<int>> board, StateNode *parent)
    {
        this->blank = blank;
        this->next = next;
        this->level = level;
        this->n = n;
        this->board = board;
        this->parent = parent;

        // Swap the positions of the blank tile and the next tile
        int temp = this->board[blank.first][blank.second];
        this->board[blank.first][blank.second] = this->board[next.first][next.second];
        this->board[next.first][next.second] = temp;
        this->blank = this->next;
    }
};

#endif // STATEMODELING_H
