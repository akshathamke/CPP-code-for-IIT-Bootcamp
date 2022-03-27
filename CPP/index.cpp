#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int win[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

bool iswin(char *board, char c){
    for(int i=0; i<8; i++){
       if(board[win[i][0]]==c and board[win[i][1]]==c and board[win[i][2]]==c){
           return true;
       }
    }
    return false;
}

bool isvalid(char board[9]){
    int xcount=0, ocount=0;
    for(int i=0; i<9; i++){
        if(board[i]=='X'){xcount++;}
        if(board[i]=='O'){ocount++;}
    }
    if(xcount==ocount || xcount==ocount+1){
        if(iswin(board, 'O')){
            if(iswin(board, 'X')){
                return false;
            }
            return (xcount==ocount);
        }
        if(iswin(board, 'X') and xcount!=ocount+1){
            return false;
        }
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    char board[9];
    for(int i=0; i<9; i++){
        cin>>board[i];
    }
    (isvalid(board))?cout<<"YES":cout<<"NO";
    
    return 0;
}