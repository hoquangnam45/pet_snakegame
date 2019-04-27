class Size{
    public:
        Size();
        ~Size();
        Size(int x, int y);
        Size& operator = (const Size& b);
        int getX();
        int getY();
        int flattenSize();
    private:
        int x, y;
};