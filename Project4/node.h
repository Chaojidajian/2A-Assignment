//Bingjian Du 20706578
class node{//representing a vertex
    private:
        int vertex;
        node *next;
    public:
        node()=default;
        ~node()=default;
        node(int vertex);
        int get_vertex();//accessing private variables
        node *get_next();
        void set_next(node *a);
        bool operator==(const node &a);
        bool operator!=(const node &a);
};