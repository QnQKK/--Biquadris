#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include <vector>
#include <memory>
#include <iostream>


class Block {
protected:
    std::vector<std::vector <std::string>> v;
public:
    Block();
    Block(const Block& b);
    Block &operator=(const Block& b);
    virtual void clockw() = 0;
    virtual void cclockw() = 0;
    virtual ~Block();
    virtual void print() = 0;
    virtual std::vector<std::vector <std::string>> getBlock() = 0;
    virtual Block* copyBlock() = 0;
    std::shared_ptr<Block> blockCpy() {
        return std::shared_ptr<Block> (this->copyBlock());
    }
    virtual std::string Type() = 0;
};

#endif
