#include "set.h"
#include "edge.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Bingjian Du 20706578
class illegal_argument{};
class graph{ //this is a graph
    private:
        vector<vector<edge>> matrix;
        int size;
        int edge_count;
    public:
        void set_size(int m); //function name consistent with commands
        int get_size();
        void print_ecount();
        graph();
        ~graph()=default;
        void insert(int u,int v,double w);
        void del(int u,int v);//delete
        void degree(int u);
        void clear();
        void mst();
};