#ifndef __BIQBOARD_H__
#define __BIQBOARD_H__
#include "Board.h"
#include "Player.h"
#include "Cell.h"
#include "Window.h"
#include "Block.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

struct Player;

class BiqBoard : public Board {
    std::shared_ptr <Player> pler1;
    std::shared_ptr <Player> pler2;
public:
    bool Textmode = false;
    // finish part
    BiqBoard ();
    ~BiqBoard ();
    void SetPler(std::shared_ptr <Player>& pler, std::string playername,int id,int level);
    std::shared_ptr <Player>& Getpler1();
    std::shared_ptr <Player>& Getpler2();
    int gCS(std::shared_ptr <Player>& pler);
    void createBoard(std::shared_ptr <Player>& pler1, std::shared_ptr <Player>& pler2, Xwindow * board) override;
    bool DrawBlock(std::shared_ptr <Player>& pler, int x, int y);
    void DrawNextBlock(std::shared_ptr <Player>& pler1, std::shared_ptr <Player>& pler2, Xwindow  * board);
    // method made for DrawBlock
    bool availableCells(std::shared_ptr <Player>& pler, int x, int y);
    bool turn = true;
    std::shared_ptr <Player>& NowPlayer();
    void switchPlayer();
    std::shared_ptr <Player>& OtherPlayer();
    void left(std::shared_ptr <Player>& pler);
    void right(std::shared_ptr <Player>& pler);
    void down(std::shared_ptr <Player>& pler);
    void drop(std::shared_ptr <Player>& pler);
    void clockPossible(std::shared_ptr <Player>& pler);
    void counterCPossible(std::shared_ptr <Player>& pler);
    void initialPossibilities();
    void updatePoss(std::shared_ptr <Player>& pler);
    int ReCalc(std::shared_ptr <Player>& pler) override;
    void destroyLine(std::shared_ptr <Player>& pler, std::vector<int> &clean_row);
    void LevelUp(std::shared_ptr <Player>& pler);
    void LevelDown(std::shared_ptr <Player>& pler);
    void deadCell(std::shared_ptr <Player>& pler);
    void LevelHeavy(std::shared_ptr <Player>& pler);
    void BlockHeavy(std::shared_ptr <Player>& pler);
    void Blind(std::shared_ptr <Player>& pler);
    bool GameOver(std::shared_ptr <Player>& pler);
    void Restart(std::shared_ptr <Player>& pler1, std::shared_ptr <Player>& pler2);
};

#endif

