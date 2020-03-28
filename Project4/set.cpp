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
    node *temp1=this->theSet[a].get_head();
    node *temp2=this->theSet[b].get_head();;  
    temp1.get_tail()->set_next(temp2.get_head());
    temp1.set_tail(temp2.get_tail());
    while(temp2.get_current()->get_next()!=nullptr){
        int temp3=temp2.get_current()->get_next()->get_vertex();
        nodelist temp4=this->theSet[temp3];
        temp4.set_head(temp1.get_head());

    }
    this->theSet[b].set_head(this->theSet[a].get_head());

}