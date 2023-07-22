#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "Block.h"

class OBlock : public Block{
    std::string BlkType = "O";
    int currentRotation;
protected:
    std::vector<std::vector <std::string>> v;
public:
    void clockw() override;
    void  cclockw() override;
    OBlock();
    ~OBlock();
    void print() override;
    std::vector<std::vector <std::string>> getBlock() override;
    OBlock* copyBlock() override;
    std::unique_ptr<OBlock> blockCpy();
    std::string Type() override;
};

#endif