#include <iostream>
#include <ctime>

using namespace std;

// Prototypes

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running) {
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if(checkTie(spaces)) {
            return false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if(checkTie(spaces)) {
            return false;
            break;
        }
    }
    
    cout << "THANKS FOR PLAYING!";

    return 0;
}

// Functions

void drawBoard(char *spaces) {
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}
void playerMove(char *spaces, char player) {
    int number;

    do{
        cout << "It's your turn. (Enter 1-9): ";
        cin >> number;
        number--;

        if(spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while(!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer) {
    int number;

    // Generate a random number
    srand(time(0));

    while(true) {
        // Set number to be between 0-8
        number = rand() % 9;
        
        if(spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer) {
    
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {            // Check rows
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";                     
    } else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {     
        spaces[3] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";                     
    } else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {     
        spaces[6] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";                     
    } else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {     // Check columns
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";                     
    } else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {     
        spaces[1] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";                     
    } else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {     
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";                     
    } else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {     // Check Diagonals
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";                     
    } else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n"; 
    } else {
        return false;
    }
    return 0;
}
bool checkTie(char *spaces) {

    for(int i = 0; i < 9; i++) {
        if(spaces[i] == ' ') {
            return false;
        }
    }

    cout << "IT'S A TIE!\n";
    return true;
}