#include <iostream>
#include "qttest.h"
#include <string>
//Bingjian Du 20706578
using namespace std;
int main(){
    string s;
    tree mytree;
    while(getline(cin, s)){
        string command,substring;
        extract_input(s,command,substring);
        if(command=="i"){
            string name;
            double x;
            double y;
            long long p;
            double r;
            double s;
            if(extract_info(substring,name,x,y,p,r,s)){
                city *new_city=new city(name,x,y,p,r,s);
                if(mytree.insert(new_city,mytree.get_root())){
                    cout<<"success";
                }else{
                    cout<<"failure";
                }
            }
        }else if(command=="s"){
            double x;
            double y;
            if(extract_search(substring,x,y)){
                mytree.search(x,y);
            }
        }else if(command=="q_max"){
            double x,y;
            string attr,direction;
            if(extract_attr(substring,x,y,direction,attr){
                mytree.q_max(x,y,direction,attr);
            }
        }else if(command=="q_min"){
            double x,y;
            string attr;
            if(extract_attr(substring,x,y,attr){
                
            }
        }else if(command=="q_total"){
            double x,y;
            string attr;
            if(extract_attr(substring,x,y,attr){
                
            }
        }else if(command=="print"){
            double x,y;
            string attr;
        }else if(command=="clear"){
            double x,y;
            string attr;
        }else if(command=="size"){
            ;
        }else{
            ;
        }
    }
}
void extract_input(string input,string&command,string&substring){
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
bool extract_info(string input,string &name,double &x, double &y, long long &p,double &r, double &s){
    int a=0;
    string longtitude,latitude, population, cost, salary;
    for (size_t i = 0; i != input.length(); i++)
    {
        if (input[i] != ' ' && a==0)
        {
            name = name + input[i];
        }
        if(input[i] != ' ' && a==1){
            longtitude=longtitude+input[i];
        }
        if(input[i] != ' ' && a==2){
            latitude=latitude+input[i];
        }
        if(input[i] != ' ' && a==3){
            population=population+input[i];
        }
        if(input[i] != ' ' && a==4){
            cost=cost+input[i];
        }
        if(input[i] != ' ' && a==5){
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
    p=stoll(population);
    r=stod(cost);
    s=stod(salary);
    return true;
} 
bool extract_search(string input,double &x, double &y){
    int a=1;
    string longtitude,latitude;
    for (size_t i = 0; i != input.length(); i++)
    {
        if(input[i] != ' ' && a==1){
            longtitude=longtitude+input[i];
        }
        if(input[i] != ' ' && a==2){
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
bool extract_attr(string input,double &x, double &y,string &dir,string &attr){
    string longtitude,latitude;
    int a=1;
    for (size_t i = 0; i != input.length(); i++)
    {
        if(input[i] != ' ' && a==1){
            longtitude=longtitude+input[i];
        }
        if(input[i] != ' ' && a==2){
            latitude=latitude+input[i];
        }
        if(input[i] != ' ' && a==3){
            dir=dir+input[i];
        }
        if(input[i] != ' ' && a==4){
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