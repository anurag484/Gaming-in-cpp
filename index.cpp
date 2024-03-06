#include<iostream>
#include "tictactoe.cpp"
#include"sudoku.cpp"
#include"easysudoku.cpp"
#include "number.cpp"
#include "quiz.cpp"
using namespace std;


int main(){
    do{
    
    
    cout<<"."<<endl;
    cout<<endl<<endl<<endl<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"*************!!!!!!!!!welcome to the gaming world!!!!!!!!!!!!********************"<<endl<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"             1. Tic Tac Toe"<<endl<<endl;
    cout<<"             2. sudoku"<<endl<<endl;
    cout<<"             3.casino number guessing"<<endl<<endl;
    cout<<"             4.quiz"<<endl;
    cout<<"             0.exit"<<endl;
    cout<<"----------------------------------------------------------------------------------"<<endl;
    cout<<"enter your choice"<<endl;
    int n;
    cin>>n;

    switch (n)
    {
    case 1:
        int mode;
        cout<<"              1. Computer vs Player"<<endl<<endl;
        cout<<"              2.Player vs Player"<<endl<<endl;

        cout<<"Select Mode of the game"<<endl;
        cin>>mode;

        switch(mode){
            case 1:
            computerVSplayer();
            break;

            case 2:
            playerVSplayer();
            break;
        
            default :
            cout<<"Please select valid Game Mode"<<endl;
            break;
        }
        break;
    case 2:
        cout<<"1.easy"<<endl;
        cout<<"2.hard"<<endl;
        cout<<"enter your choice"<<endl;
        int m;
        cin>>m;
        switch (m){
            case 1:
                
            break;
        
        case 2:
            cout<<"enter 1 to start"<<endl;
            int b;
            cin>>b;
            if(b==1){
                vector<vector<int>>sudo=generateSudoku();
                printSudoku(sudo);
                cout<<"1.view solution"<<endl;
                int a;
                cin>>a;
                if(a==1){
                    viewsol(sudo);
                }
            }
            
            break;
        default:
            cout<<"Please select valid Game Mode"<<endl;
            break;
        }
        break;

    
    case 3:
        guess();
        break;
    case 4:
        quiz();
        break;

    case 0:
            exit(0);
            break;
    default:

        cout<<"enter valid choice"<<endl;
        break;
    }
    }
    while(1);
}