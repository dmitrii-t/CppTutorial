#include "../include/DataRaces.hpp"
#include "DeepCopy.hpp"
#include "MoveConst.hpp"

int main() {
    TestDataRace();
    TestDeepCopy();
    TestMoveConstructor();
    return 0;
}