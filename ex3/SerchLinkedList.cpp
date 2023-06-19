//
// Created by omerl
//

#include "SerchLinkedList.h"

SerchLinkedList::Node::Node(CVirus *data, SerchLinkedList::Node *next) {
    this->data = data;
    this->next = next;
}

SerchLinkedList::SerchLinkedList() {
    this->head = nullptr;
    this->count = 0;
}


SerchLinkedList::SerchLinkedList(const SerchLinkedList &other) {
    this->head = nullptr;
    this->count = 0;
    Node* temp = other.head;
    while(temp) {
        add(temp->data);
        temp = temp->next;
    }
}

SerchLinkedList::~SerchLinkedList() {
    clear();
}

SerchLinkedList &SerchLinkedList::operator=(const SerchLinkedList &other) {
    if(this == &other) {
        return *this;
    }
    clear();
    Node* temp = other.head;
    while(temp) {
        add(temp->data);
        temp = temp->next;
    }
    return *this;
}

void SerchLinkedList::operator++(int t) {
    auto* v = new CVirus(*this->get(0));
    this->get(0)->incrementId();
    v->setVersion(*this->get(0)->getId());
    this->remove(this->get(this->size()-1));
    v->setErrors(v->errorsCalc());
    this->add(v);
}

void SerchLinkedList::add(CVirus *v) {
    Node* current;
    if(head == nullptr || head->data->getErrors() > v->getErrors()) {
        head = new Node(v, head);
    }
    else {
        current = head;
        while(current->next && current->next->data->getErrors() <= v->getErrors()) {
            current = current->next;
        }
        Node* new_node = new Node(v, current->next);
        current->next = new_node;
    }
    count++;
}

bool SerchLinkedList::remove(CVirus *v) {
    if(isEmpty()) {
        return false;
    }
    Node* temp = head;
    if(temp->data->compareTo(v)) {
        head = head->next;
        delete temp;
        count--;
        return true;
    }
    while(temp->next && !temp->next->data->compareTo(v)) {
        temp = temp->next;
    }
    if(temp->next) {
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        count--;
        return true;
    }
    return false;
}

CVirus *SerchLinkedList::get(int index) {
    if (index < 0 || index >= count) {
        std::cerr << "Invalid index" << std::endl;
        exit(-1);
    }
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

int SerchLinkedList::size() const {
    return count;
}

void SerchLinkedList::clear() {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    count = 0;
    head = nullptr;
}

bool SerchLinkedList::isEmpty() const {
    if(count == 0) {
        return true;
    }
    return false;
}

void SerchLinkedList::print() {
    Node* temp = head;
    int size = temp->data->getDim();
    while(temp) {
        std::cout << temp->data->getName();
        if(temp->data->getVersion() != 0) {
            std::cout << "_" + std::to_string(temp->data->getVersion());
        }
        std::cout << "\t";
        int* arr = temp->data->getValues();
        for(int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        temp = temp->next;
    }

}
