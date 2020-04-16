#include <vector>
#include "edge.h"
using namespace std;
class min_q{
    private:
        vector<node *> vertices;
    public:
        min_q(vector<node *> vertices);
        ~min_q();
        void swap(node *a,node *b);
        void heapify(int i);
        void build();
        void del(int i);
        vector<node *> get_q();
        node *extractMin();
};