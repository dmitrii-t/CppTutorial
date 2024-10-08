#include "Board.h"
#include "Search.h"
// #include <windows.h>
#include "Test.h"

using namespace std;

int main()
{
    // SetConsoleOutputCP(CP_UTF8);

    constexpr Position init{0, 0};
    constexpr Position goal{4, 5};
    auto board = Board();
    ReadBoardFile("board.txt", board);

    const auto solution = Search(board, init, goal);
    PrintBoard(solution);

    // Test Heuristic
    // TestAddToOpen();
    TestCompare();
    TestSearch();
    TestCheckValidCell();
    // TestExpandNeighbors();
    TestReadBoardFile();
}
