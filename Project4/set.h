#include "nodelist.h"
#include <vector>
using namespace std;//Bingjian Du 20706578
class set{ //representing a universe set
    private:
        vector<nodelist> theSet;
    public:
        set()=default;
        ~set();
        void makeset(int num); //consistent with lecture notes
        node *findset(int num);
        void merge(int a, int b);
};