#include<iostream>
#include<ctime>
#include<random>
using namespace std;

char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

void show_board(){

    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[0]<<"   |   "<< board[1]<<"   |   "<< board[2]<<endl;

    cout<<"------- -------- -------"<<endl;

    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[3]<<"   |   "<< board[4]<<"   |   "<< board[5]<<endl;

    cout<<"------- -------- -------"<<endl;

    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[6]<<"   |   "<< board[7]<<"   |   "<< board[8]<<endl;


}

void getXplayer_choice(){
    while(true){
        cout<<"Select Your Position (1-9) : ";
        int choice;
        cin>>choice;
        choice--;

        if(choice<0 || choice>8){
            cout<<"Please Select Your Choice From 1-9"<<endl;
        }
        else if(board[choice]!=' '){
            cout<<"Please select an empty position"<<endl;
        }
        else{
            board[choice]='X';
            break;
        }
    }
}
void getOplayer_choice(){
    while(true){
        cout<<"Select Your Position (1-9) : ";
        int choice;
        cin>>choice;
        choice--;

        if(choice<0 || choice>8){
            cout<<"Please Select Your Choice From 1-9"<<endl;
        }
        else if(board[choice]!=' '){
            cout<<"Please select an empty position"<<endl;
        }
        else{
            board[choice]='O';
            break;
        }
    }
}
void get_computer_choice(){
    srand(time(0));
    int choice;
    do{
        choice = rand()%10;
    }while(board[choice] != ' ');

    board[choice]='O';

    
}

int count_board(char symbol){
    int total =0;
    for(int i=0;i<9;i++){
        if(board[i]==symbol){
            total+=1;
        }
    }
    return total;
}

char check_winner(){
    //winner in row
    if(board[0] == board[1] && board[1] == board[2]  && board[0]!=' '){
        return board[0];
    }
    if(board[3] == board[4] && board[4] == board[5]  && board[3]!=' '){
        return board[3];
    }
    if(board[6] == board[7] && board[7] == board[8]  && board[6]!=' '){
        return board[6];
    }
    //winner in col
    if(board[0]==board[3] && board[3]==board[6] && board[0]!=' '){
        return board[0];
    }
    if(board[1]==board[4] && board[4]==board[7] && board[1]!=' '){
        return board[1];
    }
    if(board[2]==board[5] && board[5]==board[8] && board[2]!=' '){
        return board[2];
    }

    //winner in diagonal
    if(board[0]==board[4] && board[4]==board[8] && board[0]!= ' '){
        return board[0];
    }
    if(board[2]==board[4] && board[4]==board[6] && board[2]!= ' '){
        return board[0];
    }

    if(count_board('X')+count_board('O')<9){
        return 'C';
    }
    else{
        return 'D';
    }
}

void computerVSplayer(){
    string playername;
    cout<<"Enter Your Name: ";
    cin>>playername;

    while(true){
        system("cls");
        show_board();
        if(count_board('X')==count_board('O')){
            cout<<playername<<"'s turn"<<endl;
            getXplayer_choice();
        }
        else{
            get_computer_choice();
        }
        char winner = check_winner();
        if(winner=='X'){
            system("cls");
            show_board();
            cout<<playername<<" won the game"<<endl;
            break;
        }
        else if(winner=='O'){
            system("cls");
            show_board();
            cout<<"Computer won the game"<<endl;
            break;
        }
        else if(winner=='D'){
            system("cls");
            show_board();
            cout<<"Game is Draw"<<endl;
            break;
        }
    }
}
void playerVSplayer(){
    string xplayer,oplayer;
    cout<<"Enter X Player Name: "<<endl;
    cin>>xplayer;
    cout<<"Enter O Player Name: "<<endl;
    cin>>oplayer;

    while(true){
        system("cls");
        show_board();
        if(count_board('X')==count_board('O')){
            cout<<xplayer<<"'s turn"<<endl;
            getXplayer_choice();
        }
        else{
            cout<<oplayer<<"'s turn"<<endl;
            getOplayer_choice();
        }
        char winner = check_winner();
        if(winner=='X'){
            system("cls");
            show_board();
            cout<<xplayer<<" won the game"<<endl;
            break;
        }
        else if(winner=='O'){
            system("cls");
            show_board();
            cout<<oplayer<<" won the game"<<endl;
            break;
        }
        else if(winner=='D'){
            system("cls");
            show_board();
            cout<<"Game is Draw"<<endl;
            break;
        }
    }
}
/*
int main(){

    int mode;
    cout<<"1. Computer vs Player"<<endl;
    cout<<"2.Player vs Player"<<endl;

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
    return 0;
}
*/