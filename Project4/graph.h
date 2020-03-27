#include "set.h"
#include "edge.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Bingjian Du 20706578
class graph{
    private:
        vector<vector<edge>> matrix;
        int size;
        class illegal_argument{};
        int edge_count;
    public:
        void set_size(int m);
        int get_size();
        void print_ecount();
        graph();
        void insert(int u,int v,double w);
        void del(int u,int v);
        void degree(int u);
        void clear();
        void mst();
};