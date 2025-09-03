#include<iostream>
#include<limits>
using namespace std;
char space[3][3];
int row, column;
char token= 'X';
string n1, n2; 
bool tie=false;
void func1(){
    cout<<"    |    | \n";
    cout<<" "<<space[0][0]<<"  | "<<space[0][1]<<"  | "<<space[0][2]<<"  \n";
    cout<<"____|____|____ \n";
    cout<<"    |    | \n";
    cout<<" "<<space[1][0]<<"  | "<<space[1][1]<<"  | "<<space[1][2]<<"  \n";
    cout<<"____|____|____ \n";
    cout<<"    |    | \n";
    cout<<" "<<space[2][0]<<"  | "<<space[2][1]<<"  | "<<space[2][2]<<"  \n";
    cout<<"    |    | \n";
} 
void func2(){
    int digit;
    bool validmove=false;
    while(!validmove){
    if(token=='X'){
        cout<<n1<<" Please enter a number: ";
        cin>>digit;
    }
     if(token=='0'){
        cout<<n2<<" Please enter a number : ";
        cin>>digit;
    }
    switch(digit){
               case 1: row=0; column=0;
                       break;
               case 2: row=0; column=1;
                       break;
               case 3: row=0; column=2;
                       break;
               case 4: row=1; column=0;
                       break;
               case 5: row=1; column=1;
                       break;
               case 6: row=1; column=2;
                       break;
               case 7: row=2; column=0;
                       break;
               case 8: row=2; column=1;
                       break;
               case 9: row=2; column=2;
                       break;
              default:cout<<"Invalid !!"<<endl;
                   continue;
    }
if(token=='X' && space[row][column]!='X' && space[row][column]!='0')    //player 1 turn
   { space[row][column]='X';
      token='0';
      validmove=true;
    }
    else if(token=='0' && space[row][column]!='X' && space[row][column]!='0')  //player2 turn
   { space[row][column]='0';
     token='X';
     validmove=true;
     }
    else{
        cout<<"That spot is already taken "<<endl;
    }
}
}

bool func3(){
        for( int i=0;i<3;i++){
            if(space[i][0]==space[i][1]  && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])  {
                 return true;
            }  //rows
        }
        if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1]&& space[1][1]==space[2][0]){
           return true; 
        }  //diagonal

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
              if (space[i][j]!='X' && space[i][j]!='0'){
                 return false;      //game is going on  
              }  
            }
        }
        tie =true;
        return false;
    } 
    void resetboard(){
        char num='1';
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                space[i][j]=num++;
            }
        }
        token='X';
        tie=false;
    }
    int main(){
        cout<<"```````````````TIC TAC TOE GAME ```````````````"<<endl;
        cout<<"Enter the name of the first player : \n";
        getline(cin,n1);
        cout<<"Enter the name of the second player : \n";
        getline(cin,n2);
        cout<<n1<< " is player1 (X) \n";
        cout<<n2<<" is player 2 (0) \n";
        char playagain;
        do{
            resetboard();
            func1();
        while(!func3()){
            func2();
            func1();
        }
        if(token=='X' && tie==false){
            cout<<n2<<" Win!!"<<endl;
        }
        else if(token=='0' && tie==false){
            cout<<n1<<" Win!!"<<endl;
        }
        else{
            cout<<" It's a draw!!"<<endl;
        }
        cout<<"DO YOU WANT TO PLAY AGAIN?? (Y/N): ";
        cin>>playagain;
    }while(playagain=='Y' || playagain=='y');

        return 0;
    }
    