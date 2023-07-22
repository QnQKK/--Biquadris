#include "Level3.h"
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

Level3::Level3(){
    levnum = 3;
    rb1 = true;//yes default is rb
    rb2 = true;
    seqCt1 = 0;
    seqCt2 = 0;//
    seqCt1_int = 0;
    seqCt2_int = 0;
    
    srand(seedn);
    for(int i = 0 ; i < 4 ; i++ ) {
        numseqLt1.emplace_back(rand() % 9 + 1);
    }//for player1
    for(int i = 0 ; i < 4 ; i++ ) {
        numseqLt2.emplace_back(rand() % 9 + 1);
    }//for player2
}

Level3::~Level3(){}

void Level3::aBS(std::string filename,int id){
    string s;
    if (id == 1){
        ifstream seq1{filename};
        while(seq1 >> s){
            string p1 = s;
            sList1.emplace_back(p1);
        }
        rb1 = false;
    }else {
        ifstream seq2{filename};
        while(seq2 >> s){
            string p2 = s;
            sList2.emplace_back(p2);
        }
        rb2 = false;
    }
}

shared_ptr<Block> Level3::Blockg(std::shared_ptr<Player> pler){
    shared_ptr<Block> bp = nullptr;
    bool random = false;
    if ((pler->id == 1) && rb1) random = true;
    if ((pler->id == 2) && rb2) random = true;
    if(random){
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
            case 6: bp = make_shared<SBlock>(); break;
            case 7: bp = make_shared<SBlock>(); break;
            case 8: bp = make_shared<ZBlock>(); break;
            case 9: bp = make_shared<ZBlock>(); break;
        }
    } else {
        
        //use weird file to get block
        char c;
        if(pler->id == 1){
            if(seqCt1 > sList1.size() - 1){
                seqCt1 = 0;
            }
            
            c = sList1[seqCt1][0];
            ++seqCt1;
            
        } else {//2
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
    }
    return bp;
}

void Level3::BackRan(int id ){
    if (id == 1){
        rb1 = true;
    }else if (id == 2){
        rb2 = true;
    }
    
}