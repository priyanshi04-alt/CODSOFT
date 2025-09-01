#include<iostream>
#include<cstdlib>   //rand()
#include<ctime>    //time
using namespace std;
//Random number generation using rand() =41,function (predefined function)
//int random =offset + (rand() % range);
int main(){
    // srand(time(0));   //generate new random
    // int secretnumber=1 + (rand() % 100);
    cout<<"\n\t\t\tWelcome To GuessTheNumber Game!!"<<endl;
    cout<<"You have to guess a number between 1 and 100, You'll have limited choices based on the level you choose.Good Luck!!"<<endl;
    while(true){
     cout<<"\n Enter the difficulty level : \n ";
     cout<<" 1. Easy !!\t";
     cout<<" 2. Medium !!\t";
     cout<<" 3. Difficult !!\t";
     cout<<" 0. End Game !!\n"<<endl ;
       int difficultyChoice;
       cout<<"Enter the number : ";
       cin>>difficultyChoice;
       srand(time(0));   //generate new random
       int secretnumber=1 + (rand() % 100);
       int playerChoice;
       if(difficultyChoice==1){
         cout<<"\n You have 10 choices for finding the secret number between 1 and 100.";
         int choicesLeft=10;
         for(int i=0;i<10;i++){
          cout<<"\n\n Enter the number: ";
          cin>>playerChoice;
          if(playerChoice==secretnumber){
            cout<<"Well played! You won , "<<playerChoice<<" is the secret number"<<endl;
            cout<<"\t\t\t Thanks for playing :)....."<<endl;
            cout<<"Play the game again with us!!\n\n"<<endl;
            break;
          }
          else{
            cout<<"OOPS!! "<<playerChoice<<" is not the right number\n";
            if(playerChoice>secretnumber){
              cout<<"The secret number is smaller than the number you have chosen"<<endl;
            }
            else{
              cout<<"The secret number is greater than the number you have chosen"<<endl;
            }
            choicesLeft--;
            cout<<choicesLeft<<" choices left "<<endl;
            if(choicesLeft==0){
              cout<<"You couldn't find the secret number, it was "<<secretnumber<<" ,You lose!!\n\n";
              cout<<"Play the game again to win!!\n\n";
            }
          }
         }
       }
        else if(difficultyChoice==2){
           cout<<"\n You have 7 choices for finding the secret number between 1 and 100.";
         int choicesLeft=7;
         for(int i=0;i<7;i++){
          cout<<"\n\n ENter the number: ";
          cin>>playerChoice;
          if(playerChoice==secretnumber){
            cout<<"Well played! You won, "<<playerChoice<<" is the secret number"<<endl;
            cout<<"\t\t\t Thanks for playing....."<<endl;
            cout<<"Play the game again with us!!\n\n"<<endl;
            break;
          }
          else{
            cout<<"OOPS!! "<<playerChoice<<" is not the right number\n";
            if(playerChoice>secretnumber){
              cout<<"The secret number is smaller than the number you have chosen"<<endl;
            }
            else{
              cout<<"The secret number is greater than the number you have chosen"<<endl;
            }
            choicesLeft--;
            cout<<choicesLeft<<" choices left "<<endl;
            if(choicesLeft==0){
              cout<<"You couldn't find the secret number, it was "<<secretnumber<<" ,You lose!!\n\n";
              cout<<"Play the game again to win!!\n\n";
            }
          }
         }

        }
        else if(difficultyChoice==3){
           cout<<"\n You have 5 choices for finding the secret number between 1 and 100.";
         int choicesLeft=5;
         for(int i=0;i<5;i++){
          cout<<"\n\n ENter the number: ";
          cin>>playerChoice;
          if(playerChoice==secretnumber){
            cout<<"Well played! You won, "<<playerChoice<<" is the secret number"<<endl;
            cout<<"\t\t\t Thanks for playing....."<<endl;
            cout<<"Play the game again with us!!\n\n"<<endl;
            break;
          }
          else{
            cout<<"OOPS!! "<<playerChoice<<" is not the right number\n";
            if(playerChoice>secretnumber){
              cout<<"The secret number is smaller than the number you have chosen"<<endl;
            }
            else{
              cout<<"The secret number is greater than the number you have chosen"<<endl;
            }
            choicesLeft--;
            cout<<choicesLeft<<" choices left "<<endl;
            if(choicesLeft==0){
              cout<<"You couldn't find the secret number, it was "<<secretnumber<<" ,You lose!!\n\n";
              cout<<"Play the game again to win!!\n\n";
            }
          }
         }
        }
        else if(difficultyChoice==0){
          exit(0);    //ends the program
        }
        else{
          cout<<"Wrong choice, Enter valid choice to play the game! (0,1,2,3)"<<endl;
        }
       
    }
    return 0;
}