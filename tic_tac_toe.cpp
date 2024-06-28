#include<iostream>
#include<array>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char space[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char current_marker;
char current_player;
char P1_n, P2_n;
char P1_marker;

void drawboard(){
    cout<<" "<<board[0][0]<<" "<<"|"<<" "<<board[0][1]<<" "<<"|"<<" "<<board[0][2]<<endl;
    cout<<"---"<<" "<<"---"<<" "<<"---"<<endl;
    cout<<" "<<board[1][0]<<" "<<"|"<<" "<<board[1][1]<<" "<<"|"<<" "<<board[1][2]<<endl;
     cout<<"---"<<" "<<"---"<<" "<<"---"<<endl;
    cout<<" "<<board[2][0]<<" "<<"|"<<" "<<board[2][1]<<" "<<"|"<<" "<<board[2][2]<<endl;

}

bool place_maker(int slot){
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = current_marker;
        return true;
    }else{
        return false;
    }
}

char winner(){
    //rows check
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return current_player;
        }
    }

    //columns check
    for(int i = 0;i <3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return current_player;
        }
    }

    //diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return current_player;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return current_player;
    }

    return 0;
}

void swap_player_and_marker(){
    if(current_marker == 'X'){
        current_marker = 'O';
    }else{
        current_marker = 'X';
    }

    if(current_player == P1_n){
        current_player = P2_n;
    }else{
        current_player = P1_n;
    }
}

void reset(){
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = space[i][j];
        }
    }
}
void game(){
    
    cout<<"Player 1 give your initial:"<<endl;
    cin>>P1_n;
    cout<<"Choose your marker: (X/O)"<<endl;
    cin>>P1_marker;
    cout<<"Player 2 give your initial:"<<endl;
    cin>>P2_n;

    current_player = P1_n;
    current_marker = P1_marker;

    drawboard();
    int player_won;

    for(int i = 0; i < 9; i++){
        cout<<"Its player "<<current_player<<"'s turn."<<"\nEnter your slot:"<<endl;
        int slot;
        cin>>slot;

        if(slot < 1 || slot > 9){
            cout<<"Invalid choice"<<"\nTry again!"<<endl;
            i--;
            continue;
        }

        if(!place_maker(slot)){
            cout<<"Slot is Already occupied!"<<"\nSelect another slot."<<endl;
            i--;
            continue;
        }

        drawboard();
        player_won = winner();

        if(player_won == P1_n){
            cout<<"The winner is "<<P1_n<<endl;
            break;
        }else if(player_won == P2_n){
            cout<<"The winner is "<<P2_n<<endl;
            break;
        }

        swap_player_and_marker();

    }

    if(player_won == 0){
        cout<<"Its a tie!"<<endl;
    }
}

int main(){
    cout<<endl<<"WELCOME TO THE TIC-TAC-TOE GAME!"<<endl;
    char playagain;
    game();
    do{
        cout<<"Do you want to play again? (Y/N)"<<endl;
        cin>>playagain;

        if(playagain == 'Y' || playagain == 'y'){
            reset();
            game();
        }else if(playagain == 'N' || playagain == 'n'){
            cout<<"Thanks for playing!!"<<endl;
        }else{
            cout<<"Enter valid choice!"<<endl;
        }
    }while(playagain == 'Y' || playagain == 'y');
    
    return 0;
}
