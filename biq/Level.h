#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Block.h"
#include "LBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "IBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
#include "starBlock.h"


struct Player;
extern std::string seqName1;
extern std::string seqName2;
extern int seedn;


//The abstract level class
class Level{
    
public:
    int levnum;
    int GetLevel() const;
    virtual std::shared_ptr<Block> Blockg(std::shared_ptr<Player> ) = 0;
    virtual ~Level() = 0;
    virtual void aBS(std::string,int) = 0;
    virtual void BackRan(int) = 0;
    
};

#endif