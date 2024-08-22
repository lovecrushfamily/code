#include <iostream>
#include <cmath>
#include <list>
using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template<typename T>
class SinglyLinkedList{
public:
    Node<T> *head;
    Node<T> *tail;

    SinglyLinkedList() : head(nullptr), tail(nullptr) {}
    
    Node<T>* begin(){
        return this->head;
    }

    void add(T value){
        if (this->head == nullptr){
            Node<T> *first = new Node<T>(value);
            this->head = first;
            this->tail = first;
        }else{
            Node<T> *newNode = new Node<T>(value);
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void print(){
        cout << "Printing singly linked list: ";
        Node<T> *current = this->head;
        while (current != nullptr){
            cout << current->data << ' ';
            current = current->next;
        }
        cout << '\n';
    }
};

int main(){
    SinglyLinkedList<int> myList;
    // myList.add(1);
    // myList.add(2);
    // myList.add(3);
    // myList.print();

    SinglyLinkedList<string> myStringList;
    myStringList.add("Hello");
    myStringList.add("World");
    myStringList.add("!");
    myStringList.print();

    return 0;
}