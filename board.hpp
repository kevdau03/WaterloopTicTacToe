#include <iostream>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

class GameBoard
{
private:
    int rows;
    int cols;

public:
    vector<vector<string>> gameboard;
    bool isPlayerX;
    GameBoard(int rows, int cols);
    void printBoard();
    void setSpot(int row, int col, string data);
    bool winCondition();
};
