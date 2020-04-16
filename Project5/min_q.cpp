#include "min_q.h"
void min_q::swap(node *a, node *b)
{
  node temp = *b;
  *b = *a;
  *a = temp;
}
min_q::min_q(vector<node *> vertices){
  this->vertices=vertices;
}
void min_q::heapify(int i)
{
    int size = this->vertices.size();
    int smal = i;
    int r = 2 * i + 1;
    int l = 2 * i+ 2;
    if (l <size && *(this->vertices[l] )< *(this->vertices[i])){
        smal = l;
    }
    if (r < size && *(this->vertices[r])< *(this->vertices[smal])){
        smal = r;
    }
    if (smal!= i)
    {
        swap(this->vertices[i], this->vertices[smal]);
        heapify(smal);
    }
}
void min_q::build(){
  int i;
  for(i=this->vertices.size()/2; i>=1; i--) {
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
    int root = this->vertices[0]->get_distance(); 
    this->vertices[0]= this->vertices.back(); 
    this->vertices.pop_back(); 
    heapify(0); 
    return this->vertices[0]; 
}