#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "Block.h"

class LBlock : public Block{
    std::string BlkType = "L";
    int currentRotation;
protected:
    std::vector<std::vector <std::string>> v;

public:
    void clockw() override;
    void cclockw() override;
    LBlock();
    ~LBlock();
    void print () override;
    std::vector<std::vector <std::string>> getBlock() override;
    LBlock* copyBlock () override;
    std::unique_ptr<LBlock> blockCpy();
    std::string Type () override;
};

#endif