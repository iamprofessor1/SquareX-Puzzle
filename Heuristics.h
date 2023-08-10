// Calculate the Manhattan heuristic distance for a given board configuration
int heuristic_manhattan(vector<vector<int>> b)
{
    int dist = 0;                 // Initialize the total Manhattan distance
    map<int, pair<int, int>> val; // Map to store the correct position of each value
    int n = b.size();             // Get the size of the board
    int x = 1;                    // Counter for values, excluding the blank tile (0)

    // Populate the map with the correct positions of each value
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            val[x] = make_pair(i, j); // Store the position of the value x
            x++;
        }
    }
    val[0] = make_pair(n - 1, n - 1); // Store the position of the blank tile (0) at the bottom-right corner

    // Calculate the Manhattan distance for each value in the board configuration
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Add the Manhattan distance between the current position and the correct position of the value
            dist += (abs(i - val[b[i][j]].first) + abs(j - val[b[i][j]].second));
        }
    }

    return dist; // Return the total Manhattan distance as the heuristic value
}
