//
// Created by omerl
//

#ifndef HW4_SERCHLINKEDLIST_H
#define HW4_SERCHLINKEDLIST_H


#include "CVirus.h"

class SerchLinkedList {

public:
    SerchLinkedList();
    SerchLinkedList(const SerchLinkedList& other);
    SerchLinkedList& operator=(const SerchLinkedList& other);
    ~SerchLinkedList();
    void operator++(int t);
    void add(CVirus* v);
    bool remove(CVirus* v);
    CVirus* get(int index);
    int size() const;
    void clear();
    bool isEmpty() const;
    void print();


private:
    struct Node {
        CVirus* data;
        Node* next;
        Node(CVirus* data, Node* next);
    };
    Node* head;
    int count;

};

#endif //HW4_SERCHLINKEDLIST_H
