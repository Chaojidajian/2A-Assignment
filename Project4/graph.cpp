#include "graph.h"
using namespace std;
//Bingjian Du 20706578
bool compare(edge a, edge b) {
    return a.get_weight() < b.get_weight();
}
void graph::print_ecount(){
    cout<<"edge count is "<<this->edge_count<<endl;
}
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
void graph::del(int u,int v){//delete
    try{
        edge a;
        if(this->matrix[u][v].get_weight()==0||u>=this->size||v>=this->size){
            throw illegal_argument();
        }else{
            this->edge_count--;
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
    this->edge_count=0;
    cout<<"success"<<endl;
}
void graph::mst(){
    vector<edge> edge_set;
    for(int i=0;i<this->size;i++){
        for(int j=0;j<i;j++){
            if(this->matrix[i][j].get_weight()!=0){
                edge_set.push_back(this->matrix[i][j]);
            }
        }
    }
    std::sort(edge_set.begin(),edge_set.end(),compare);
    set sets;
    sets.makeset(this->size);//applying kruskal's algorithm
    double total_weight=0;
    for(auto i=edge_set.begin();i!=edge_set.end();i++){
        int u=i->get_x();
        int v=i->get_y();
        if(*sets.findset(u)!=*sets.findset(v)){
            total_weight+=i->get_weight();
            sets.merge(u,v);
        }
    }
    bool a=true;
    node *temp3=sets.findset(0);
    for(int i=1;i<this->size;i++){
        if(temp3!=sets.findset(i)){
            a=false;
        }
    }
    if(this->size==1){
        a=false;
    }
    if(a){
        cout<<"mst "<<total_weight<<endl;
    }else{
        cout<<"not connected"<<endl;
    }
}
