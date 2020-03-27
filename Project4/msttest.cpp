//Bingjian Du 20706578
#include <iostream>
#include "msttest.h"
#include <string>
//Bingjian Du 20706578
using namespace std;
graph mygraph;
int main(){
    string s;
    while(getline(cin, s)){
        string command,substring;
        parse_input(s,command,substring);
        if(command=="n"){
            string name;
            int num=stoi(substring);
            mygraph.set_size(num);
        }else if(command=="i"){
            int x,y;
            double weight;
            if(parse_insert(substring,x,y,weight)){
                mygraph.insert(x,y,weight);
            }
        }else if(command=="degree"){
            int x=stoi(substring);
            mygraph.degree(x);
        }else if(command=="d"){
            int x,y;
            if(parse_del(substring,x,y)){
                mygraph.del(x,y);
            }
        }else if(command=="edge_count"){
            mygraph.print_ecount();
        }else if(command=="clear"){
            mygraph.clear();
        }else if(command=="mst"){
            mygraph.mst();
        }else{
            ;
        }
    }
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
bool parse_insert(string input,int &x, int &y,double &weight){
    int a=1;
    string longtitude,latitude,w;
    for (size_t i = 0; i != input.length(); i++)
    {
        if(input[i] != ' ' && a==1&&input[i] != ';'){
            longtitude=longtitude+input[i];
        }
        if(input[i] != ' ' && a==2&&input[i] != ';'){
            latitude=latitude+input[i];
        }
        if(input[i] != ' ' && a==3&&input[i] != ';'){
            w=w+input[i];
        }
        if (input[i] == ';')
        {
            a++;
        }
    }
    if(a!=3||longtitude.length()==0||latitude.length()==0||w.length()==0){
        return false;
    }
    x=stoi(longtitude);
    y=stoi(latitude);
    weight=stod(w);
    return true;
}
bool parse_del(string input,int &x,int &y){
    string longtitude,latitude;
    int a=1;
    for (size_t i = 0; i != input.length(); i++)
    {
        if(input[i] != ' ' && a==1&&input[i] != ';'){
            longtitude=longtitude+input[i];
        }
        if(input[i] != ' ' && a==2&&input[i] != ';'){
            latitude=latitude+input[i];
        }
        if (input[i] == ';')
        {
            a++;
        }
    }
    if(a!=2||longtitude.length()==0||latitude.length()==0){
        return false;
    }
    x=stoi(longtitude);
    y=stoi(latitude);
    return true;
}