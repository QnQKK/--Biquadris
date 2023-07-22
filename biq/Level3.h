#ifndef __LEVEL3_H__
#define __LEVEL3_H__

#include "Level.h"


struct Player;
extern std::string seqName1;
extern std::string seqName2;
extern int seedn;

class Level3 : public Level{
    
    int seqCt1;
    int seqCt2;
    int seqCt1_int;
    int seqCt2_int;
    bool rb1;
    bool rb2;
    std::vector<std::string> sList1;
    std::vector<std::string> sList2;
    std::vector<int> numseqLt1;
    std::vector<int> numseqLt2;
    
    
public:
    
    Level3();
    std::shared_ptr<Block> Blockg(std::shared_ptr<Player>  ) override;
    ~Level3();
    void aBS(std::string,int) override;
    void BackRan(int) override;
};

#endif 