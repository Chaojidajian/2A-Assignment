#include"tree.h"
#include<string>
//Bingjian Du 20706578
void parse_input(string input,string&command,string&substring);//parse input
bool parse_info(string input,string &name,double &x, double &y, long &p,long &r, long &s);//parse city info
bool parse_search(string input,double &x, double &y);//parse x,y
bool parse_attr(string input,double &x, double &y,string &dir,string &attr);//parse attribute