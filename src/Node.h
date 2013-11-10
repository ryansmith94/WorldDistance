#ifndef Node_H
#define Node_H

template <class T>
class Node{
    private:
        T *data;
        Node *next;
    public:
        Node(T*,Node*);
        Node(T*);
        Node();
        ~Node();
        Node* getNext();
        void setNext(Node*);
        T* getData();
        void setData(T*);
};

#endif