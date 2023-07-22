#ifndef __STARBLOCK_H__
#define __STARBLOCK_H__
#include "Block.h"


class starBlock : public Block{
    std::string BlkType = "*";
    int currentRotation;
protected:
    std::vector<std::vector <std::string>> v;
public:
    void clockw() override;
    void cclockw() override;
    starBlock();
    ~starBlock();
    void print () override;
    std::vector<std::vector <std::string>> getBlock() override;
    starBlock* copyBlock() override;
    std::string Type () override;
};

#endif