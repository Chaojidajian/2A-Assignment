#include "set.h"
#include "edge.h"
#include <vector>
using namespace std;
class graph{
    private:
        vector<vector<edge>> matrix;
        int size;
        class illegal_argument{};
        int edge_count;
    public:
        void set_size(int m);
        int get_size();
        graph();
        void insert(int u,int v,double w);
        void del(int u,int v);
        void degree(int u);
        void clear();
        void mst();
};