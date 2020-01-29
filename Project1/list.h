class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int i);
    ~Node()=default;
};
class linked_list{
    private:
    Node *head,*tail;
    int length;
    class deque_empty{};
    public:
    linked_list();
    ~linked_list();
    void enqueue_front(int i);
    void enqueue_back(int i);
    void dequeue_front();
    void dequeue_back();
    void front(int i);
    void back(int i);
    void empty();
    void size();
    void print();
};