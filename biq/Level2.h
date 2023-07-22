#ifndef __LEVEL2_H__
#define __LEVEL2_H__

#include "Level.h"

struct Player;
extern std::string seqName1;
extern std::string seqName2;
extern int seedn;

class Level2 : public Level{
    
    int seqCt1_int;
    int seqCt2_int;
    std::vector<int> numseqLt1;
    std::vector<int> numseqLt2;
    
    
public:
    Level2();
    std::shared_ptr<Block> Blockg(std::shared_ptr<Player>  ) override;
    ~Level2();
    void aBS(std::string,int) override;
    void BackRan(int) override;
};


#endif 