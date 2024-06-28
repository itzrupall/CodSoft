#include<iostream>
#include<cmath>
using namespace std;

int choice;
double num_01, num_02;
double result;

int display_dashboard(){
    cout<<"Enter the choice for your calculations"<<endl;
    cout<<"1. ADDITION"<<endl;
    cout<<"2. SUBTRACTION"<<endl;
    cout<<"3. MULTIPLICATION"<<endl;
    cout<<"4. DIVISION"<<endl;
    
    return 0;
}

void calculator(){
    cout<<"Enter the first number:";
    cin>>num_01;
    cout<<"Enter the second number:";
    cin>>num_02;

    display_dashboard();
    cin>>choice;

    switch(choice) {
        case 1:
            result = num_01 + num_02;
            cout<<"The addition of "<<num_01<<" and "<<num_02<<" is: "<<endl<<num_01<<" + "<<num_02<<" = "<<result<<endl;
            break;
        case 2:
            result = num_01 - num_02;
            cout<<"The subtraction of "<<num_01<<" and "<<num_02<<" is: "<<endl<<num_01<<" - "<<num_02<<" = "<<result<<endl;
            break;
        case 3:
            result = num_01 * num_02;
            cout<<"The multiplication of "<<num_01<<" and "<<num_02<<"is:"<<endl<<num_01<<" * "<<num_02<<" = "<<result<<endl;
            break;
        case 4:
            if(num_02 != 0){
            result = num_01 / num_02;
            cout<<"The division of "<<num_01<<" and "<<num_02<<" is: "<<endl<<num_01<<" / "<<num_02<<" = "<<result<<endl;
            }else{
                cout<<"Division with zero is not possible!!"<<endl;
            }
            break;
        default:
            cout<<"Invalid choice"<<endl<<"Enter the correct choice"<<endl;
    }

}

int main(){
    char ans;
    cout<<"WELCOME TO SIMPLE CALCULATOR!!"<<endl;

    calculator();

    do{
        cout<<"Do you want to calculate again? (Y/N)"<<endl;
        cin>>ans;

        if(ans == 'Y' || ans == 'y'){
            calculator();
        }else{
            cout<<"Thank you for your time!"<<endl;
        }
    }while (ans == 'Y' || ans == 'y');

    return 0;      
}