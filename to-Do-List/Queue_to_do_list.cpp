#include<iostream>
#include<string>
using namespace std;

const int MAX_SIZE=20;

class toDoList{
    string arr[MAX_SIZE];
    int front,rear;
    public:
        toDoList(){
            rear=front=-1;
        }
        void addTaks(string s);
        void viewTasks();
        void dotask();
        int tasksLeftToDo();
        bool isEmpty();
        string Front();
};
string toDoList::Front(){
    return arr[front];
}
bool toDoList::isEmpty(){
    if (front==-1 || front>rear){
        return true;
    }
    return false;
}
void toDoList::addTaks(string s){
    if(rear==MAX_SIZE-1){
        cout<<"cannot add more tasks. queue is full"<<endl;
        return;
    }
    if(front==-1){
        front=0;
    }
    cout<<"Task added : "<<s<<endl;
    arr[++rear]=s;
    cout<<endl;
}
void toDoList::dotask(){
    if(isEmpty()){
        cout<<"You don't have any tasks to do, you have completed your tasks"<<endl;
        return;
    }
    cout<<"task completed: "<<Front()<<endl;
    front++;
    cout<<endl;
}
void toDoList::viewTasks(){
    if(isEmpty()){
        cout<<"You don't have any tasks to do, you have completed your tasks"<<endl;
        return;
    }
    cout<<"Tasks to do:"<<endl;
    int count=0;
    for(int i=front;i<=rear;i++){
        count+=1;
        cout<<"Task "<<count<<" :"<<arr[i]<<endl;
    }
    cout<<endl;
}
int toDoList::tasksLeftToDo(){
    return rear-front+1;
}

int main(){
    string choice;
    bool blncontinue=true;
    toDoList td;
    do{
       
        cout<<"a. add task to the to_do_list \n";
        cout<<"b. do a task \n";
        cout<<"c. view the list \n";
        cout<<"d. number of tasks left to do \n ";
        cout<<"e. exit \n";
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == "a" || choice == "A"){
            cout<<"enter task you want to add to your to_do_list :";
            string s;
            cin>>s;
            td.addTaks(s);
        }
        else if(choice=="B" || choice=="b"){
            td.dotask();
        }
        else if(choice=="C" || choice=="c"){
            td.viewTasks();
        }
        else if(choice=="D" || choice=="d"){
            cout<<td.tasksLeftToDo();
            cout<<endl;
        }
        else if(choice=="X" || choice=="x"){
            cout<<"Exiting........"<<endl;
            blncontinue=false;
        }
        else{
            cout<<"invalid input "<<endl;
        }
    
    }
    while(blncontinue);
    return 0;
}