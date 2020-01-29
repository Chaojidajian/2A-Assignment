#include<iostream>
#include<string>
#include "list.h"
using namespace std;
void extract_input(string input,string&command,string&parameter){
    bool c = true;
        for (size_t i = 0; i != input.length(); i++)
        {
            if (input[i] != ' ' && c)
            {
                command = command + input[i];
            }
            if (input[i] == ' ' && c)
            {
                c = false;
            }
            if (input[i] != ' ' && !c)
            {
                parameter = parameter + input[i];
            }
        }
}
int main(){
    string s="";
    linked_list mylist;
    while(getline(cin, s)){
        string command="";
        string parameter="";
        extract_input(s,command,parameter);
        if(command=="enqueue_front"){
            int data=stoi(parameter);
            mylist.enqueue_front(data);
        }else if(command=="enqueue_back"){
            int data=stoi(parameter);
            mylist.enqueue_back(data);
        }else if(command=="dequeue_front"){
            mylist.dequeue_front();
        }else if(command=="dequeue_back"){
            mylist.dequeue_back();
        }else if(command=="clear"){
            mylist.~linked_list();
            cout<<"success"<<endl;
        }else if(command=="front"){
            int data=stoi(parameter);
            mylist.front(data);
        }else if(command=="back"){
            int data=stoi(parameter);
            mylist.back(data);
        }else if(command=="empty"){
            mylist.empty();
        }else if(command=="size"){
            mylist.size();
        }else if(command=="print"){
            mylist.print();
        }else{
            ;
        }
    }
}