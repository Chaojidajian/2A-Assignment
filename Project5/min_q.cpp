#include "min_q.h"
min_q::min_q(vector<node *> vertices){
  this->vertices=vertices;
}
void min_q::heapify(int i)
{
    int size = this->vertices.size();
    int smal = i;
    int r = 2 * i + 2;
    int l = 2 * i + 1;
    if (l <size && *(this->vertices[l] )< *(this->vertices[smal])){
        smal = l;
    }
    if (r < size && *(this->vertices[r])< *(this->vertices[smal])){
        smal = r;
    }
    if (smal!= i)
    {   
      node* temp = this->vertices[i];
      this->vertices[i]=this->vertices[smal];
      this->vertices[smal]=temp;
      heapify(smal);
    }
}
void min_q::build(){
  int i;
  for(i=(this->vertices.size()-1)/2; i>=0; i--) {
    heapify(i);
  }
}
vector<node *> min_q::get_q(){
  return this->vertices;
}
node* min_q::extractMin(){ 
    if (this->vertices.size() == 1) 
    { 
        return this->vertices[0]; 
    } 
    node* root = this->vertices[0]; 
    this->vertices[0]= this->vertices.back(); 
    this->vertices.pop_back(); 
    return root; 
}