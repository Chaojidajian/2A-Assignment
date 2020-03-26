#include "set.h"
void set::makeset(node a[],int size){
    for(auto i=0;i<size;i++){
        this->theSet.push_back(a[i]);
    }
}
node set::findset(node a){
    for (auto it = this->theSet.begin(); it != this->theSet.end(); ++it){
        if(it->get_head()==a){
            return it;
        }
    }
}