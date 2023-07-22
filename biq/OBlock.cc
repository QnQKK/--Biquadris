#include "OBlock.h"
using namespace std;



OBlock::OBlock() {
    currentRotation= 0;
    v.resize(5);
    for (int i = 0; i < 4; ++i) {
        v.resize(4);
    }
    v = {
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {"O", "O", " ", " "},
        {"O", "O", " ", " "},
    };
}

OBlock::~OBlock() {}

void OBlock::clockw() {}

void OBlock:: cclockw() {}

void OBlock::print() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> OBlock::getBlock() {
    return this->v;
}

OBlock* OBlock::copyBlock() {
    return new OBlock(*this);
}

unique_ptr<OBlock> OBlock::blockCpy() {
    return unique_ptr<OBlock> (this->copyBlock());
}

string OBlock::Type() {
    return BlkType;
}