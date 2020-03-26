class node{
    private:
        int vertex;
        node *next;
        node *head;
    public:
        node()=default;
        ~node()=default;
        node(int vertex);
        int get_vertex();
        node *get_next();
        node *get_head();
        void set_next(node *a);
        void set_head(node *a);
        bool operator==(const node &a);
};