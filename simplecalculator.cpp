#include<iostream>
using namespace std;
int main(){
    char op;
    double num1,num2;
    cout<<"--------------SIMPLE CALCULATOR--------------"<<endl;
    cin>>num1>>op>>num2;

    switch(op){
        case '+': cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl;
                 break;
        case '-': cout<<num1<<"-"<<num2<<"="<<num1-num2<<endl;
                 break;
        case '*': cout<<num1<<"*"<<num2<<"="<<num1*num2<<endl;
                 break;
        case '/':if(num2!=0.0){
                cout<<num1<<"/"<<num2<<"="<<num1/num2<<endl;
                 break;}
                else{
                    cout<<"Division By Zero IS Undefined";
                    break;
                }
        case '%': cout<<"Works only with integers"<<endl;
                  cout<<int(num1)<<"%"<<int(num2)<<"="<<int(num1)%int(num2)<<endl;
                  break;
        default:cout<<"Invalid operator";

    }
}