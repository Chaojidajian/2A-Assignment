#include "user.h"
class chain{
    private:
    user *head,*tail;
    public: 
    void set_head(user *n);
    void set_tail(user *n);
    user *get_head();
    user *get_tail();
    chain();
    ~chain();
};