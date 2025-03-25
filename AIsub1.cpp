#include <iostream>
#include <string>
using namespace std;

int main(){
/*variable declaration for taking user input*/
    string input;
    cin>> input;

/* variable declaration of the matrix/board*/
    char board[4][4];

/*iterate the input and fill the board*/
    for (int i=0; i<16; i++){
        board[i/4][i%4]=input[i];
    }






















    
/*Print the board*/
    for (int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<< board[i][j]<< " " ;
        }
    if (i!=4){
        cout<< endl;
    }    
    
}
    return 0;
}