#include "starBlock.h"
#include <iostream>
using namespace std;



starBlock::starBlock(){
    currentRotation = 0;

    v.resize(5);
    v[0].resize(4);
    v = {
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", "*"},
        {" ", " ", " ", " "},
        
    };
}

starBlock::~starBlock(){}

void starBlock::clockw(){};

void starBlock:: cclockw(){};

void starBlock::print(){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector <string>> starBlock::getBlock(){
    return this->v;
}

starBlock* starBlock::copyBlock (){
    return new starBlock (*this);
}

string starBlock::Type (){
    return BlkType;
}