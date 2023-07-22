#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "Block.h"


class IBlock : public Block{
    std::string BlkType = "I";
    int currentRotation;
protected:
    std::vector<std::vector <std::string>> v;
public:
    void clockw() override;
    void cclockw() override;
    IBlock();
    ~IBlock();
    void print() override;
    std::vector<std::vector <std::string>> getBlock() override;
    IBlock* copyBlock() override;
    std::unique_ptr<IBlock> blockCpy();
    std::string Type() override;
};

#endif