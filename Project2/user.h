#include <string>
using namespace std;
class user{
    private:
    string number;
    string caller;
    user *next_caller;
    user *prev_caller;
    public:
    user(string number, string name);
    user();
    ~user();
    string get_number();
    string get_caller();
    void set_number(string number);
    void set_caller(string caller);
    void set_next(user *n);
    void set_prev(user *n);
    user *get_next();
    user *get_prev();
    bool operator==(const user &a);
    bool operator!=(const user &a);
};