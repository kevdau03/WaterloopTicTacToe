#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include "board.hpp"
using namespace std;
void GameBoard::printBoard()
{
    int rows = 3;
    int cols = 3;
    cout << endl;
    cout << "The board" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << (gameboard[i][j]) << " "
                 << "\t";
        }
        std::cout << std::endl;
    }
    cout << endl;
}

GameBoard::GameBoard(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->isPlayerX = true;
    gameboard.resize(rows, vector<string>(cols, "$"));
}
bool GameBoard::winCondition()
{
    string playerSymbol = isPlayerX ? "X" : "O";

    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++)
    {
        // Check rows
        if (gameboard[i][0] == playerSymbol && gameboard[i][1] == playerSymbol && gameboard[i][2] == playerSymbol)
        {
            return true;
        }

        // Check columns
        if (gameboard[0][i] == playerSymbol && gameboard[1][i] == playerSymbol && gameboard[2][i] == playerSymbol)
        {
            return true;
        }
    }

    // Check diagonals
    if (gameboard[0][0] == playerSymbol && gameboard[1][1] == playerSymbol && gameboard[2][2] == playerSymbol)
    {
        return true;
    }

    if (gameboard[0][2] == playerSymbol && gameboard[1][1] == playerSymbol && gameboard[2][0] == playerSymbol)
    {
        return true;
    }

    return false; // No win found
}

void GameBoard::setSpot(int row, int col, string data)
{
    gameboard[col][row] = data;
}
