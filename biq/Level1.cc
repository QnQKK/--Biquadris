#include "Level1.h"
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


Level1::Level1(){
    levnum = 1;
    seqCt1_int = 0;
    seqCt2_int = 0;
    
    srand(seedn);
    for(int i = 0 ; i < 4 ; i++ ) {
        numseqLt1.emplace_back(rand() % 12 + 1);
    }//for player1
    for(int i = 0 ; i < 4 ; i++ ) {
        numseqLt2.emplace_back(rand() % 12 + 1);
    }//for player2
}

Level1::~Level1(){}

//we pretend we need this function but actually not
void Level1::aBS(std::string filename,int id){}

//
shared_ptr<Block> Level1::Blockg(std::shared_ptr<Player> pler){
    shared_ptr<Block> bp = nullptr;
    int rm = 1;
    //
    if(pler->id == 1){
        if(seqCt1_int > numseqLt1.size() - 1){//reset
            seqCt1_int = 0;
        }
        
        rm = numseqLt1[seqCt1_int];
        ++seqCt1_int;
        
    } else {
        if(seqCt2_int > numseqLt2.size() - 1){//reset
            seqCt2_int = 0;
        }
        rm = numseqLt2[seqCt2_int];
        ++seqCt2_int;
    }
    switch (rm){
        case 1: bp = make_shared<LBlock>(); break;
        case 2: bp = make_shared<IBlock>(); break;
        case 3: bp = make_shared<OBlock>(); break;
        case 4: bp = make_shared<JBlock>(); break;
        case 5: bp = make_shared<TBlock>(); break;//
        case 6: bp = make_shared<LBlock>(); break;
        case 7: bp = make_shared<IBlock>(); break;
        case 8: bp = make_shared<OBlock>(); break;
        case 9: bp = make_shared<JBlock>(); break;
        case 10: bp = make_shared<TBlock>(); break;//
        case 11: bp = make_shared<ZBlock>(); break;
        case 12: bp = make_shared<SBlock>(); break;
    }
    return bp;
}

void Level1::BackRan(int id ){}