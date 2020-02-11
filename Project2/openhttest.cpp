#include <iostream>
#include "open_table.h"
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
            if (!c)
            {
                parameter = parameter + input[i];
            }
        }
}
void extract_num(string input,string&num,string&name){
    bool c = true;
        for (size_t i = 0; i != input.length(); i++)
        {
            if (c)
            {
                num = num + input[i];
            }
            if (input[i] == ';' && c)
            {
                c = false;
            }
            if (!c)
            {
                name = name + input[i];
            }
        }
}
int main(){
    string s;
    open_table mytable;
    while(getline(cin, s)){
        string command,parameter;
        extract_input(s,command,parameter);
        for(std::vector<user>::iterator it = mytable.get_data().begin() ; it != mytable.get_data().end(); ++it){
            if((*it).get_number()!=""){
            std::cout<<(*it).get_number()<<" ";
            }
        }
        if(command=="n"){
            int k=stoi(parameter);
            mytable.define(k);
        }else if(command=="i"){
            string num,name;
            extract_num(parameter,num,name);
            long long k=stoll(num);
            if(k>9999999999){
                ;
            }else{
                mytable.insert(num,name);
            }
        }else if(command=="s"){
                mytable.search(parameter);
        }else if(command=="d"){
                mytable.delete_data(parameter);
        }else{
            ;
        }
    }
}