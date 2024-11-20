#pragma once
#include <algorithm>
#include <math.h>

#include "Board.h"

struct Position {
  int x;
  int y;

  Position operator+(const Position &other) const {
    return Position{x + other.x, y + other.y};
  }

  bool operator==(const Position &other) const {
    return x == other.x && y == other.y;
  }
};

struct Node {
  Position pos;
  int g;
  int h;

  bool operator==(const Node &other) const {
    return g + h == other.g + other.h;
  }

  void Print(Node v) {
    cout << "{ ";
    for (auto item : {v.pos.x, v.pos.y, v.g, v.h}) {
      cout << item << " ";
    }
    cout << "}" << "\n";
  }
};

void PrintVectorOfNodes(vector<Node> v) {
  for (auto node : v) {
    cout << "{ ";
    for (auto col : {node.pos.x, node.pos.y, node.g, node.h}) {
      cout << col << " ";
    }
    cout << "}" << "\n";
  }
}

constexpr Position delta[4] = {
    Position{-1, 0},
    Position{0, -1},
    Position{1, 0},
    Position{0, 1},
};

int Heuristic(Position a, Position b) {
  return abs(b.x - a.x) + abs(b.y - a.y);
}

bool Compare(Node v1, Node v2) { return v1.g + v1.h - v2.g - v2.h > 0; }

/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<Node> *v) { sort(v->begin(), v->end(), Compare); }

bool CheckValidCell(const Node node, const Board &grid) {
  if (node.pos.x >= 0 && node.pos.x < static_cast<int>(grid.size()) &&
      node.pos.y >= 0 && node.pos.y < static_cast<int>(grid[0].size())) {
    return grid[node.pos.x][node.pos.y] == State::kEmpty;
  }

  return false;
}

Board Search(Board board, const Position &start, const Position &target) {
  // Queue with open nodes.
  vector<Node> open{};

  // Initialize the starting node.
  Node startNode = {start, 0, Heuristic(start, target)};

  // AddToOpen(x, y, g, h, open, board);
  open.push_back(startNode);
  board[startNode.pos.x][startNode.pos.y] = State::kClosed;

  // int step = 0;
  while (!open.empty()) {
    CellSort(&open);
    auto node = open.back();
    open.pop_back();

    board[node.pos.x][node.pos.y] = State::kPath;

    if (node.pos == target) {
      board[start.x][start.y] = State::kStart;
      board[node.pos.x][node.pos.y] = State::kFinish;
      return board;
    }

    // Check sibling nodes
    for (const auto &d : delta) {
      Position nextPos = node.pos + d;
      Node nextNode = {nextPos, node.g + 1, Heuristic(nextPos, target)};

      if (CheckValidCell(nextNode, board)) {
        open.push_back(nextNode);
        board[nextNode.pos.x][nextNode.pos.y] = State::kClosed;
      }
    }
  }

  cout << "No path found!" << "\n";
  return Board{};
}
