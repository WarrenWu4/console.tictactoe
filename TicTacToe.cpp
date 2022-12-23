#include <bits/stdc++.h>
using namespace std;
bool gameOver;
string board[9] = {"1", "2", "3" , "4", "5", "6", "7", "8", "9"};
int turn=2;

void Draw() {
    //if it's a draw
    bool draw = true;
    for(int i=0;i<sizeof(board)/sizeof(int);i++) {
        if(board[i] != "X" || board[i] != "O") {
            draw = false;
            break;
        }
    }
    if(draw) {
        cout << "Draw";
        this_thread::sleep_for(chrono::milliseconds(5000));
        gameOver=true;
    }
}

void Winner() {
    for(int i=0;i<sizeof(board)/sizeof(int);i++) {
        //row
        if(i==2 || i==5 || i==8) {
            if(board[i] == board[i-1] && board[i] == board[i-2]) {cout << "Winner is: " << board[i]; this_thread::sleep_for(chrono::milliseconds(5000)); gameOver=true;}
        }
        //column
        if(i==6 || i == 7 || i == 8) {
            if(board[i] == board[i-3] && board[i] == board[i-6]) {cout << "Winner is: " << board[i]; this_thread::sleep_for(chrono::milliseconds(5000)); gameOver=true;}
        }
        //diagnol1
        if(i == 0) {
            if(board[i] == board[i+4] && board[i] == board[i+8]) {cout << "Winner is: " << board[i]; this_thread::sleep_for(chrono::milliseconds(5000)); gameOver=true;}
        }
        //diagnol2
        if(i == 2) {
            if(board[i] == board[i+2] && board[i] == board[i+4]) {cout << "Winner is: " << board[i]; this_thread::sleep_for(chrono::milliseconds(5000)); gameOver=true;}
        }
    }
}

void Display() {
    cout << "\n";
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "__________\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "__________\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

void Input() {
    int move;
    cin >> move;
    switch(move) {
        case 1:
            if(turn%2==0) {board[0] = "X";turn++;}
            else {board[0] = "O";turn++;}
            break;
        case 2:
            if(turn%2==0) {board[1] = "X";turn++;}
            else {board[1] = "O";turn++;}
            break;
        case 3:
            if(turn%2==0) {board[2] = "X";turn++;}
            else {board[2] = "O";turn++;}
            break;
        case 4:
            if(turn%2==0) {board[3] = "X";turn++;}
            else {board[3] = "O";turn++;}
            break;
        case 5:
            if(turn%2==0) {board[4] = "X";turn++;}
            else {board[4] = "O";turn++;}
            break;
        case 6:
            if(turn%2==0) {board[5] = "X";turn++;}
            else {board[5] = "O";turn++;}
            break;
        case 7:
            if(turn%2==0) {board[6] = "X";turn++;}
            else {board[6] = "O";turn++;}
            break;
        case 8:
            if(turn%2==0) {board[7] = "X";turn++;}
            else {board[7] = "O";turn++;}
            break;
        case 9: 
            if(turn%2==0) {board[8] = "X";turn++;}
            else {board[8] = "O";turn++;}
            break;
    }
}

int main() {
    gameOver = false;
    while(!gameOver) {
        Display();
        cout << "X starts first\n" << "Enter position number: ";
        Input();
        Winner();
        Draw();
    }
}