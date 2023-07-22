#include <iostream>
#include "BiqBoard.h"
#include "Board.h"
#include "Cell.h"
#include "Player.h"
#include "Level.h"
#include "starBlock.h"
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <memory>
#include <fstream>

#include "Window.h"
#include "Draw.h"

using namespace std;

string seqName1 = "biquadris_sequence1.txt";
string seqName2 = "biquadris_sequence2.txt";
string norstring;
string seqstring;
int seedn = 111;
bool specialOn = false;




int main(int argc, const char * argv[]) {
    //begin
    int startlevel = 0; 
    BiqBoard b;

    if (argc > 1) {
        for (int i = 1 ; i < argc ; i++) {
            if(argv[i][0] == '-') {
                //-t or -text
                // text-only mode
                if(argv[i][1] == 't'){
                    cout << "text only mode!" << endl;
                    b.Textmode = true;
                }
                // changing the sequence
                if (argv[i][1] == 's') {
                    if (argv[i][2] == 'c') {
                        //scriptfile1
                        if (strncmp(argv[i],"-scriptfile1",12) == 0) {
                            i++;
                            if ((i >= argc) || (argv[i][0] == '-')) {
                                cout << "you forget to give me a filename!"<< endl;
                                i--;
                            } else {
                                seqName1 = argv[i];
                                seqName1 = argv[i];
                                cout << "we will find" << seqName1 << " seq for player1!" << endl;
                            }
                        }
                        //-scriptfile2
                        if (strncmp(argv[i],"-scriptfile2",12) == 0) {
                            i++;
                            if ((i >= argc) || (argv[i][0] == '-')) {
                                cout << "you forget to give me a filename!"<< endl;
                                i--;
                            } else {
                                seqName2 = argv[i];
                                cout << "we will find" << seqName2 << " seq for player2!" << endl;
                            }
                        }
                    }
                    // seed
                    if(argv[i][2] == 'e') {
                        if(strncmp(argv[i],"-seed",5)) {
                            i++;
                            if ((i >= argc) || (argv[i][0] < '0') ||(argv[i][0] > '9' )) {
                                cout << "you forget to give a number for seed!"<< endl;
                                i--;
                            } else {
                                seedn = stoi(argv[i]);
                            }
                        }
                    }
                }
            }
        }
    }

    Xwindow board(600, 550);
    drawInBoard(board);


    // default/initial settings for Players
    string type;
    string command;
    

    shared_ptr <Player>& player1 = b.Getpler1();
    shared_ptr <Player>& player2 = b.Getpler2();
    

    b.SetPler(player1, "Murtaza", 1, startlevel);
    b.SetPler(player2, "Qianli", 2, startlevel);
    

    player1->CurBlock = player1->levptr->Blockg(player1);
    player1->NextBlock = player1->levptr->Blockg(player1);
    
    
    player2->CurBlock = player2->levptr->Blockg(player2);
    player2->NextBlock = player2->levptr->Blockg(player2);
    
    
    b.DrawBlock(player1, player1->row, player1->col);
    
    
    b.createBoard(player1, player2, &board);
    
     
    // terminal interface
    string cmdp;
    if (b.Textmode) {
        board.drawString(200, 250, "Terminal Biquadris.");
    }
    while(cin >> cmdp) {
        vector<string> seqList;
        seqList.emplace_back("mapping"); //the initial size will be 1
        if (cmdp == "sequence") {
            string comfile;
            cin >> comfile;
            ifstream comseq{comfile};
            string s;
            while(comseq >> s) {
                string tb = s;
                seqList.emplace_back(tb);
            }

       } else {
           seqList.emplace_back(cmdp);
       }
        
        // _the_ real_ command
        while(seqList.size() != 1) {
            int num = -111; // error number
            int i = 0;
            string cmd = seqList[seqList.size() - 1];
            if((cmd[0] <= '9')&&(cmd[0] >= '0')) num = 0;
            while((cmd[i] <= '9')&&(cmd[i] >= '0')) {
                num =  num + stoi(string(1,cmd[0])) * pow(10 , i);
                ++i;
            }
            string temp = "";
            int len = cmd.length();
            while(i < len) {
                temp = temp + cmd[i];
                ++i;
            }

            cmd = temp;
        
            b.deadCell(player1);
            b.deadCell(player2);
        
            string cont;
            if (!b.GameOver (player1)) {
                cout << "Player1's game is over" << endl;
                cout << "Do you want to restart? [y/n] " << endl;
            
                cin >> cont;
                if (cont == "y") {
                    b.Restart(b.NowPlayer(), b.OtherPlayer());
                    b.NowPlayer()->CurBlock = b.NowPlayer()->levptr->Blockg(player1);
                    b.NowPlayer()->NextBlock = b.NowPlayer()->levptr->Blockg(player1);
                    b.OtherPlayer()->CurBlock = b.OtherPlayer()->levptr->Blockg(player2);
                    b.OtherPlayer()->NextBlock = b.OtherPlayer()->levptr->Blockg(player2);
                    cmd = " ";
                } else {
                    break;
                }
            }
            if (!b.GameOver (player2)) {
                cout << "Player2's game is over" << endl;
                cout << "Do you want to restart? [y/n] " << endl;
                cin >> cont;
                if (cont == "y") {
                    b.Restart(b.NowPlayer(), b.OtherPlayer());
                    b.NowPlayer()->CurBlock = b.NowPlayer()->levptr->Blockg(player1);
                    b.NowPlayer()->NextBlock = b.NowPlayer()->levptr->Blockg(player1);
                    b.OtherPlayer()->CurBlock = b.OtherPlayer()->levptr->Blockg(player2);
                    b.OtherPlayer()->NextBlock = b.OtherPlayer()->levptr->Blockg(player2);
 	            cmd = " ";
                } else {
                    break;
                }
            }

            if(cmd[0] == 'c') {
                //clockwise and counterclockwise
                if (cmd.length() > 1) { // clockwise
                    if (cmd[1] == 'c') { // ccw
                        if(num < 0) num = 1;
                        for(;num > 0;num--) {
                            if (b.NowPlayer()->counterCPossible){
                                b.NowPlayer()->CurBlock->cclockw();
                            }
                            b.initialPossibilities();
                            b.updatePoss(b.NowPlayer());
                        
                        }
                    }
                    if(cmd[1] == 'l') { // clockwise
                        if(num < 0) num = 1;
                        for(;num > 0;num--) {
                            if (b.NowPlayer()->clockPossible) {
                                b.NowPlayer()->CurBlock->clockw();
                            }
                            b.initialPossibilities();
                            b.updatePoss(b.NowPlayer());
                        }
                    }
                    // we also have cw for clockwise and ccw for counterclockwise
                    if(cmd[1] == 'o') { // counterclockwise
                        if(num < 0) num = 1;
                        for(;num > 0;num--){
                            if (b.NowPlayer()->counterCPossible) {
                                b.NowPlayer()->CurBlock->cclockw();
                            }
                            b.initialPossibilities();
                            b.updatePoss(b.NowPlayer());
                        }
                    }
                    if (cmd[1] == 'w') { // cw
                        if (num < 0) num = 1;
                        for(;num > 0;num--) {
                            if (b.NowPlayer()->clockPossible) {
                                b.NowPlayer()->CurBlock->clockw();
                            }
                            b.initialPossibilities();
                            b.updatePoss(b.NowPlayer());
                        }
                    }
                }
            }
            //d
            if (cmd[0] == 'd') {
                //down
                //drop
                if (cmd.length() > 1) {
                    if(cmd[1] == 'o'){//down
                        if (num < 0) num = 1;
                        for(;num > 0;num--) {
                            b.updatePoss(b.NowPlayer());
                            b.down(b.NowPlayer());
                            b.updatePoss(b.NowPlayer());
                        }
                    }
                    if (cmd[1] == 'r') {//drop
                        b.drop(b.NowPlayer());
                    }
                }
            }
        
            if (cmd[0] == 'l') {
        
                if (cmd.length() > 2) {
                    if(cmd[2] == 'f') {
                        if(num < 0) num = 1;
                            while(num != 0) {
                            b.left(b.NowPlayer());
                            b.updatePoss(b.NowPlayer());
                            b.LevelHeavy(b.NowPlayer());
                            b.BlockHeavy(b.NowPlayer());
                            num--;
                        }
                    }
                    if (cmd.length() > 5) {
                        if (cmd[5] == 'u') {
                            if(num < 0) num = 1;
                                while(num != 0){
                                b.LevelUp(b.NowPlayer());
                                num--;
                            }
                        }
                        if (cmd[5] == 'd') {
                            if(num < 0) num = 1;
                            while(num != 0) {
                                b.LevelDown(b.NowPlayer());
                                num--;
                            }
                        }
                    }
                }
            }
            //m
            //n
            if (cmd[0] == 'n') {
                //norandom + file
                //  if(cmd.length() > 8) break;
                if( cin >> norstring){
                    if((b.NowPlayer()->curLev == 0)||(b.NowPlayer()->curLev == 1)||(b.NowPlayer()->curLev == 2)){
                        cout << "only curLev 3 and curLev 4 can norandom!!" << endl;
                    } else {//yes now we do this
                        cout << "we will find" << norstring << " for testing!" <<endl;
                        b.NowPlayer()->levptr->aBS(norstring,b.NowPlayer()->id);
                    }
                }
            }
            //o
            //p
            //q
            //r
            if (cmd[0] == 'r') {
                //random
                //restart
                //right
                // if(cmd.length() > 7) break;
            
                if (cmd.length() > 1) {
                    if (cmd[1] == 'a') {
                        //random
                        if((b.NowPlayer()->curLev == 0)||(b.NowPlayer()->curLev == 1)||(b.NowPlayer()->curLev == 2)){
                            cout << "only curLev 3 and curLev 4 can random back!!" << endl;
                        } else {
                            b.NowPlayer()->levptr->BackRan(b.NowPlayer()->id);
                        }
                    }
                    if (cmd[1] == 'e') {
                        b.Restart(b.NowPlayer(), b.OtherPlayer());
                        b.NowPlayer()->CurBlock = b.NowPlayer()->levptr->Blockg(player1);
                        b.NowPlayer()->NextBlock = b.NowPlayer()->levptr->Blockg(player1);
                        b.OtherPlayer()->CurBlock = b.OtherPlayer()->levptr->Blockg(player2);
                        b.OtherPlayer()->NextBlock = b.OtherPlayer()->levptr->Blockg(player2);
                        cout << "we can restart" << endl;
                    }
                    if (cmd[1] == 'i') {
                        //right
                        if (num < 0) num = 1;
                        while(num != 0) {
                            b.right(b.NowPlayer());
                            b.updatePoss(b.NowPlayer());
                        
                            b.LevelHeavy(b.NowPlayer());
                            b.BlockHeavy(b.NowPlayer());
                            num--;
                        }
                    }
                }
            }
            //s
            if (cmd[0] == 's') {
                //sequence + file
                if (cmd[1] == 'e') {
                    if (cin >> seqstring) {
                        cout << "we sequence" << seqstring << " something" << endl;
                    }
                }
            }
            if(cmd == "I"){
                b.NowPlayer()->CurBlock = make_shared<IBlock>();
            }
            if(cmd == "J"){
                b.NowPlayer()->CurBlock = make_shared<JBlock>();
            }
            if(cmd == "L"){
                b.NowPlayer()->CurBlock = make_shared<LBlock>();
            }
            if(cmd == "O"){
                b.NowPlayer()->CurBlock = make_shared<OBlock>();
            }
            if(cmd == "S"){
                b.NowPlayer()->CurBlock = make_shared<SBlock>();
            }
            if(cmd == "Z"){
                b.NowPlayer()->CurBlock = make_shared<ZBlock>();
            }
            if (cmd == "T"){
                b.NowPlayer()->CurBlock = make_shared<TBlock>();
            }
        
        
            if (b.DrawBlock(b.NowPlayer(), b.NowPlayer()->row, b.NowPlayer()->col)) {
                b.NowPlayer()->NextBlock  = b.NowPlayer()->levptr->Blockg(b.NowPlayer());
                int clear_rows = b.ReCalc(b.NowPlayer());
                if (clear_rows >= 2) {
                    string cmd2;
                    cout << "Which Punishment you want to choose: blind || heavy || force";
                
                    cout << endl;
                    while (cin >> cmd2) {
                        if (cmd2 == "heavy") {
                            b.OtherPlayer()->heavy = true;
                            break;
                        } else if (cmd2 == "blind") {
                            b.Blind (b.OtherPlayer());
                            break;
                        } else if ( cmd2 == "force") {
                            cout << "which block? "<< endl;
                            char tempblock;
                            cin >> tempblock;
                            b.switchPlayer();//we switch player for now
                            shared_ptr<Block> bk = nullptr;
                            switch(tempblock) {
                                case 'J' : bk = make_shared<JBlock>(); break;
                                case 'O' : bk = make_shared<OBlock>(); break;
                                case 'L' : bk = make_shared<LBlock>(); break;
                                case 'I' : bk = make_shared<IBlock>(); break;
                                case 'S' : bk = make_shared<SBlock>(); break;
                                case 'Z' : bk = make_shared<ZBlock>(); break;
                                case 'T' : bk = make_shared<TBlock>(); break;
			                }
                            b.NowPlayer()->CurBlock = bk;
                            //  delete del;
                            b.switchPlayer();//and we switch back
                            break;
                            //end of force
                        } else {
                            continue;
                        }
                    }
                }
                b.switchPlayer();
            }
            //we set the punish
        if (b.NowPlayer()->starblk){  // * punishment
            if(b.NowPlayer()->notclear == 5){
                shared_ptr<Block> startemp = b.NowPlayer()->CurBlock;
                b.NowPlayer()->CurBlock = make_shared<starBlock>();
                
                b.right(b.NowPlayer());
                b.right(b.NowPlayer());
                
                b.drop(b.NowPlayer());
                
                b.updatePoss(b.NowPlayer());
                
                b.ReCalc(b.NowPlayer());
                b.DrawBlock(b.NowPlayer(), b.NowPlayer()->row, b.NowPlayer()->col);
                b.createBoard(player1, player2, &board);
                
                
                b.NowPlayer()->CurBlock = startemp;//
                b.NowPlayer()->notclear = 0;//we reset
            }
        }//end of *

            b.ReCalc(b.NowPlayer());
            b.DrawBlock(b.NowPlayer(), b.NowPlayer()->row, b.NowPlayer()->col);
            b.createBoard(player1, player2, &board);
            seqList.pop_back();
        } //end of commands 
    }//end of the real command loop
}

