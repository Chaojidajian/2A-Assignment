#include "node.h"
class nodelist{//representing a set
    private:
        node *head;
        node *tail;
    public:
        nodelist()=default;
        nodelist(node *a);
        ~nodelist()=default;//accessing private variables
        node *get_head();
        node *get_tail();
        void set_head(node *a);
        void set_tail(node *a);
};