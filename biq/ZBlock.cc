#include "ZBlock.h"
using namespace std;


ZBlock::ZBlock() {
    currentRotation = 0;
    v.resize(5);
    for (int i = 0; i < 4; ++i) {
        v.resize(4);
    }
    v = {
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {"Z", "Z", " ", " "},
        {" ", "Z", "Z", " "},
    };
}

ZBlock::~ZBlock() {}

void ZBlock::clockw() {
    if (currentRotation == 0) {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", "Z", " ", " "},
            {"Z", "Z", " ", " "},
            {"Z", " ", " ", " "},
        };
        currentRotation = 1;
    } else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"Z", "Z", " ", " "},
            {" ", "Z", "Z", " "},
        };
        currentRotation = 0;
    }
}

void ZBlock::cclockw() {
    clockw();
    clockw();
    clockw();
}

void ZBlock::print() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> ZBlock::getBlock() {
    return this->v;
}

ZBlock* ZBlock::copyBlock() {
    return new ZBlock(*this);
}

unique_ptr<ZBlock> ZBlock::blockCpy() {
    return unique_ptr<ZBlock> (this->copyBlock());
}

string ZBlock::Type() {
    return BlkType;
}