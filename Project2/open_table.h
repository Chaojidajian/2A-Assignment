#include "user.h"
#include <vector>
using namespace std;
class open_table{
    private:
        vector<user> data;
        long long m;
        long long exists;
    public:
        open_table()=default;
        ~open_table();
        vector<user> get_data();
        void define(string k);
        int insert(string number,string name);
        int search(string number);
        int delete_data(string number);
};