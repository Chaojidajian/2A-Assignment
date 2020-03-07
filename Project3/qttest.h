#include"tree.h"
#include<string>
//Bingjian Du 20706578
void extract_input(string input,string&command,string&substring);//extract input
bool extract_info(string input,string &name,double &x, double &y, long long &p,double &r, double &s);//extract city info
bool extract_search(string input,double &x, double &y);
bool extract_attr(string input,double &x, double &y,string &dir,string &attr);