#include "Level0.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

extern string seqName1;
extern string seqName2;
extern int seedn;


Level0::Level0(){
    
    ifstream seq1{seqName1};
    ifstream seq2{seqName2};
    
    string s;
    while(seq1 >> s){
        string p1 = s;
        sList1.emplace_back(p1);
    }
    while(seq2 >> s){
        string p2 = s;
        sList2.emplace_back(p2);
    }
    
    seqCt1 = 0;
    seqCt2 = 0;
    levnum = 0;
}

Level0::~Level0(){}

//we pretend we need this function but actually not
void Level0::aBS(std::string filename,int id){}

//Return a block pointer
shared_ptr<Block> Level0::Blockg(std::shared_ptr<Player> p){
    shared_ptr<Block> bp = nullptr;
    char c;
    if(p->id == 1){
        if(seqCt1 > sList1.size() - 1){
            seqCt1 = 0;
        }
        

        c = sList1[seqCt1][0];
        ++seqCt1;
        
    } else {
        if(seqCt2 > sList2.size() - 1){
            seqCt2 = 0;
        }
        c = sList2[seqCt2][0];
        ++seqCt2;
    }
    switch(c){
        case 'J' : bp = make_shared<JBlock>();break;
        case 'O' : bp = make_shared<OBlock>();break;
        case 'L' : bp = make_shared<LBlock>();break;
        case 'I' : bp = make_shared<IBlock>();break;
        case 'S' : bp = make_shared<SBlock>();break;
        case 'Z' : bp = make_shared<ZBlock>();break;
        case 'T' : bp = make_shared<TBlock>();break;
            
    }
    return bp;
}


void Level0::BackRan(int id ){}