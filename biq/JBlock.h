#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "Block.h"

class JBlock : public Block {
    std::string BlkType = "J";
    int currentRotation;
protected:
    std::vector<std::vector <std::string>> v;
public:
    void clockw() override;
    void cclockw() override;
    JBlock();
    ~JBlock();
    void print() override;
    std::vector<std::vector <std::string>> getBlock() override;
    JBlock* copyBlock() override;
    std::unique_ptr<JBlock> blockCpy();
    std::string Type() override;
};

#endif