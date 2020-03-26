#include "graph.h"
#include <iostream>
#include <algorithm>
using namespace std;
void graph::set_size(int m){
    try{
        if(m<0){
            throw illegal_argument();
        }
        else{
            edge a;
            vector<vector<edge> > v1(m, vector<edge>(m, a));
            this->matrix=v1;
            this->size=m;
            cout<<"success"<<endl;
        }
    }catch(illegal_argument i)
    {
        cout<<"failure"<<endl;
    }
   
}
int graph::get_size(){
    return this->size;
}
graph::graph(){
    this->size=0;
    this->edge_count=0;
}
void graph::insert(int u,int v,double w){
    try{
        if(w<=0||u>=this->size||v>=this->size){
            throw illegal_argument();
        }else{
            edge a(w,u,v);
            edge b(w,v,u);
            if(this->matrix[u][v].get_weight()==0){
                this->edge_count++;
            }
            this->matrix[u][v]=a;
            this->matrix[v][u]=b;
            cout<<"success"<<endl;
        }
    }catch(illegal_argument i)
    {
        cout<<"failure"<<endl;
    }
}
void graph::del(int u,int v){
    try{
        edge a;
        if(this->matrix[u][v].get_weight()==0||u>=this->size||v>=this->size){
            throw illegal_argument();
        }else{
            this->matrix[u][v]=a;
            this->matrix[v][u]=a;
            cout<<"success"<<endl;
        }
    }catch(illegal_argument i)
    {
        cout<<"failure"<<endl;
    }
}
void graph::degree(int u){
    try{
        if(u>=this->size){
            throw illegal_argument();
        }else{
            int count=0;
            for(int i=0;i<this->size;i++){
                if(this->matrix[u][i].get_weight()!=0){
                    count++;
                }
            }
            cout<<"degree of "<<u<<" is "<<count<<endl;
        }
    }catch(illegal_argument i)
    {
        cout<<"failure"<<endl;
    }
}
void graph::clear(){
    edge a;
    int m=this->size;
    vector<vector<edge> > v1(m, vector<edge>(m, a));
    this->matrix=v1;
}
void graph::mst(){
    vector<edge> edge_set;
    for(int i=0;i<this->size;i++){
        for(int j=0;j<i;j++){
            edge_set.push_back(this->matrix[i][j]);
        }
    }
    std::sort(edge_set.begin(),edge_set.end());
    node node_list[this->size];
    for(int i=0;i<this->size;i++){
        node temp(i);
        node_list[i]=temp;
    }
    vector<set> sets;
    for(int i=0;i<this->size;i++){
        set temp(node_list[i]);
        sets.push_back(temp);
    }
    for (auto it = edge_set.begin(); it != edge_set.cend(); ++it){
        it->get_weight();
        std::cout << ' ' << *it;
        std::cout << '\n';
    }

}

int main(){
    graph my_graph;

}