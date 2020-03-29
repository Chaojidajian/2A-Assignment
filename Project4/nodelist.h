#include "node.h"
class nodelist{
    private:
        node *head;
        node *current;
        node *tail;
    public:
        nodelist()=default;
        nodelist(node *a);
        ~nodelist()=default;
        node *get_current();
        node *get_head();
        node *get_tail();
        void set_head(node *a);
        void set_tail(node *a);
};