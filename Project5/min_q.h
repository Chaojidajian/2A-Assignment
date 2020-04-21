#include <vector>
#include "edge.h"
using namespace std;
class min_q{
    private:
        vector<node *> vertices;
    public:
        min_q(vector<node *> vertices);
        ~min_q()=default;
        void heapify(int i);  //heapify a point with index
        void build();  //for initialization
        void del(int i); //delete a point
        vector<node *> get_q();
        node *extractMin(); //extract a point from the top of queue and return its pointer
};