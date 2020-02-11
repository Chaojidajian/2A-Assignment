#include "chain.h"
#include <vector>
using namespace std;
class chain_table{
    private:
        vector<chain> data;
        int m;
    public:
        chain_table();
        ~chain_table();
        vector<chain> get_data();
        void define(int m);
        void insert(string number,string name);
        int search(string number);
        int delete_data(string number);
        void print(string i);
};