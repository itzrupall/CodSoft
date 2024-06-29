#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int n;

void game(){
    const int N = 100;
    //generating the secret number
    srand(time(0));
    int num =  1 + (rand() % 100);
    cout<<"\tGuess a number between 1 to 100"<<endl;
    cout<<"\tYou have 10 choices to find the secret number"<<endl;
    
    int choices_left = 10;
    for(int i = 0; i < 10; i++){
        
        cout<<"\n\tEnter the number you guessed"<<endl;
        cin>>n;

        //check for correct input
        if(n < 0 || n > 100){
            cout<<"\tEnter valid number between 0 and 100"<<endl;
            break;
        }
        //checking if the guessed no is correct
        if(n == num){
            cout<<"\tWell played!!\n\tYou guessed the number perfectly!\n\tThanks for playing..."<<endl;
            break;
        }
        else{
            cout<<"\tSorry you guessed wrong.."<<endl;
        }

        if(n > num){
        //Hints for the guessed no
            cout<<"\tSecret number is smaller than the number you guessed."<<endl;
        }
        else{
            cout<<"\tSecret number is bigger than the number you guessed."<<endl;
        }
        choices_left--;
        cout<<"\tChoices left are:"<<choices_left<<endl;
        if(choices_left == 0){
            cout<<"\tSorry you are out of choices"<<"\n\tThanks for playing..Better luck next time."<<endl;
            cout<<"\tThe secret number was:"<<num<<endl;
            break;
        }
        
        
    }
    
    
}

int main(){
    cout<<"\t\t\t\t\t--------------------------------------"<<endl;
    cout<<"\t\t\t\t\tWELCOME TO THE NUMBER GUESSING GAME!!"<<endl;
    cout<<"\t\t\t\t\t--------------------------------------"<<endl;
    char playagain;
    game();

    do{
        
        cout<<"\tDo you want to play again?? \n\t(Y,N)"<<endl;
        cin>>playagain;
        if(playagain == 'Y' || playagain == 'y')
            game();
        else
            cout<<"\tThanks for playing"<<endl;

    }while(playagain == 'Y' || playagain == 'y');

    return 0;
}
