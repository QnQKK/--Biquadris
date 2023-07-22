#ifndef __LEVEL0_H__
#define __LEVEL0_H__

#include "Level.h"


struct Player;
extern std::string seqName1;
extern std::string seqName2;
extern int seedn;

class Level0 : public Level{
    
    int seqCt1;
    int seqCt2;
    std::vector<std::string> sList1;
    std::vector<std::string> sList2;
    
public:
    Level0();
    std::shared_ptr<Block> Blockg(std::shared_ptr<Player>  ) override;
    ~Level0();
    void aBS(std::string,int) override;
    void BackRan(int) override;
};



#endif 