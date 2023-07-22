#include "LBlock.h"
using namespace std;

LBlock::LBlock() {
    currentRotation = 0;
    v.resize(5);
    for (int i = 0; i < 4; ++i) {
        v.resize(4);
    }
    v = {
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", "L", " "},
        {"L", "L", "L", " "},
    };
}

LBlock::~LBlock() {}

void LBlock::clockw() {
    if (currentRotation == 0) {
        v = {
                {" ", " ", " ", " "},
                {" ", " ", " ", " "},
                {"L", " ", " ", " "},
                {"L", " ", " ", " "},
                {"L", "L", " ", " "},
            };
        currentRotation = 1;
    } else if (currentRotation == 1) {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"L", "L", "L", " "},
            {"L", " ", " ", " "},
        };
        currentRotation = 2;
    } else if (currentRotation == 2) {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"L", "L", " ", " "},
            {" ", "L", " ", " "},
            {" ", "L", " ", " "},
        };
        currentRotation = 3;
    } else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", "L", " "},
            {"L", "L", "L", " "},
        };
        currentRotation = 0;
    }
}

void LBlock:: cclockw() {
    clockw();
    clockw();
    clockw();
}

void LBlock::print() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> LBlock::getBlock() {
    return this->v;
}

LBlock* LBlock::copyBlock() {
    return new LBlock(*this);
}
unique_ptr<LBlock> LBlock::blockCpy() {
    return unique_ptr<LBlock> (this->copyBlock());
}
string LBlock::Type() {
    return BlkType;
}