#include "BiqBoard.h"
#include "Player.h"
#include <iostream>
#include <string>

extern bool specialOn;


using namespace std;

BiqBoard::BiqBoard () {
    pler1 = shared_ptr <Player> (new Player);
    pler2 = shared_ptr <Player> (new Player);
}

BiqBoard::~BiqBoard(){
}


void BiqBoard::SetPler(shared_ptr <Player> &pler, string playername,int id,int curLev) {
    
    pler->Field.resize(15);
    for (int row = 0; row < 15; row++) {
        pler->Field[row].resize(11);
        for (int col = 0; col < 11; col++) {
            pler->Field[row][col] = Cell();
        }
    }
    //for curLev
    if (curLev == 0) {
        pler->levptr = unique_ptr <Level> (new Level0);
    } 
    if (curLev == 1) {
        pler->levptr = unique_ptr <Level> (new Level1);
    }
    if (curLev == 2) {
        pler->levptr= unique_ptr <Level> (new Level2);
    }
    if (curLev == 3) {
        pler->levptr= unique_ptr <Level> (new Level3);
    }
    if (curLev == 4) {
        pler->levptr= unique_ptr <Level> (new Level4);
    } 
    
    
    pler->id = id;

    pler->RPoss = true;
    pler->DPoss = true;
    pler->LPoss = true;
    pler->heavy = false; 
    pler->Active = true;
    pler->clockPossible = true;
    pler->counterCPossible = true;

    pler->CurBlock = nullptr;
    pler->NextBlock = nullptr;

    pler->name = playername;
    pler->curLev = curLev;

    pler->col = 0;
    pler->row = 0;
    pler-> Sco= 0;
    pler->SpeAttack = 0; 
    pler->downImposs = 0;

    pler->IScore = 0;
    pler->JScore = 0;
    pler->LScore = 0;
    pler->OScore = 0;
    pler->SScore = 0;
    pler->TScore = 0;
    pler->ZScore = 0;
}



// get score

string NumToString(int num) {
    string s = "";
    if(num == 0) {
        s = "0";
    } else {
        while(num != 0){
            int con = num % 10;
            switch (con){
                case 1: s = s + "1"; break;
                case 2: s = s + "2"; break;
                case 3: s = s + "3"; break;
                case 4: s = s + "4"; break;
                case 5: s = s + "5"; break;
                case 6: s = s + "6"; break;
                case 7: s = s + "7"; break;
                case 8: s = s + "8"; break;
                case 9: s = s + "9"; break;
                case 0: s = s + "0"; break;
            }
            num = num / 10;
        }
    }
    return s;
}

int BiqBoard::gCS(shared_ptr <Player>& pler) {
    return pler->Sco;
}


//get player
shared_ptr <Player>& BiqBoard::Getpler2() {
    return pler2;
}

shared_ptr <Player>& BiqBoard::Getpler1() {
    return pler1;
    
}
// Making the board
void BiqBoard::createBoard(shared_ptr <Player>& pler1, shared_ptr <Player>& pler2, Xwindow * board) {
    int temp_col = 0;
    cout << " Level:    " << pler1->curLev << "    " << " Level:    " << pler2->curLev << endl;
    cout << " Score    " << pler1->Sco << "    " << " Score:    " << pler2->Sco << endl;
    if (!Textmode){
        board->fillRectangle(0, 0, 600, 30, 5);
        board->drawString(5, 25, "Level:");
        string levelStr1 = NumToString(pler1->curLev);
        board->drawString(55, 25, levelStr1);
        
        board->drawString(100, 25, "Score:");
        string scoreStr1 = NumToString(pler1->Sco);
        board->drawString(150, 25, scoreStr1);
        
        board->drawString(330, 25, "Level:");
        string levelStr2 = NumToString(pler2->curLev);
        board->drawString(380, 25, levelStr2);
        
        board->drawString(425, 25, "Score:");
        string scoreStr2 = NumToString(pler2->Sco);
        board->drawString(475, 25, scoreStr2);
    }
    
    cout << "-----------     -----------" << endl;
    if (!Textmode){
        board->drawLine(0, 50, 265, 50);
        board->drawLine(350, 50, 600, 50);
    }
    for (int row = 0; row < 15; row++) {
        
        for (int col1 = 0; col1 < 11; col1++) {
            cout << pler1->Field[row][col1];
            if (!Textmode){
                pler1->Field[row][col1].draw(col1, row+2, board);
                temp_col = col1;
            }
            
        }
        cout << "     ";
        for (int col2 = 0; col2 < 11; col2++) {
            cout << pler2->Field[row][col2];
            if (!Textmode){
                pler2->Field[row][col2].draw(col2+temp_col+3, row+2, board);
            }
        }
        cout << endl;
        
        if ((row+1) == 15){
            cout << "-----------     -----------" << endl;
            cout << " Next:           Next:     " << endl;
            if (!Textmode){
                board->drawString(5, 440, "Next:");
                board->drawString(330, 440, "Next:");
            }
        }
        
    }
    if (!Textmode) {
        for (int i = 18; i < 30; ++i) {
            for (int j = 0; j < 24; ++j) {
                board->fillRectangle(j*25, i*25, 25, 25, 1);
            }
        }
    }
    DrawNextBlock(pler1, pler2, board);
}




bool BiqBoard::DrawBlock(shared_ptr <Player>& pler, int x, int y) {
    int b_row = 5;
    int b_col = 4;
    int board_row = 15;
    int bc = 11;
    bool ava = availableCells(pler, x, y);
    vector <vector <string>> v = pler->CurBlock->getBlock();
    
    
    for (int row = 0; row < b_row; ++ row) {
        for (int col = 0; col < b_col; ++ col) {
            int new_row = row + x;
            int new_col = col + y;
            string color = v[row][col];
            if ((new_col >= bc)||(new_row >= board_row)||(color == " ")) {
                continue;
            }
            else {
                if (pler->downImposs == 1) {
                    pler->Field[new_row][new_col].Deactivate(color);
                    continue;
                }
                if (ava){
                    pler->Field[new_row][new_col].Activate(color);
                }
            }
        }
    }

    if (pler->downImposs == 1) {
        pler->downImposs = 0;
        pler->col = 0;
        pler->row = 0;
        pler->CurBlock = pler->NextBlock;
        pler->RPoss = true;
        pler->LPoss = true;
        pler->DPoss = true;
        pler->clockPossible = true;
        pler->counterCPossible = true;
        return true;
    }
    return false;
}



void BiqBoard::DrawNextBlock(shared_ptr <Player>& pler1, shared_ptr <Player>& pler2, Xwindow * board){
    shared_ptr<Block> p1 = pler1->NextBlock;
    shared_ptr<Block> p2 = pler2->NextBlock;
    vector<vector<string>> b1 = p1->getBlock();
    vector<vector<string>> b2 = p2->getBlock();
    
    for (int i = 2; i < 5; ++i){
        for (int j = 0; j < 4; ++j){
            cout << b1[i][j];
            if (!Textmode){
                if (b1[i][j] != " ") {
                    if (b1[i][j] == "I") {
                        board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 7);
                    } else if (b1[i][j] == "J"){
                        board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 9);
                    } else if (b1[i][j] == "L"){
                        board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 0);
                    } else if (b1[i][j] == "Z"){
                        board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 6);
                    } else if (b1[i][j] == "S"){
                        board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 3);
                    } else if (b1[i][j] == "O"){
                        board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 4);
                    } else if (b1[i][j] == "T"){
                        board->fillRectangle((3+j)*25, (16+i)*25, 25, 25, 8);
                    }
                }
            }
        }
        cout << "            ";
        for (int j = 0; j < 4; ++j){
            cout << b2[i][j];
            if (!Textmode){
                if (b2[i][j] != " "){
                    if (b2[i][j] == "I") {
                        board->fillRectangle(25*(j+16), 25*(i+16), 25, 25, 7);
                    } else if (b2[i][j] == "J"){
                        board->fillRectangle(25*(j+16), 25*(i+16), 25, 25, 9);
                    } else if (b2[i][j] == "L"){
                        board->fillRectangle(25*(j+16), 25*(i+16), 25, 25, 0);
                    } else if (b2[i][j] == "Z"){
                        board->fillRectangle(25*(j+16), 25*(i+16), 25, 25, 6);
                    } else if (b2[i][j] == "S"){
                        board->fillRectangle(25*(j+16), 25*(i+16), 25, 25, 3);
                    } else if (b2[i][j] == "O"){
                        board->fillRectangle(25*(j+16), 25*(i+16), 25, 25, 4);
                    } else if (b2[i][j] == "T"){
                        board->fillRectangle(25*(j+16), 25*(i+16), 25, 25, 8);
                    }
                }
            }
        }
        cout << endl;
    }
}



// helper function of DrawBlock
bool BiqBoard::availableCells(shared_ptr <Player>& pler, int x, int y) {
    int b_row = 5;
    int b_col = 4;
    int board_row = 15;
    int bc = 11;
    vector <vector <string>> v = pler->CurBlock->getBlock();
    for (int row = 0; row < b_row; ++ row) {
        for (int col = 0; col < b_col; ++ col) {
            int new_row = row + x;
            int new_col = col + y;
            string color = v[row][col];
            if ((new_col >= bc)||(new_row >= board_row)||(color == " ")) {
                continue;
            }
            else if (pler->Field[new_row][new_col].GetColor() != " "){
                return false;
                break;
            }
        }
    }
    return true;
}





// switching

shared_ptr <Player>& BiqBoard::NowPlayer() {
    if (turn){
        return pler1;
    }else{
        return pler2;
    }
}

shared_ptr <Player>& BiqBoard::OtherPlayer() {
    if (turn){
        return pler2;
    }else{
        return pler1;
    }
}



void BiqBoard::switchPlayer() {
    turn = !turn;
}





// command left
void BiqBoard::left(shared_ptr <Player>& pler){
    int pc = pler->col;
    if ((pc > 0)&&(pler->LPoss)){
        
        pler->RPoss = true;
        pler->DPoss = true;
        pler->col -= 1;
    }
    else {
        pler->DPoss = true;
        pler->LPoss = true;
        pler->RPoss = true;
    }
    pler->clockPossible = true;
    pler->counterCPossible = true;
}


// command right
void BiqBoard::right(shared_ptr <Player>& pler){
    int pc = pler->col;
    int rc = 0;
    int bc = 11;
    for (int row = 0; row < 5; ++ row) {
        for (int col = 0; col < 4; ++col) {
            vector <vector <string>> v = pler->CurBlock->getBlock();
            if ((v[row][col] != " ")&&(col > rc)) {
                rc = col;
            }
        }
    }
    
    
    if ((pc + rc + 2 <= bc) && (pler->RPoss)) {
        
        pler->col += 1;
        pler->LPoss = true;
        pler->DPoss = true;
        
    }
    else if (!pler->RPoss) {
        pler->RPoss = true;
        pler->LPoss = true;
        pler->DPoss = true;
    }
    pler->clockPossible = true;
    pler->counterCPossible = true;
}


// command down
void BiqBoard::down(shared_ptr <Player>& pler){
    int player_row = pler->row;
    if (!pler->DPoss) {
        ++pler->notclear;//
        //  cout << "can't down" << endl;
        pler->downImposs += 1;
        for (int i = 0; i < 15; ++i){
            for (int j = 0; j < 11; ++j){
                pler->Field[i][j].NotBlind();
            }
        }
    }
    
    if ((player_row < 15)&&(pler->DPoss)){
        pler->row += 1;
        pler->RPoss = true;
        pler->LPoss = true;
    } else {
        pler->RPoss = true;
        pler->LPoss = true;
        pler->DPoss = true;
    }
    pler->clockPossible = true;
    pler->counterCPossible = true;
    
}


//drop
void BiqBoard::drop(shared_ptr <Player>& pler) {
    while (pler->downImposs == 0) {
        updatePoss(pler);
        down(pler);
        updatePoss(pler);
    }
}


//clockpossible
void BiqBoard::clockPossible(shared_ptr <Player>& pler){
    int x = pler->row;
    int y = pler->col;
    int b_row = 5;
    int b_col = 4;
    int board_row = 15;
    int bc = 11;
    shared_ptr<Block>copy = pler->CurBlock->blockCpy();
    copy->clockw();
    string BlkType = copy->Type();
    
    for (int row = 0; row < b_row; ++ row) {
        for (int col = 0; col < b_col; ++ col) {
            
            int new_row = row + x;
            int new_col = col + y;
            if ((new_col >= 11) && (BlkType == "I")){
                pler->clockPossible = false;
                break;
            }
            if ((new_col > 11) && (BlkType != "I")){
                pler->clockPossible = false;
                break;
            }
            vector <vector <string>> v_copy = copy->getBlock();
            string cwcolor = v_copy[row][col];
            if ((new_col >= bc)||(new_row >= board_row)||(cwcolor == " ")) {
                continue;
            }

            if (pler->Field[new_row][new_col].GetColor() != " "){
                pler->clockPossible = false;
                break;
            }
        }
    }
}


// command ccwpossible
void BiqBoard::counterCPossible(shared_ptr <Player>& pler){
    int x = pler->row;
    int y = pler->col;
    int b_row = 5;
    int b_col = 4;
    int board_row = 15;
    int bc = 11;
    shared_ptr<Block>copy = pler->CurBlock->blockCpy();
    copy->cclockw();
    string BlkType = copy->Type();
    
    for (int row = 0; row < b_row; ++ row) {
        for (int col = 0; col < b_col; ++ col) {
            
            int new_row = row + x;
            int new_col = col + y;
            if ((new_col >= 11) && (BlkType == "I")){
                pler->counterCPossible = false;
                break;
            }
            if ((new_col > 11) && (BlkType != "I")){
                pler->counterCPossible = false;
                break;
            }
            
            vector <vector <string>> v_copy = copy->getBlock();
            string cwcolor = v_copy[row][col];
            
            if ((new_col >= bc)||(new_row >= board_row)||(cwcolor == " ")) {
                continue;
            }
            
            
            
            if (pler->Field[new_row][new_col].GetColor() != " "){
                pler->counterCPossible = false;
                break;
            }
        }
    }
}



// update possibilities
void BiqBoard::initialPossibilities () {
    pler1->DPoss = true;
    pler1->LPoss = true;
    pler1->RPoss = true;
    pler2->DPoss = true;
    pler2->LPoss = true;
    pler2->RPoss = true;
}



// update all possible
void BiqBoard::updatePoss(shared_ptr <Player>& pler){
    int x = pler->row;
    int y = pler->col;
    int b_row = 5;
    int b_col = 4;
    int board_row = 15;
    int bc = 11;
    int check_row = 0;
    vector <vector <string>> v = pler->CurBlock->getBlock();
    
    for (int row = 0; row < b_row; ++ row) {
        check_row = 0;
        for (int col = 0; col < b_col; ++ col) {
            int new_row = row + x;
            int new_col = col + y;
            string color = v[row][col];
            if ((new_col >= bc)||(new_row >= board_row)||(color == " ")) {
                continue;
            } else {
                if ((new_col+1 > 10)||(pler->Field[new_row][new_col+1].GetColor() != " ")){
                    pler->RPoss = false;
                }
                if (check_row == 0) {
                    check_row += 1;
                    if ((new_col -1 < 0)|| (pler->Field[new_row][new_col-1].GetColor() != " ")){
                        pler->LPoss = false;
                    }
                }
                if ((new_row+1 >= 15) || (pler->Field[new_row+1][new_col].GetColor() != " ")){
                    pler->DPoss = false;
                }                
            }
        }
    }
    clockPossible(pler);
    counterCPossible(pler);
}

// checking if lines are complete
int BiqBoard::ReCalc(shared_ptr <Player>& pler) {
    vector < int > clean_row;
    for (int row = 14; row > 0 ; row-- ) {
        int num_dead_cell = 0;
        for (int col = 0; col < 11; ++col) {
            if (pler->Field[row][col].GetColor() == " ") {
                continue;
            }
            else if ((!(pler->Field[row][col].GetColor() == " "))&&(!pler->Field[row][col].isActive())) {
                num_dead_cell += 1;
            }
            if (num_dead_cell == 11) {
                clean_row.push_back(row);
            }
        }
    }
    // score
    int a = clean_row.size();
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < 11; ++j) {
            string color = pler->Field[clean_row[i]][j].GetColor();
            if (color == "I") {
                pler->IScore += 1;
            } else if (color == "J") {
                pler->JScore += 1;
            } else if (color == "L") {
                pler->LScore += 1;
            } else if (color == "O") {
                pler->OScore += 1;
            } else if (color == "S") {
                pler->SScore += 1;
            } else if (color == "T") {
                pler->TScore += 1;
            } else if (color == "Z") {
                pler->ZScore += 1;
            }
        }
    }
    if (clean_row.size() != 0) {
        destroyLine(pler, clean_row);
    }
    return a;
}


// adding score and destroying lines
void BiqBoard::destroyLine(shared_ptr <Player>& pler,  vector< int > & clean_row){
    vector < vector < Cell> > new_Field;
    int num_clean_row = clean_row.size();
    int x = 0;
    new_Field.resize(15);
    
    for (int row = 0; row < num_clean_row; row++) {
        new_Field[row].resize(11);
        for (int col = 0; col < 11; col++) {
            new_Field[row][col] = Cell();
            
        }
    }
    
    
    for (int row = 0; row < 15; row++) {
        if (row + x >= 15) {
            break;
        }
        
        if (clean_row.back() == row ) {
            clean_row.pop_back();
            x += 1;
            continue;
        } else {
            new_Field[row + num_clean_row - x].resize(11);
            
            
            for (int col = 0; col < 11; col++) {
                new_Field[row + num_clean_row - x][col] = pler->Field[row][col];
            }
        }
    }
    
    
    
    int add_score = (num_clean_row + pler->curLev)*(num_clean_row + pler->curLev);
    //cout << add_score << endl;
    
    if ((pler->IScore != 0)&&(pler->IScore % 4 == 0)) {
        add_score += 1;
    }
    if ((pler->JScore != 0)&&(pler->JScore % 4 == 0)) {
        add_score += 1;
    }
    if ((pler->LScore != 0)&&(pler->LScore % 4 == 0)) {
        add_score += 1;
    }
    if ((pler->OScore != 0)&&(pler->OScore % 4 == 0)) {
        add_score += 1;
    }
    if ((pler->SScore != 0)&&(pler->SScore % 4 == 0)) {
        add_score += 1;
    }
    if ((pler->TScore != 0)&&(pler->TScore % 4 == 0)) {
        add_score += 1;
    }
    
    cout << add_score << endl;
    pler->IScore = 0;
    pler->JScore = 0;
    pler->LScore = 0;
    pler->OScore = 0;
    pler->SScore = 0;
    pler->TScore = 0;
    
    pler->Field = new_Field;
    pler->Sco += add_score;
}

// leveling up and down
void BiqBoard::LevelUp(shared_ptr <Player>& pler){
    int le = pler->curLev + 1;
    if (le == 1) {
        pler->levptr= unique_ptr <Level> (new Level1);
        pler->curLev = 1;
        pler->starblk = false;
    } else if (le == 2) {
        pler->levptr= unique_ptr <Level> (new Level2);
        pler->curLev = 2;
        pler->starblk = false;
    } else if (le == 3) {
        pler->levptr= unique_ptr <Level> (new Level3);
        pler->curLev = 3;
        pler->starblk = false;
    } else if (le == 4) {
        pler->levptr= unique_ptr <Level> (new Level4);
        pler->curLev = 4;
        pler->starblk = true;
    }
}

void BiqBoard::LevelDown(shared_ptr <Player>& pler) {
    int le = pler->curLev - 1;
    if (le == 1) {
        pler->levptr= unique_ptr <Level> (new Level1);
        pler->curLev = 1;
        pler->starblk = false;
    } else if (le == 2) {
        pler->levptr= unique_ptr <Level> (new Level2);
        pler->curLev = 2;
        pler->starblk = false;  
    } else if (le == 3) {
        pler->levptr= unique_ptr <Level> (new Level3);
        pler->curLev = 3;
        pler->starblk = false;
    }  else if (le == 4) {
        pler->levptr= unique_ptr <Level> (new Level4);
        pler->curLev = 4;
        pler->starblk = true;
    } else if (le == 0) {
        pler->levptr= unique_ptr <Level> (new Level0);
        pler->curLev = 0;
        pler->starblk = false;
    }
}

void BiqBoard::deadCell(shared_ptr <Player>& pler) {
    for (int row = 0; row < 15; ++row){
        for (int col = 0; col < 11; ++col){
            Cell cur = pler->Field[row][col];
            if (cur.isActive()){
                pler->Field[row][col].Deactivate(" ");
            }
        }
    }
}

// Heavy
void BiqBoard::LevelHeavy(shared_ptr <Player>& pler) {
    if ((pler->downImposs == 0)&&(pler->curLev >= 3)) {
        updatePoss(pler);
        down(pler);
        updatePoss(pler);
    }
}

void BiqBoard::BlockHeavy(shared_ptr <Player>& pler) {
    for (int i = 0; i < 2; ++i) {
        if ((pler->downImposs == 0)&&(pler->heavy)) {
            updatePoss(pler);
            down(pler);
            updatePoss(pler);
        }
    }
}


// when someone loses
bool BiqBoard::GameOver(shared_ptr <Player>& pler) {
    string check0 = pler->Field[3][0].GetColor(); 
    string check1 = pler->Field[3][1].GetColor();
    string check2 = pler->Field[3][2].GetColor();
    string check3 = pler->Field[3][3].GetColor();
    string checkone0 = pler->Field[4][0].GetColor();
    string checkone1 = pler->Field[4][1].GetColor();
    string checkone2 = pler->Field[4][2].GetColor();
    string checkone3 = pler->Field[4][3].GetColor();
    bool check0bool = pler->Field[3][0].isActive();
    bool check1bool = pler->Field[3][1].isActive();
    bool check2bool = pler->Field[3][2].isActive();
    bool check3bool = pler->Field[3][3].isActive();
    bool checkone0bool = pler->Field[4][0].isActive();
    bool checkone1bool = pler->Field[4][1].isActive();
    bool checkone2bool = pler->Field[4][2].isActive();
    
    
   if ((pler->NextBlock->Type() == "I")&&
        (((check0 != " ") && (!check0bool)) || ((check1 != " ") && (!check1bool)) || ((check2 != " ") && (!check2bool)) || ((check3 != " ") && (!check3bool)))) {
        return false;
    }
    if ((pler->NextBlock->Type() == "O")&&
        (((check0 != " ") && (!check0bool))||((check1 != " ") && (!check1bool))||((checkone0 != " ") && (!checkone0bool))||((checkone1 != " ") && (!checkone1bool)))) {
        return false;
    }
    if ((pler->NextBlock->Type() == "T")&&(((check1 != " ") && (!check1bool)) || ((checkone0 != " ") && (!checkone0bool)) || ((checkone1 != " ") && (!checkone1bool)) || ((checkone2 != " ") && (!checkone2bool)))) {
        return false;
    }
    if ((pler->NextBlock->Type() == "L")&&(((check3 != " ") && (!check3bool))||((checkone0 != " ") && (!checkone0bool))||((checkone1 != " ") && (!checkone1bool))||((checkone2 != " ") && (!checkone2bool)))) {
        return false;
    }
    if ((pler->NextBlock->Type() == "J")&&(((check0 != " ") && (!check0bool))||((checkone0 != " ") && (!checkone0bool))||((checkone1 != " ") && (!checkone1bool))||((checkone2 != " ") && (!checkone2bool)))) {
        return false;
    }
    if ((pler->NextBlock->Type() == "Z") &&(((check0 != " ") && (!check0bool))||((check1 != " ") && (!check1bool))||((checkone1 != " ") && (!checkone1bool))||((checkone2 != " ") && (!checkone2bool)))) {
        return false;
    }
    if ((pler->NextBlock->Type() == "S") &&(((check1 != " ") && (!check1bool))||((check2 != " ") && (!check2bool))||((checkone0 != " ") && (!checkone0bool))||((checkone1 != " ") && (!checkone1bool)))) {
        return false;
    }
    return true;
}

//To restart the game
void BiqBoard::Restart(shared_ptr <Player>& pler1, shared_ptr <Player>& pler2) {
    SetPler(pler1, "Murtaza" , 1, 0);
    SetPler(pler2, "Qianli" , 2, 0);
}


// blind
void BiqBoard::Blind(shared_ptr <Player>& pler) {
    for (int i = 2; i < 12; ++i) {
        for (int j = 2; j < 9; ++j) {
            pler->Field[i][j].TurnBlind();
        }
    }
}
