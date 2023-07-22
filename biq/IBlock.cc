#include "IBlock.h"
using namespace std;

IBlock:: IBlock() {
    currentRotation = 0;
    v.resize(5);
    for (int i = 0; i < 4; ++i) {
        v.resize(4);
    }
    v = {
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {"I", "I", "I", "I"},
        {" ", " ", " ", " "},
    }; 
}

IBlock::~IBlock() {}

void IBlock::clockw() {
    if (currentRotation == 1) {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"I", "I", "I", "I"},
            {" ", " ", " ", " "},
        };
        currentRotation = 0;
    } else {
        v = {
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {" ", " ", " ", " "},
        };
        currentRotation = 1;
    }
}

void  IBlock::cclockw() {
   if ( currentRotation == 1) {
        v = {
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {"I", " ", " ", " "},
            {" ", " ", " ", " "},
        };
        currentRotation = 0;
    } else {
        v = {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {"I", "I", "I", "I"},
            {" ", " ", " ", " "},
        };
        currentRotation = 1;
    } 
}

void IBlock::print() {
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> IBlock::getBlock() {
    return this->v;
}

IBlock* IBlock::copyBlock() {
    return new IBlock(*this);
}

unique_ptr<IBlock> IBlock::blockCpy() {
    return std::unique_ptr<IBlock> (this->copyBlock());
}

string IBlock::Type() {
    return BlkType;
}