template <class T> 
class LinkedNode{
    public:
        LinkedNode();
        LinkedNode(T&);
        ~LinkedNode();
        T& getData();
        LinkedNode<T>*& getNextNode();
        LinkedNode<T>*& getPrevNode();
        void setData(T& data);
        void setNextNode(LinkedNode<T>*);
        void setPrevNode(LinkedNode<T>*);
    private:
        T data;
        LinkedNode<T> *nextNode, *prevNode;
};