#include<iostream>
#include<windows.h>
using namespace std;
void print_tasks(string tasks[], bool completed[],int task_count){
    cout<<"Tasks To Perform: "<<endl;
    cout<<"----------------------------------------------------"<<endl;
    for(int i=0;i<task_count;i++){
        cout<<"Task "<<i<<" : "<<tasks[i]<<" ["<<(completed[i] ? "Completed" : "Pending" ) << "]"<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
}


int main(){
 string tasks[100]={""};
 bool completed[100]={false};
 //counter var->know how manny tasks we have
int task_count=0;
int option=-1;
while(option!=0){
//menu
cout<<"-----To Do List-------"<<endl;
cout<<"1 - Add New Task"<<endl;
cout<<"2 - View Tasks"<<endl;
cout<<"3 - Delete the Tasks"<<endl;
cout<<"4 - Mark Task as Completed "<<endl;
cout<<"0 - Terminate the Program"<<endl;
cout<<"Enter your option : ";
cin>>option;
switch(option){
    case 1:{
        if(task_count>99){
        cout<<"``````Task List is Full``````"<<endl;
        }
        else{
           cout<<"Enter a New Task: "; 
           cin.ignore();             //will not take empty spaces
           getline(cin,tasks[task_count]);
           completed[task_count]=false;
           task_count++;
        }
        break;
    }
    case 2:
    system("cls");
    if(task_count==0){
        cout<< "No tasks available!!" << endl;}
    else{
         print_tasks(tasks,completed,task_count);
    }
    break;
    case 3:{
        system("cls");
        print_tasks(tasks,completed,task_count);
        int del_task=0;
        cout<<"Enter  task number to delete : ";
        cin>>del_task;
        if(del_task<0 || del_task>=task_count){
            cout<<"You Entered an Invalid Task No."<<endl;
            break;
        }
        for(int i=del_task; i<task_count;i++){
            tasks[i]=tasks[i+1];
            completed[i]=completed[i+1];
        }
        task_count=task_count-1;
        cout<<"Task deleted successfully."<<endl;
        break;
    }
    case 4:{
        system("cls");
       print_tasks(tasks,completed,task_count);
       int mark_task;
       cout<<"Enter task number to mark as completed: ";
       cin>>mark_task;
      if (mark_task < 0 || mark_task >= task_count) {
                    cout << "Invalid task number!" << endl;
                } else {
                    completed[mark_task] = true;
                    cout << "Task marked as completed!" << endl;
                }
                break;

    }
    case 0:
    cout<<"-----------Terminating the Program-------------"<<endl;
    break;
    default:
            cout<<"You entered Invalid Value!!"<<endl;
}

}



    return 0;
}