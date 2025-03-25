#include<iostream>
#include<string>
using namespace std;

/*function to find position of # on the board*/
void findAvailableActions(const string &board){
    int pos= board.find('#');

/*dimension of matrix*/
    const int ROWS=4;
    const int COLUMNS=4;

/*row and columns for blank space*/
    int row= pos/ COLUMNS;
    int col= pos % COLUMNS;

/*what actions can be taken according to position of #*/
    if(row>0) cout<<"UP"<<endl;
    if(row<ROWS-1) cout<<"DOWN"<<endl;
    if(col>0) cout<<"LEFT"<<endl;
    if(col<COLUMNS-1) cout<<"RIGHT"<<endl;
}

int main(){
    string board;
    cin>>board;
    findAvailableActions(board);
    return 0;
}