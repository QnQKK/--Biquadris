#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "Block.h"
class TBlock : public Block{
    std::string BlkType = "T";
    int currentRotation;
protected:
    std::vector<std::vector <std::string>> v;
public:
    void clockw() override;
    void cclockw() override;
    TBlock();
    ~TBlock();
    void print() override;
    std::vector<std::vector <std::string>> getBlock() override;
    TBlock* copyBlock() override;
    std::unique_ptr<TBlock> blockCpy();
    std::string Type () override;
};


#endif