#include "set.h"
using namespace std;//Bingjian Du 20706578
void set::makeset(int num){
    for(int i=0;i<num;i++){
        node *temp1=new node(i);
        nodelist temp2(temp1);
        this->theSet.push_back(temp2);
    }
}
node *set::findset(int num){
    return this->theSet[num].get_head();
}
void set::merge(int a, int b){ //merging disjoint sets
    nodelist *temp1=&this->theSet[a];
    nodelist *temp2=&this->theSet[b];  
    node *temp3=this->theSet[a].get_head();
    node *temp4=this->theSet[b].get_head();
    temp1->get_tail()->set_next(temp4);
    do
    {//setting the first part new tail
        int temp5=temp3->get_vertex();
        nodelist *temp6=&this->theSet[temp5]; 
        temp6->set_tail(temp2->get_tail());
        temp6->set_head(temp1->get_head());
        temp3=temp3->get_next();
    }while(temp3!=nullptr);
}
set::~set(){
    while (!theSet.empty()){
        nodelist temp=theSet.back();
        delete temp.get_current();
        theSet.pop_back();
  }
}