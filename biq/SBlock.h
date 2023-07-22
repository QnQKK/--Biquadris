#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "Block.h"

class SBlock: public Block {
    std::string BlkType = "S";
    int currentRotation;
protected:
    std::vector<std::vector <std::string>> v;
public:
    void clockw() override;
    void cclockw() override;
    SBlock();
    ~SBlock();
    void print() override;
    std::vector<std::vector <std::string>> getBlock() override;
    SBlock* copyBlock() override;
    std::unique_ptr<SBlock> blockCpy();
    std::string Type() override;
};

#endif 
