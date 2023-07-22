#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include "Level.h"

struct Player;
extern std::string seqName1;
extern std::string seqName2;
extern int seedn;

class Level1 : public Level{
    
    int seqCt1_int;
    int seqCt2_int;
    std::vector<int> numseqLt1;
    std::vector<int> numseqLt2;
    
    
public:
    Level1();
    std::shared_ptr<Block> Blockg(std::shared_ptr<Player>  ) override;
    ~Level1();
    void aBS(std::string,int) override;
    void BackRan(int) override;
};

#endif 