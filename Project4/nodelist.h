#include "node.h"
class nodelist{//representing a set
    private:
        node *head;
        node *tail;
        node *current;
    public:
        nodelist()=default;
        nodelist(node *a);
        ~nodelist()=default;//accessing private variables
        node *get_head();
        node *get_tail();
        node *get_current();
        void set_head(node *a);
        void set_tail(node *a);
};