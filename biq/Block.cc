#include "Block.h"
using namespace std;

Block::Block () {}
Block::~Block() {}

Block::Block(const Block& b) {
    v = b.v;
}

Block &Block::operator=(const Block& other) {
    if (this == &other) return *this;
    v = other.v;
    return *this;
}
