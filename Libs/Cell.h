enum cellType{
    WALL,
    FOOD,
    EMPTY,
    SNAKE,
};
class Cell{
    public:
        Cell();
        Cell(cellType);
        ~Cell();
        void setType(enum cellType type);
        cellType& getType();
        void setRowCol(int, int);
        void setRow(int);
        void setCol(int);
        int getRow();
        int getCol();
        Cell& operator= (const Cell&);
    private:
        int row, col;
        cellType type;
};