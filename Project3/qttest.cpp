#include <iostream>
#include "qttest.h"
#include <string>
//Bingjian Du 20706578
using namespace std;
tree mytree;
int main(){
    string s;
    while(getline(cin, s)){
        string command,substring;
        parse_input(s,command,substring);
        if(command=="i"){
            string name;
            double x,y;
            long p,r,s;
            if(parse_info(substring,name,x,y,p,r,s)){
                city *new_city=new city(name,x,y,p,r,s);
                if (mytree.get_root()==nullptr){
                        mytree.set_root(new_city);
                        cout<<"success"<<endl;
                }else{
                    if(mytree.insert(new_city,mytree.get_root())){
                        cout<<"success"<<endl;
                    }else{
                        cout<<"failure"<<endl;
                    }
                }
            }
        }else if(command=="s"){
            double x;
            double y;
            if(parse_search(substring,x,y)){
                mytree.search(x,y);
            }
        }else if(command=="q_max"){
            double x,y;
            string attr,direction;
            if(parse_attr(substring,x,y,direction,attr)){
                mytree.q_max(x,y,direction,attr);
            }
        }else if(command=="q_min"){
            double x,y;
            string direction,attr;
            if(parse_attr(substring,x,y,direction,attr)){
                mytree.q_min(x,y,direction,attr);
            }
        }else if(command=="q_total"){
            double x,y;
            string attr,direction;
            if(parse_attr(substring,x,y,direction,attr)){
                mytree.q_total(x,y,direction,attr);
            }
        }else if(command=="print"){
            mytree.print(mytree.get_root());
            if(mytree.get_root()!=nullptr){
                cout<<endl;
            }
        }else if(command=="clear"){
            mytree.clear(mytree.get_root());
            city *temp=mytree.get_root();
            delete temp;
            mytree.set_root(nullptr);
            mytree.set_size(0);
            cout<<"success"<<endl;
        }else if(command=="size"){
            mytree.tree_size();
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
bool parse_info(string input,string &name,double &x, double &y, long &p,long &r, long &s){
    int a=0;
    string longtitude,latitude, population, cost, salary;
    for (size_t i = 0; i != input.length(); i++)
    {
        if (input[i] != ' ' && a==0&&input[i] != ';')
        {
            name = name + input[i];
        }
        if(input[i] != ' ' && a==1&&input[i] != ';'){
            longtitude=longtitude+input[i];
        }
        if(input[i] != ' ' && a==2&&input[i] != ';'){
            latitude=latitude+input[i];
        }
        if(input[i] != ' ' && a==3&&input[i] != ';'){
            population=population+input[i];
        }
        if(input[i] != ' ' && a==4&&input[i] != ';'){
            cost=cost+input[i];
        }
        if(input[i] != ' ' && a==5&&input[i] != ';'){
            salary=salary+input[i];
        }
        if (input[i] == ';')
        {
            a++;
        }
    }
    if(a!=5){
        return false;
    }

    x=stod(longtitude);
    y=stod(latitude);
    p=stol(population);
    r=stol(cost);
    s=stol(salary);
    return true;
} 
bool parse_search(string input,double &x, double &y){
    int a=1;
    string longtitude,latitude;
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
    if(a!=2){
        return false;
    }
    x=stod(longtitude);
    y=stod(latitude);
    return true;
}
bool parse_attr(string input,double &x, double &y,string &dir,string &attr){
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
        if(input[i] != ' ' && a==3&&input[i] != ';'){
            dir=dir+input[i];
        }
        if(input[i] != ' ' && a==4&&input[i] != ';'){
            attr=attr+input[i];
        }
        if (input[i] == ';')
        {
            a++;
        }
    }
    if(a!=4){
        return false;
    }
    x=stod(longtitude);
    y=stod(latitude);
    return true;
}