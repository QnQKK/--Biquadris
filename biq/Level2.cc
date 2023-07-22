#include "Level2.h"
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

Level2::Level2(){
    levnum = 2;
    int seqCt1_int = 0;
    int seqCt2_int = 0;
    srand(seedn);
    for(int i = 0 ; i < 4 ; i++ ) {
        numseqLt1.emplace_back(rand() % 7 + 1);
    }//for player1
    for(int i = 0 ; i < 4 ; i++ ) {
        numseqLt2.emplace_back(rand() % 7 + 1);
    }//for player2
}

//we pretend we need this function but actually not
void Level2::aBS(std::string filename,int id){}

Level2::~Level2(){};

shared_ptr<Block> Level2::Blockg(std::shared_ptr<Player> pler){
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
        case 5: bp = make_shared<TBlock>(); break;
        case 6: bp = make_shared<ZBlock>(); break;
        case 7: bp = make_shared<SBlock>(); break;
    }
    return bp;
}

void Level2::BackRan(int id ){}