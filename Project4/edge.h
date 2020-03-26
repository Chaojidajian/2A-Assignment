class edge{
    private:
        double weight;
        int x,y;
    public:
        edge();
        edge(double w,int u, int v);
        double get_weight();
        bool operator<(const edge &a);
};