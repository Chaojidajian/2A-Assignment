#include "set.h"
#include "edge.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Bingjian Du 20706578
class graph{ //this is a graph
    private:
        vector<vector<edge>> matrix;
        int size;
        class illegal_argument{};
        int edge_count;
    public:
        void set_size(int m); //function name consistent with commands
        int get_size();
        void print_ecount();
        graph();
        ~graph();
        void insert(int u,int v,double w);
        void del(int u,int v);//delete
        void degree(int u);
        void clear();
        void mst();
};