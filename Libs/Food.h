class Food{
    public:
        Food();
        ~Food();
        int generatePosition(int numberOfPlayableCell, int snakeLength);
        // Coordinate& getPosition();
    private:
        const int p_foodAppear = 100;
};