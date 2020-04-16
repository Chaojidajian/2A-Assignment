#include "graph.h"
using namespace std;
//Bingjian Du 20706578
graph::graph(){
    this->node_count=0;
    this->edge_count=0;
}
void graph::init_vertex(){
    for (auto it = this->cities.begin() ; it != this->cities.end(); ++it){
        (*it)->reset();
    }
}
void graph::insert(string name){
    if(!this->search(name)){
        node* temp=new node(name);
        this->cities.push_back(temp);
        this->matrix.push_back(std::vector<edge*>());
        node_count++;
        cout<<"success"<<endl;
    }else{
        cout<<"failure"<<endl;
    }
}
node* graph::find_city1(string name){
    for (auto it = this->cities.begin() ; it != this->cities.end(); ++it){
        if((*it)->get_name()==name){
            return *it;
        }
    }
    return this->cities[0];
}
int graph::find_city2(string name){
    int result=0;
    for (auto it = this->cities.begin() ; it != this->cities.end(); ++it){
        if((*it)->get_name()==name){
            return result;
        }
        result++;
    }
    return -1;
}
void graph::setd(string name1,string name2, double distance){
    if(distance<=0.0||!this->search(name1)||!this->search(name2)||name1==name2){
        cout<<"failure"<<endl;
    }
    else{
        node* temp1=this->find_city1(name1);
        node* temp2=this->find_city1(name2);
        if(this->distance(name1,name2)==-1){
            temp1->add_adjacent(temp2);
            temp2->add_adjacent(temp1);
        }
        edge *temp3=new edge(distance, temp1,temp2);
        edge *temp4=new edge(distance, temp2,temp1);
        this->matrix[this->find_city2(name1)].push_back(temp3);
        this->matrix[this->find_city2(name2)].push_back(temp4);
        edge_count++;
        cout<<"success"<<endl;
    }
}
bool graph::search(string name){
    for (auto it = this->cities.begin() ; it != this->cities.end(); ++it){
        if((*it)->get_name()==name){
            return true;
        }
    }
   return false;
}
void graph::degree(string name){
    if(this->search(name)){
        cout<<"degree of "<<name<<" "<<this->matrix[this->find_city2(name)].size()<<endl;
    }else{
        cout<<"failure"<<endl;
    }
}
void graph::graph_nodes(){
    cout<<"number of nodes "<<this->node_count<<endl;
}
void graph::graph_edges(){
    cout<<"number of edges "<<this->edge_count<<endl;
}
double graph::distance(string name1,string name2){
    if(!this->search(name1)||!this->search(name2)||name1==name2){
        return -1;
    }else{
        for (auto it = this->matrix[this->find_city2(name1)].begin() ; it != this->matrix[this->find_city2(name1)].end(); ++it){
            if((*it)->get_city2()->get_name()==name2){
                return (*it)->get_weight();
            }
        }
        return -1;
    }
}
void graph::shortest_d(string name1,string name2){
    this->init_vertex();
    if(!this->search(name1)||!this->search(name2)||name1==name2){
        cout<<"failure"<<endl;
        return;
    }
    node *start=this->find_city1(name1);//use name1 as start vertex
    start->set_distance(0);
    min_q a(this->cities);
    a.build();
    while(a.get_q().size()!=0){
        node *temp1=a.extractMin();
        int i=temp1->get_adjacent().size();
        for(int j = 0 ; j != i; ++j){
            double temp3=this->distance(temp1->get_adjacent()[j]->get_name(),temp1->get_name())+temp1->get_distance();
            if(temp1->get_adjacent()[j]->get_distance()==-1){
                temp1->get_adjacent()[j]->set_distance(temp3);
            }else{
                if(temp1->get_adjacent()[j]->get_distance()>temp3){
                    temp1->get_adjacent()[j]->set_distance(temp3);
                    temp1->get_adjacent()[j]->set_parent(temp1);
                }
            } 
        }
        a.build();
    }
    node *temp3=this->find_city1(name2);
    if(temp3->get_distance()==-1){
        cout<<"failure"<<endl;
    }else{
        cout<<"shortest distance "<<name1<<" to "<<name2<<" "<<temp3->get_distance()<<endl;
    }
}
void graph::print_path(string name1,string name2){
    this->init_vertex();
    if(!this->search(name1)||!this->search(name2)||name1==name2){
        cout<<"failure"<<endl;
        return;
    }
    node *start=this->find_city1(name1);//use name1 as start vertex
    start->set_distance(0);
    min_q a(this->cities);
    a.build();
    while(a.get_q().size()!=0){
        node *temp1=a.extractMin();
        vector<edge*> temp2=this->matrix[this->find_city2(temp1->get_name())];
        for(auto it = temp1->get_adjacent().begin() ; it != temp1->get_adjacent().end(); ++it){
            double temp3=this->distance((*it)->get_name(),temp1->get_name())+temp1->get_distance();
            if((*it)->get_distance()==-1){
                (*it)->set_distance(temp3);
                continue;
            }else{
                if((*it)->get_distance()>temp3){
                    (*it)->set_distance(temp3);
                    (*it)->set_parent(temp1);
                    continue;
                }
            } 
        }
        a.build();
    }
    node *temp3=this->find_city1(name2);
    if(temp3->get_distance()==-1){
        cout<<"failure"<<endl;
    }else{
        vector<node *> temp4;
        while(temp3!=start){
            temp4.push_back(temp3);
            temp3=temp3->get_parent();
        }
        cout<<name1;
        while(temp4.size()!=0){
            cout<<" "<<temp4.back()->get_name();
            temp4.pop_back();
        }
    }
}
void graph::clear(){
    for(auto i = this->matrix.begin() ; i != this->matrix.end(); ++i){
        for(auto j=*i->begin(); j != *i->end(); ++j){
            delete j;
        }
    }
    this->matrix.clear();
    for(auto i = this->cities.begin() ; i != this->cities.end(); ++i){
            delete *i;
    }
    this->cities.clear();
    this->edge_count=0;
    this->node_count=0;
}
graph::~graph(){
    this->clear();
}