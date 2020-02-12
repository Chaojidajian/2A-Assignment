#include <iostream>
#include "chain_table.h"
using namespace std;
void extract_input(string input,string&command,string&number,string &name){
    int a=0;
        for (size_t i = 0; i != input.length(); i++)
        {
            if (input[i] != ' ' && a==0)
            {
                command = command + input[i];
            }if(input[i] != ';' && a==1){
                number=number+input[i];
            }
            if(input[i] != ';' && a==2){
                name=name+input[i];
            }
            if (input[i] == ' ' && a==0)
            {
                a=1;
            }
            if(input[i] == ';' && a==1){
                a=2;
            }
        }
}
int main(){
    string s="";
    chain_table mytable;
    while(getline(cin, s)){
        string command,number,name;
        extract_input(s,command,number,name);
        // cout<<command<<" "<<number<<" "<<name<<" "<<endl;
        if(command=="n"){
            mytable.define(number);
        }else if(command=="i"){
            if(number.length()==10){
                mytable.insert(number,name);
            }
        }else if(command=="s"){
            if(number.length()==10){
                mytable.search(number);
            }      
        }else if(command=="d"){
            if(number.length()==10){
                mytable.delete_data(number);
            }
        }else if(command=="p"){
            int temp=stoll(number);
            if(mytable.get_size()>=temp){
                mytable.print(number);
            }
        }else{
            ;
        }
    }
}