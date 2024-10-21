#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

enum class State; // forward declaration
using Board = vector<vector<State>>;
using Row = vector<State>;

enum class State
{
    // Order matters as (static_cast<State>(i) is used for conversion
    kEmpty,
    kObstacle,

    kClosed,
    kPath,
    kStart,
    kFinish,
};

// Converts 
// "⛰️   "
// "0   "
string CellToString(State state)
{
    switch (state)
    {
        // case State::kObstacle: return "⛰️   ";
        // case State::kClosed: return "x   ";
        // case State::kPath: return "🚗   ";
        // default: return "0   ";
    case State::kObstacle: return "^   ";
    case State::kClosed: return "x   ";
    case State::kPath: return ".   ";
    case State::kStart: return "S   ";
    case State::kFinish: return "F   ";
    default: return "0   ";
    }
}

void PrintBoard(const Board& v)
{
    for (const auto& row : v)
    {
        cout << "{ ";
        for (const auto& col : row)
        {
            cout << CellToString(col) << " ";
        }
        cout << "}" << "\n";
    }
}

bool ParseLine(string str, Row& row)
{
    bool result = false;

    istringstream iss(str);
    int i;
    char c;
    while (iss >> i >> c && c == ',')
    {
        row.push_back(static_cast<State>(i));
        result = true;
    }
    return result;
}

bool ReadBoardFile(string path, Board& board)
{
    ifstream file(path);
    if (!file)
    {
        cout << "Failed to open file " << path << endl;
        return false;
    }

    // Check for UTF-8 BOM
    char bom[3];
    file.read(bom, 3);
    if (!(bom[0] == (char)0xEF && bom[1] == (char)0xBB && bom[2] == (char)0xBF))
    {
        // If not BOM, reset file pointer to beginning
        file.seekg(0);
    }

    string line;
    while (getline(file, line))
    {
        vector<State> row{};
        if (ParseLine(line, row))
        {
            board.push_back(row);
        }
    }
    return true;
}
