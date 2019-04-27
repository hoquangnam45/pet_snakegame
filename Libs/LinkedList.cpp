#include "LinkedList.h"
#include "Cell.h"
template <class T> LinkedList<T>::LinkedList(){
    headNode = tailNode = nullptr;
    size = 0;
}

template <class T> LinkedList<T>::~LinkedList(){
    tailNode = nullptr;
    delete tailNode;
    delete headNode;
    size = 0;
}

template <class T> LinkedNode<T>*& LinkedList<T>::getHead(){
    return headNode;
}

template <class T> LinkedNode<T>*& LinkedList<T>::getTail(){
    return tailNode;
};

template <class T> void LinkedList<T>::addHead(T& newData){
    LinkedNode<T> *newNode = new LinkedNode<T>(newData);
    newNode->setNextNode(headNode);
    if(headNode) headNode->setPrevNode(newNode);
    else tailNode = newNode;
    headNode = newNode;
    size++;
}

template <class T> void LinkedList<T>::addTail(T& newData){
    LinkedNode<T> *newNode = new LinkedNode<T>(newData);
    newNode->setPrevNode(tailNode);
    if(tailNode) tailNode->setNextNode(newNode);
    else headNode = newNode;
    tailNode = newNode;
    size++;
}

template <class T> void LinkedList<T>::deleteHead(){
    LinkedNode<T>* tempNode = headNode->getNextNode();
    headNode->setNextNode(nullptr);
    delete headNode;
    headNode = tempNode;
    size--;
}

template <class T> void LinkedList<T>::deleteTail(){
    LinkedNode<T>* tempNode = tailNode->getPrevNode();
    tempNode->setNextNode(nullptr);
    delete tailNode;
    tailNode = tempNode;
    size--;
}

template <class T> int LinkedList<T>::getSize(){
    return size;
}

template class LinkedList<int>;
template class LinkedList<Cell>;
