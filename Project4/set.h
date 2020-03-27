#include "node.h"
#include <vector>
using namespace std;//Bingjian Du 20706578
class set{
    private:
        vector<node> theSet;
    public:
        set()=default;
        ~set()=default;
        void makeset(int num);
        node *findset(int num);
        void merge(int a, int b);
};