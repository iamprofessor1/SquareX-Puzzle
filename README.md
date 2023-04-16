<br/>
<p align="center">

  <h1 align="center">
<a href="https://github.com/iamprofessor1/SlidingX" target = "_blank">SquareX-Puzzle</a>
</h1>

  <p align="center">
    Build with ❤️ by <b><a href="https://www.linkedin.com/in/vikas-pandit/">VIKAS PANDEY</a></b>
    <br/>
    <br/>
    <a href="https://github.com/iamprofessor1/SquareX-Puzzle/blob/main/README.md"><strong>Explore the docs »</strong></a>
    <br/>
  
  </p>

</p>


<br>
<br>


## Table of Contents

- [About the Project](#about-the-project)
- [Getting Started](#getting-started)
- [Files Description](#files-description)
    - [stateModeling.h](#statemodelingh)
    - [bfs.h](#bfsh)
    - [solutionPrinter.h](#solutionprinterh)
    - [puzzleSolver.cpp](#puzzlesolvercpp)
    - [inputPuzzle.txt](#inputpuzzletxt)
    - [outputSolution.txt](#outputsolutiontxt)
- [Time Complexity](#time-complexity)
- [Contributing](#contributing)
- [Need Help](#need-Help)


## About The Project

SquareX-Puzzle is an interactive project that takes a square sliding puzzle board as input and uses a breadth-first search(BFS) algorithm to find the minimum number of moves required to reach the final state. 

The project provides a user-friendly interface where users can input their puzzle and obtain the number of moves required to solve it and how to make a move. 

The project is written in C++ and designed to be easily adaptable to other languages. SquareX-Puzzle is a great example of an algorithmic problem solving project and a useful tool for anyone interested in studying search algorithms.

<p align="center">
  <img width="460" height="460" src="https://miro.medium.com/max/1213/1*YxeZJzfhW4kn5O5wAGbkIg.gif">
</p>



## Getting Started

➤ Getting started with SquareX-Puzzle:

Clone the repository:
```sh
git clone https://github.com/iamprofessor1/SquareX-Puzzle.git
```

➤ Navigate to the project directory:
```sh
cd SquareX-Puzzle
```

➤ Compile the code:
g++ puzzleSolver.cpp -o puzzleSolver


➤ Run the program:

```sh
./puzzleSolver
```

➤ Enter the puzzle configuration:

```sh

3
3 8 5
0 7 1
2 6 4
```

➤ Wait for the program to calculate the solution:

```sh
Congratulations! We've found the solution using BFS! 
You'll be happy to know that it only took us 23 moves to get there! :) 
 This is puzzle you have given :- 
Move no :- 0
[ 3 8 5 ] 
[ 0 7 1 ] 
[ 2 6 4 ] 


Move no :- 1
[ 3 8 5 ] 
[ 7 0 1 ] 
[ 2 6 4 ] 

Move no :- 2
[ 3 8 5 ] 
[ 7 1 0 ] 
[ 2 6 4 ] 

Move no :- 3
[ 3 8 5 ] 
[ 7 1 4 ] 
[ 2 6 0 ] 

...
...
...

Move no :- 23
[ 1 2 3 ] 
[ 4 5 6 ] 
[ 7 8 0 ] 

```

Note: The program uses the BFS algorithm to find the solution. It may take a while to compute the solution for larger puzzle configurations.


## Files Description

### stateModeling.h
The struct named "StateNode" has the following properties:
<ul>
<li> "blank" and "next" are the coordinates of the blank tile and the next tile to move.</li>
<li> "level" represents the depth of the StateNode in the search tree.</li>
<li> "n" is the size of the board (i.e., n x n).</li>
<li> "board" is a vector of vector of integers representing the board configuration.</li>
<li> "parent" is a pointer to the parent StateNode.</li>
</ul>
The struct also includes a constructor that initializes the properties of the StateNode struct. The constructor swaps the positions of the blank tile and the next tile to create a new board configuration. The header file is guarded by a preprocessor directive, ensuring that the contents of the header file are included only once in the program.


### bfs.h
This code performs a BFS (breadth-first search) algorithm to solve the puzzle. It takes in the initial state of the puzzle as a StateNode struct and the final state of the puzzle as a vector<vector<int>> board_final. It creates a queue to store the states of the puzzle, starts with the initial state, and iterates through each possible movement of the blank tile until it reaches the final state or the queue is empty.

If the final state is reached, it prints the number of moves required to reach the solution state and calls the print_solution() function to print the solution. If no solution is found, it prints an error message.

The code also includes a visited map to keep track of already visited states and avoids repeating them.

### solutionPrinter.h
This is the header file for the solution printer module. It includes the header file for state modeling and declares a function print_solution that prints the solution path for the given puzzle. The function takes a pointer to the current state node as input and prints the board configurations along with the move number. The solution path is printed in reverse order using a stack to store the StateNodes.

The function print_solution uses a loop to pop StateNodes from the stack and print the board configuration and move number. If it is the first iteration of the loop, it prints a message to indicate that the puzzle provided by the user is being printed. The board configuration is printed row-wise, and each element of the board is separated by a space. The board configuration is enclosed in square brackets, and each row is enclosed in a pair of curly braces. Finally, the function prints a blank line after each board configuration to make it easier to read.

The header file is protected by the #ifndef and #endif preprocessor directives to prevent multiple inclusions of the header file in the same translation unit.


### puzzleSolver.cpp
The program takes the size of the board and the initial configuration of the board as input from a file named inputPuzzle.txt. It then creates the final configuration of the board and generates an initial StateNode object. Finally, it passes the initial StateNode object and the final board configuration to the bfs function for finding the solution to the puzzle.
The bfs function uses a queue and a map data structure to keep track of the visited states and to perform the BFS algorithm. The StateNode struct is used to represent a state in the puzzle. It contains the current board configuration, the position of the blank tile, the position of the next tile to move, the depth of the state in the search tree, and a pointer to the parent state. The StateNode struct also has a constructor that initializes the board configuration after swapping the blank tile with the next tile to move.

The program sets the input and output files to inputPuzzle.txt and outputSolution.txt, respectively. It also sets I/O operations to run faster by using the ios_base::sync_with_stdio(0) function.


### inputPuzzle.txt

The file named inputPuzzle.txt contains the input for the puzzle solver program. The first line of the file contains a single integer, which represents the size of the board (i.e., n x n). The next n lines represent the initial configuration of the board. Each line contains n integers separated by spaces, where each integer represents a tile in the board. The number 0 represents the blank tile

### outputSolution.txt
The outputSolution.txt file contains the solution steps to solve the sliding tile puzzle. The steps are written in the following format:

Step 1:
The board configuration after the first move.

Step 2:
The board configuration after the second move.

And so on, until the final configuration is reached



## Time Complexity

<i>The time complexity of the implemented puzzle solver using the Breadth-First Search (BFS) algorithm depends on the size of the board, represented as n x n, and the number of states generated during the search.</i>

The number of states generated in the worst case for the n-puzzle problem can be bounded by the branching factor raised to the depth of the search tree. In the case of the n-puzzle, the maximum branching factor can be 4 (the number of possible moves for the blank tile). The depth of the search tree can be up to n^2, which is the number of tiles on the board.

<u><i> Therefore, the worst-case time complexity of the algorithm can be expressed as <b> O(4^(n^2)) </b>, which is exponential in terms of the size of the board.
</i><u>

However, in practice, the number of states generated during the search is much less than the upper bound. This is because the BFS algorithm explores the search space in a breadth-first manner, which means that it visits all the nodes at a given depth before moving to the next level. Hence, the number of nodes generated at a given depth is much less than the maximum branching factor raised to the depth.

Moreover, the implemented algorithm uses a hash map to store the visited nodes and to avoid revisiting them. This reduces the number of nodes generated during the search, especially when dealing with larger boards.

Therefore, the actual time complexity of the algorithm is significantly lower than the upper bound and can be considered reasonable for solving practical instances of the n-puzzle problem.



## Contributing
Contributions are always welcome! If you have any ideas or suggestions, feel free to open an issue or a pull request.

## Need-Help
  
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/vikas-pandit/)
[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:vikaspandey1206@gmail.com)

---------

```javascript

if (youEnjoyed) {
    starThisRepository();
}

```

-----------


