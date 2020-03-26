#include "node.h"
#include <vector>
class set{
    private:
        vector<node> theSet;
    public:
        set()=default;
        ~set()=default;
        void makeset(node a[],int size);
        node findset(node a);
        void merge(node a, node b);
};