#include <iostream>
#include <string>
using namespace std;

/* Function to swap */
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int main() {
    string input, action;
    cin >> input >> action; /* User input */

    char board[4][4];
    int blank_x = 0, blank_y = 0; /* Position of blank (#) */

    for (int i = 0; i < 16; i++) {  /* Fill the board */
        board[i / 4][i % 4] = input[i];
        if (input[i] == '#') {      /* Store position of # */
            blank_x = i / 4;
            blank_y = i % 4;
        }
    }

    /* Perform the action */
    if (action == "UP" && blank_x > 0) {
        swap(board[blank_x][blank_y], board[blank_x - 1][blank_y]);
    } else if (action == "DOWN" && blank_x < 3) {
        swap(board[blank_x][blank_y], board[blank_x + 1][blank_y]);
    } else if (action == "LEFT" && blank_y > 0) {
        swap(board[blank_x][blank_y], board[blank_x][blank_y - 1]);
    } else if (action == "RIGHT" && blank_y < 3) {
        swap(board[blank_x][blank_y], board[blank_x][blank_y + 1]);
    }

    /* Print the board */
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
