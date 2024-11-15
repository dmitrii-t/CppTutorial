#pragma once
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>

#include "Search.h"

using namespace std;

void TestCompare() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Compare Function Test: ";
  Node test_1{1, 2, 5, 6};
  Node test_2{1, 3, 5, 7};
  Node test_3{1, 2, 5, 8};
  Node test_4{1, 3, 5, 7};
  if (Compare(test_1, test_2)) {
    cout << "failed" << "\n";
    cout << "\n" << "a = ";
    test_1.Print(test_1);
    cout << "b = ";
    test_2.Print(test_2);
    cout << "Compare(a, b): " << Compare(test_1, test_2) << "\n";
    cout << "Correct answer: 0" << "\n";
    cout << "\n";
  } else if (!Compare(test_3, test_4)) {
    cout << "failed" << "\n";
    cout << "\n" << "a = ";
    test_3.Print(test_3);
    cout << "b = ";
    test_4.Print(test_4);
    cout << "Compare(a, b): " << Compare(test_3, test_4) << "\n";
    cout << "Correct answer: 1" << "\n";
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}

void TestSearch() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Search Function Test: ";
  Position init{0, 0};
  Position goal{4, 5};
  Board board{};
  ReadBoardFile("board.txt", board);
  // std::cout.setstate(std::ios_base::failbit); // Disable cout
  auto output = Search(board, init, goal);
  // std::cout.clear(); // Enable cout
  Board solution{{State::kStart, State::kObstacle, State::kEmpty, State::kEmpty,
                  State::kEmpty, State::kEmpty},
                 {State::kPath, State::kObstacle, State::kEmpty, State::kEmpty,
                  State::kEmpty, State::kEmpty},
                 {State::kPath, State::kObstacle, State::kEmpty, State::kClosed,
                  State::kClosed, State::kClosed},
                 {State::kPath, State::kObstacle, State::kClosed, State::kPath,
                  State::kPath, State::kPath},
                 {State::kPath, State::kPath, State::kPath, State::kPath,
                  State::kObstacle, State::kFinish}};

  if (output != solution) {
    cout << "failed" << "\n";
    cout << "Search(board, {0,0}, {4,5})" << "\n";
    cout << "Solution board: " << "\n";
    PrintBoard(solution);
    cout << "Your board: " << "\n";
    PrintBoard(output);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  return;
}

void TestCheckValidCell() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "CheckValidCell Function Test: ";
  Board grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty,
              State::kEmpty, State::kEmpty},
             {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty,
              State::kEmpty, State::kEmpty},
             {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty,
              State::kEmpty, State::kEmpty},
             {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty,
              State::kEmpty, State::kEmpty},
             {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty,
              State::kObstacle, State::kEmpty}};

  if (CheckValidCell({0, 0, 0, 0}, grid)) {
    cout << "failed" << "\n";
    cout << "\n" << "Test grid is: " << "\n";
    PrintBoard(grid);
    cout << "Cell checked: (0, 0)" << "\n";
    cout << "\n";
  } else if (!CheckValidCell({4, 2, 0, 0}, grid)) {
    cout << "failed" << "\n";
    cout << "\n" << "Test grid is: " << "\n";
    PrintBoard(grid);
    cout << "Cell checked: (4, 2)" << "\n";
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
}

void TestReadBoardFile() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Read Board Function Test: ";
  Board board{};
  ReadBoardFile("board.txt", board);
  Board expected{{State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty,
                  State::kEmpty, State::kEmpty},
                 {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty,
                  State::kEmpty, State::kEmpty},
                 {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty,
                  State::kEmpty, State::kEmpty},
                 {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty,
                  State::kEmpty, State::kEmpty},
                 {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty,
                  State::kObstacle, State::kEmpty}};

  if (board != expected) {
    cout << "failed" << "\n";
    cout << "Expected board: " << "\n";
    PrintBoard(expected);
    cout << "Your board: " << "\n";
    PrintBoard(board);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  return;
}
