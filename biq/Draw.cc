#include "Draw.h"
using namespace std;



void drawPixel(int a, int b, Xwindow& board) {
    int x = 10;
    int y = 50;
    int w = 16;
    int c = 5;
    
    board.fillRectangle(x + w*a, y + w*b  ,w , w , c);
}


void drawInBoard(Xwindow &board) {
    

    string s1;
    //Coverpage
    while(1) {
        // start game
        
        //background
        board.fillRectangle( 0 , 0 , 600 , 550 , 0);
        
        // title screen
        //b
        drawPixel(3,0,board);
        drawPixel(3,1,board);
        drawPixel(3,2,board);
        drawPixel(3,3,board);
        drawPixel(3,4,board);
        drawPixel(3,5,board);
        drawPixel(3,6,board);
        drawPixel(4,6,board);
        drawPixel(5,6,board);
        drawPixel(5,5,board);
        drawPixel(5,4,board);
        drawPixel(4,4,board);
        
        //i
        drawPixel(7,2,board);
        drawPixel(7,4,board);
        drawPixel(7,5,board);
        drawPixel(7,6,board);
        
        //q
        drawPixel(11,4,board);
        drawPixel(10,4,board);
        drawPixel(9,4,board);
        drawPixel(9,5,board);
        drawPixel(9,6,board);
        drawPixel(10,6,board);
        drawPixel(11,5,board);
        drawPixel(11,6,board);
        drawPixel(11,7,board);
        drawPixel(11,8,board);
        
        //u
        drawPixel(13,4,board);
        drawPixel(13,5,board);
        drawPixel(13,6,board);
        drawPixel(14,6,board);
        drawPixel(15,6,board);
        drawPixel(15,5,board);
        drawPixel(15,4,board);
        
        //a
        drawPixel(18,4,board);
        drawPixel(17,5,board);
        drawPixel(18,6,board);
        drawPixel(19,6,board);
        drawPixel(19,5,board);
        
        //d
        drawPixel(22,4,board);
        drawPixel(21,4,board);
        drawPixel(21,5,board);
        drawPixel(21,6,board);
        drawPixel(22,6,board);
        drawPixel(23,1,board);
        drawPixel(23,2,board);
        drawPixel(23,3,board);
        drawPixel(23,4,board);
        drawPixel(23,5,board);
        drawPixel(23,6,board);
        
        
        //r
        drawPixel(25,4,board);
        drawPixel(26,5,board);
        drawPixel(26,6,board);
        drawPixel(27,4,board);
        
        //i
        drawPixel(29,2,board);
        drawPixel(29,4,board);
        drawPixel(29,5,board);
        drawPixel(29,6,board);
        
        //s
        drawPixel(33,3,board);
        drawPixel(32,3,board);
        drawPixel(31,4,board);
        drawPixel(32,5,board);
        drawPixel(33,6,board);
        drawPixel(32,7,board);
        drawPixel(31,7,board);
        

            
        string line1 = "Welcome to two players biquadris!";
        string line2 = "Here are some of the rules:";
        string line3 = "To control the blocks by commends with";
        string line4 = "right, left, down, drop, levelup, leveldown,";
        string line5 = "clockwise(cw) and counterclockwise(ccw).";
        string line6 = "Have fun!";

        board.drawString(100, 250, line1);
        board.drawString(100, 280, line2);
        board.drawString(100, 310, line3);
        board.drawString(100, 340, line4);
        board.drawString(100, 370, line5);
        board.drawString(100, 400, line6);
        
        //hint
        string c = "Press anykey to continue! ";
        board.drawString(225, 530, c);
        
        if(cin >> s1) break;
    }
    
    board.fillRectangle(0, 0, 600, 550, 0);
}