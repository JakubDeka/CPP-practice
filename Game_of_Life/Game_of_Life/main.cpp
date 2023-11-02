#include <iostream>
#include <array>
#include <cstdlib>

const int SIZE = 5;
const int ITERATIONS_LIMIT = 10;

bool** createBoard(int m, int n)
{
    bool* values = (bool*)calloc(m * n, sizeof(float));
    bool** rows = (bool**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; ++i)
    {
        rows[i] = values + i * n;
    }
    return rows;
}

void destroyBoard(bool** arr)
{
    free(*arr);
    free(arr);
}

int checkHowManyNeighboursAlive(int x, int y, bool** board, int board_x, int board_y)
{
    int neighbour_x, neighbour_y, alive_neighbours = 0;
    for (int x_change = -1; x_change <= 1; x_change++)
    {
        for (int y_change = -1; y_change <= 1; y_change++)
        {
            if (!(x_change == 0 and y_change == 0))
            {
                //std::cout << y_change << " " << x_change << '\n';
                neighbour_x = (board_x + x + x_change) % board_x;
                neighbour_y = (board_y + y + y_change) % board_y;
                alive_neighbours += board[neighbour_x][neighbour_y];
            }
        }
    }
    return alive_neighbours;
}

void changeCellState(bool** board, int x, int y, bool target_state)
{
    board[x][y] = target_state;
}

bool updateCell(bool** old_board, bool** new_board, int x, int y)
{
    int nghb = checkHowManyNeighboursAlive(x, y, old_board, SIZE, SIZE);
    bool cell_alive = old_board[x][y];
    if (cell_alive and (nghb < 2 or nghb > 3))
    {
        changeCellState(new_board, x, y, 0);
        return true;
    }
    else if (!cell_alive and nghb == 3)
    {
        changeCellState(new_board, x, y, 1);
        return true;
    }
    else
    {
        new_board[x][y] = old_board[x][y];
        return false;
    }
}

void printBoard(bool** board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::array<bool**, 2> updateBoard(bool** board, int board_x, int board_y)
{
    bool** new_board = createBoard(SIZE, SIZE);
    int changed_neighbours = 0;
    for (int x = 0; x < board_x; x++)
    {
        for (int y = 0; y < board_y; y++)
        {
            changed_neighbours += updateCell(board, new_board, x, y);
        }
    }
    printBoard(new_board);
    std::cout << "Changed neighbours: " << changed_neighbours << "\n\n";
    return { new_board, (bool**) (changed_neighbours>0) };
}

int main()
{
    bool** board = createBoard(SIZE, SIZE);
    board[0][0] = 5;
    board[0][1] = 11;
    board[0][2] = 3;
    board[0][3] = 3;

    int iteration = 0;
    std::cout << "Iteration: " << iteration << std::endl;
    printBoard(board);
    std::cout << std::endl;
    
    bool play = true;
    while (play and iteration<ITERATIONS_LIMIT)
    {
        iteration++;
        std::cout << "Iteration: " << iteration << std::endl;
        std::array<bool**, 2> result = updateBoard(board, SIZE, SIZE);
        board = result[0];
        if (!result[1])
        {
            break;
        }
    }
}