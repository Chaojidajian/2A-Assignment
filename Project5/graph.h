#include "min_q.h"
#include <vector>
#include <iostream>
using namespace std;
//Bingjian Du 20706578
class graph{ //this is a graph
    private:
        vector<vector<edge*>> matrix;
        vector<node *> cities;
        int node_count;
        int edge_count;
    public:
        graph();
        ~graph()=default;
        void insert(string name);
        void setd(string name1,string name2, double distance);
        bool search(string name);//delete
        void degree(string name);
        void graph_nodes();
        void graph_edges();
        double distance(string name1,string name2);
        void shortest_d(string name1,string name2);
        void print_path(string name1,string name2);
        node* find_city1(string name); //return obj
        int find_city2(string name); //return index
        void clear();
        void init_vertex();
};