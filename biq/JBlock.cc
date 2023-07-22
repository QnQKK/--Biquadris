#include "JBlock.h"
using namespace std;

JBlock::JBlock() {
    currentRotation = 0;
    v.resize(5);
    for (int i = 0; i < 4; ++i) {
        v.resize(4);
    }
    v = {
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {"J", " ", " ", " "},
        {"J", "J", "J", " "},
    };
}

JBlock::~JBlock() {}

void JBlock::clockw() {
    if (currentRotation == 0) {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"J", "J", " ", " "},
            {"J", " ", " ", " "},
            {"J", " ", " ", " "},
        };
        currentRotation = 1;
    } else if (currentRotation == 1) {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"J", "J", "J", " "},
            {" ", " ", "J", " "},
        };
        currentRotation = 2;
    } else if (currentRotation == 2) {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", "J", " ", " "},
            {" ", "J", " ", " "},
            {"J", "J", " ", " "},
        };
        currentRotation = 3;
    } else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"J", " ", " ", " "},
            {"J", "J", "J", " "},
        };
        currentRotation = 0;
    }
}

void JBlock::cclockw() {
    clockw();
    clockw();
    clockw();
}

void JBlock::print() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> JBlock::getBlock() {
    return this->v;
}

JBlock* JBlock::copyBlock() {
    return new JBlock(*this);
}

unique_ptr<JBlock> JBlock::blockCpy() {
    return unique_ptr<JBlock> (this->copyBlock());
}

string JBlock::Type() {
    return BlkType;
}