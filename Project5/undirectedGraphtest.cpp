//Bingjian Du 20706578
#include <iostream>
#include "undirectedGraphtest.h"
#include <string>
//Bingjian Du 20706578
using namespace std;
graph mygraph;
int main(){
    string s;
    while(getline(cin, s)){
        string command,substring;
        parse_input(s,command,substring);
        if(command=="i"){
            mygraph.insert(substring);
        }else if(command=="setd"){
            string name1,name2;
            double d;
            if(parse_setd(substring,name1,name2,d)){
                mygraph.setd(name1,name2,d);
            }
        }else if(command=="s"){
            if(mygraph.search(substring)){
                cout<<"found "<<substring<<endl;
            }else{
                cout<<"not found"<<endl;
            }
        }else if(command=="degree"){
            mygraph.degree(substring);
        }else if(command=="graph_nodes"){
            mygraph.graph_nodes();
        }else if(command=="graph_edges"){
            mygraph.graph_edges();
        }else if(command=="d"){
            string name1,name2;
            if(parse_name(substring,name1,name2)){
                if(mygraph.distance(name1,name2)!=-1){
                    cout<<"direct distance "<<name1<<" to "<<name2<<" "<<mygraph.distance(name1,name2)<<endl;
                }else{
                    cout<<"failure"<<endl;
                }
            }
        }else if(command=="shortest_d"){
            string name1,name2;
            if(parse_name(substring,name1,name2)){
                mygraph.shortest_d(name1,name2);
            }
        }else if(command=="print_path"){
            string name1,name2;
            if(parse_name(substring,name1,name2)){
               mygraph.print_path(name1,name2); 
            }
        }else if(command=="clear"){
            mygraph.clear();
            cout<<"success"<<endl;    
        }else{
            ;
        }
    }
    return 0;
}
void parse_input(string input,string&command,string&substring){
    int a=0;
    for (size_t i = 0; i != input.length(); i++)
    {
        if (input[i] != ' ' && a==0)
        {
            command = command + input[i];
        }
        if (input[i] == ' ' && a==0)
        {
            a=1;
        }
        if(input[i] != ' ' && a==1){
            substring=substring+input[i];
        }
    }
}
bool parse_setd(string input,string &x, string &y,double &weight){
    int a=1;
    string name1,name2,w;
    for (size_t i = 0; i != input.length(); i++)
    {
        if(input[i] != ' ' && a==1&&input[i] != ';'){
            name1=name1+input[i];
        }
        if(input[i] != ' ' && a==2&&input[i] != ';'){
            name2=name2+input[i];
        }
        if(input[i] != ' ' && a==3&&input[i] != ';'){
            w=w+input[i];
        }
        if (input[i] == ';')
        {
            a++;
        }
    }
    if(a!=3||name1.length()==0||name2.length()==0||w.length()==0){
        return false;
    }
    x=name1;
    y=name2;
    weight=stod(w);
    return true;
}
bool parse_name(string input,string &x,string &y){
    string name1,name2;
    int a=1;
    for (size_t i = 0; i != input.length(); i++)
    {
        if(input[i] != ' ' && a==1&&input[i] != ';'){
            name1=name1+input[i];
        }
        if(input[i] != ' ' && a==2&&input[i] != ';'){
            name2=name2+input[i];
        }
        if (input[i] == ';')
        {
            a++;
        }
    }
    if(a!=2||name1.length()==0||name2.length()==0){
        return false;
    }
    x=name1;
    y=name2;
    return true;
}