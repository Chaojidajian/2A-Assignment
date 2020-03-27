//Bingjian Du 20706578
class edge{
    private:
        double weight;
        int x,y;
    public:
        edge();
        edge(double w,int u, int v);
        int get_x();
        int get_y();
        double get_weight();
};