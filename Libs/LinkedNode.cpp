#include "LinkedNode.h"
#include "Cell.h"
#include<iostream>
template<class T> LinkedNode<T>::LinkedNode(){
    nextNode = prevNode = nullptr;
};

template<class T> LinkedNode<T>::LinkedNode(T& newData){
    data = newData;
    nextNode = prevNode = nullptr;
}

template<class T> LinkedNode<T>::~LinkedNode(){
    if (nextNode){
        delete nextNode;
        nextNode = nullptr;
    }
}

template<class T> T& LinkedNode<T>::getData(){
    return data;
}

template<class T> LinkedNode<T>*& LinkedNode<T>::getNextNode(){
    return nextNode;
}

template<class T> LinkedNode<T>*& LinkedNode<T>::getPrevNode(){
    return prevNode;
}

template<class T> void LinkedNode<T>::setData(T& data){
    this->data = data;
}

template<class T> void LinkedNode<T>::setNextNode(LinkedNode<T>* node){
    nextNode = node;
}

template<class T> void LinkedNode<T>::setPrevNode(LinkedNode<T>* node){
    prevNode = node;
}
template class LinkedNode<int>;
template class LinkedNode<Cell>;