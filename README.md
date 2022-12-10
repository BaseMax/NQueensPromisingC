# n-Queens Promising C

This is a promising implementation of the n-Queens problem in C. It uses a recursive backtracking algorithm to find all solutions to the n-Queens problem. It is a promising implementation because it uses a heuristic to prune the search tree. The heuristic is to only place a queen in a column if it is not in check with any other queens. This heuristic is not guaranteed to find all solutions, but it is guaranteed to find all solutions in a reasonable amount of time.

## Usage

To compile the program, you can use CMake to generate a Makefile. Then, you can use the Makefile to compile the program. The following commands will compile the program:

    mkdir build
    cd build
    cmake ..
    make

To run the program, you can use the following command:

    ./QueensPromising <n>

Where `<n>` is the size of the board. The program will print all solutions to the n-Queens problem.

## License

This project is licensed under the GPL-3 License - see the [LICENSE](LICENSE) file for details

© Copyright Max Base, 2022
