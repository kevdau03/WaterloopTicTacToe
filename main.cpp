#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include "board.hpp"
using namespace std;

int main()
{
    GameBoard board(3, 3);
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1, you're X" << endl;
    cout << "Player 2, you're O" << endl;
    cout << "Player 1 is going to go first" << endl;
    board.printBoard();
    cout << "Choose your column and row: " << endl;
    int turn = 9;
    while (!board.winCondition())
    {
        int row, col;

        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board.gameboard[col][row] != "$")
        {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        if (board.isPlayerX)
        {
            board.setSpot(row, col, "X");
            board.printBoard();
            turn--;
            if (board.winCondition())
            {
                cout << "Player 1 wins!" << endl;
                return 0;
            }
            board.isPlayerX = false;
            cout << "Player 2 now it's your turn, choose your column and row: " << endl;
        }
        else
        {
            board.setSpot(row, col, "O");
            board.printBoard();
            turn--;
            if (board.winCondition())
            {
                cout << "Player 2 wins!" << endl;
                return 0;
            }
            board.isPlayerX = true;
            cout << "Player 1 now it's your turn, choose your column and row: " << endl;
        }

        if (turn == 0)
        {
            cout << "It's a draw" << endl;
            break;
        }
    }
}
