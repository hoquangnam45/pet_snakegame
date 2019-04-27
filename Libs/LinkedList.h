
#include "LinkedNode.h"
template <class T>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        LinkedNode<T>*& getHead();
        LinkedNode<T>*& getTail();
        void addHead(T& data);
        void addTail(T& data);
        void deleteHead();
        void deleteTail();
        int getSize();
    private:
        LinkedNode<T>* headNode;
        LinkedNode<T>* tailNode;
        int size;
};