#include<iostream>
#include<string>
#include<ctime>
using namespace std;
class book{
    public:
           string title,author,ISBN;
           bool isAvailable;
           time_t issuedate;

book(){
    title ="";
    author ="";
    ISBN="";
    isAvailable=true;
}
void setbook(string t, string a,string i){
    title=t;
    author=a;
    ISBN=i;
    isAvailable=true;
}
};

class library{
    private:
            book books[100];     //100 objects of book class type.
            int bookcount;
    public:
          library(){
            bookcount=0;
          }
    void addbook(string title,string author,string ISBN){
         if(bookcount<100){
            books[bookcount].setbook(title,author,ISBN);
            bookcount++;
            cout<<"Book added successfully!!\n";
         }
         else{
            cout<<"Library is full!!.Cannot add more books.\n";
         }
    }
    void displaybooks(){
        if(bookcount==0){
            cout<<"No books in the library.\n";
            return;
        }
        cout<<"\n-------------------BOOK LIST-----------------\n";
        for(int i=0;i<bookcount;i++){
            cout<<i+1<<"."<<books[i].title<<"by"<<books[i].author<<" | ISBN : "<<books[i].ISBN<<" | "<<(books[i].isAvailable?"Available":"Issued")<<endl;
        }
    }
    void searchbook(string key){
        bool found=false;
        for(int i=0;i<bookcount;i++){
            if(books[i].title==key || books[i].author==key || books[i].ISBN==key){
                cout<<"Found: "<<books[i].title<<" by "<< books[i].author<<endl;
                found=true;
                break;
            }
        }
        if(!found)cout<<"Book not found!!\n";
    }
    void issuebook(string ISBN){
        for(int i=0;i<bookcount;i++){
            if(books[i].ISBN==ISBN && books[i].isAvailable){
                books[i].isAvailable=false;
                books[i].issuedate=time(0);
                cout<<"Book issued successfully!! \n";
                return ;
            }
        }
        cout<<"Book is not available or ISBN is incorrect!! \n";
    }
    void returnbook(string ISBN){
        for(int i=0;i<bookcount;i++){
            if(books[i].ISBN==ISBN && !books[i].isAvailable){
                time_t now=time(0);
                double days= difftime(now,books[i].issuedate)/(60*60*24);
                int fine=0;
                if(days>7){
                    fine=(days-7)*10;
                }
                cout<<"Book returned. Fine: Rs"<<fine<<endl;
                books[i].isAvailable=true;
                return;
            }
            cout<<"Invalid return or book was not issued!! \n";
        }
    }
};

int main(){
    library l;
    int choice;
    string title,author,ISBN;
    do{
        cout<<"\n------------Library Management System-------------\n";
        cout<<"1.Add book\n2. Display books\n3. Search book\n4. Issue book\n5. Return book\n6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
        case 1 : cin.ignore();
                 cout<<"Enter title : ";
                 getline(cin,title);
                 cout<<"Enter author: ";
                 getline(cin,author);
                 cout<<"Enter ISBN: ";
                 getline(cin,ISBN);
                 l.addbook(title,author,ISBN);
                 break;
        case 2:l.displaybooks();
               break;
        case 3: cin.ignore();
              cout<<"Enter title/author/ISBN to search: ";
              getline(cin,title);
              l.searchbook(ISBN);
              break;
        case 4: cin.ignore();
               cout<<"Enter ISBN to issue: ";
               getline(cin,ISBN);
               l.issuebook(ISBN);
               break;
        case 5: cin.ignore();
               cout<<"Enter ISBN to return: ";
               getline(cin,ISBN);
               l.returnbook(ISBN);
               break;
        case 6:
              cout<<"Exiting....\n";
              break;
        default:
              cout<<"Invalid choice!! \n";
    }
    }while(choice!=6);
    return 0;
}
   