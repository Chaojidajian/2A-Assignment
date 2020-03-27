#include "set.h"
using namespace std;//Bingjian Du 20706578
void set::makeset(int num){
    for(int i=0;i<num;i++){
        node temp(i);
        this->theSet.push_back(temp);
    }
}
node *set::findset(int num){
    return this->theSet[num].get_head();
}
void set::merge(int a, int b){
    node *temp1=&(this->theSet[a]);
    node *temp2=&(this->theSet[b]);
    temp2->set_head(temp1);
    while(temp1->get_next()!=nullptr){
        temp1=temp1->get_next();
    }
    temp1->set_next(temp2);
    while(temp1->get_next()!=nullptr){
        temp2=temp2->get_next();
        temp2->set_head(temp1);
        
    }

}