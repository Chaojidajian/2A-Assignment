#include "chain.h"
#include <vector>
using namespace std;
class chain_table{
    private:
        vector<chain> data;
        long long m;
    public:
        chain_table();
        ~chain_table();
        vector<chain> get_data();
        void define(string k);
        void insert(string number,string name);
        bool search(string number);
        int delete_data(string number);
        void print(string i);
        long long get_size();
};