#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "Block.h"

class ZBlock: public Block{
    std::string BlkType = "Z";
    int currentRotation;
protected:
    std::vector<std::vector <std::string>> v;
public:
    void clockw() override;
    void cclockw() override;
    ZBlock();
    ~ZBlock();
    void print() override;
    std::vector<std::vector <std::string>> getBlock() override;
    ZBlock* copyBlock() override;
    std::unique_ptr<ZBlock> blockCpy();
    std::string Type () override;
};

#endif