#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "Board.h"
#include "Block.h"
#include "Cell.h"
#include "Level.h"
#include "Level0.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"


struct Player{
    std::vector <std::vector <Cell>> Field;
    std::string name;
    int id;
    int Sco;
    int curLev;
    int col;
    int row;
    bool LPoss;
    bool RPoss;
    bool DPoss;
    int downImposs;
    std::unique_ptr<Level> levptr;
    bool clockPossible;
    bool counterCPossible;
    std::shared_ptr<Block> CurBlock;
    std::shared_ptr<Block> NextBlock;
    
    bool Active;
    int SpeAttack;

    // keeping track of score
    int IScore;
    int JScore;
    int LScore;
    int OScore;
    int SScore;
    int TScore;
    int ZScore;
    
    // keep track for Heavy
    bool heavy;
    
    // Tracker for lvl 4
    int notclear = 0;
    bool starblk = false;
};

#endif