#ifndef __BOURD_H__
#define __BOURD_H__

#include "Player.h"
#include "Window.h"
#include <memory>


class Board {
public:
    Board();
    virtual ~Board() = 0;
    virtual void createBoard(std::shared_ptr <Player>& player1, std::shared_ptr <Player>& player2, Xwindow *board) = 0;
    virtual int ReCalc(std::shared_ptr <Player>& player) = 0;
};



#endif 