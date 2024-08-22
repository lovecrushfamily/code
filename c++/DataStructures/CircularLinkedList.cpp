#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};
class CircularLinkedList
{
public:
    Node *head;
    Node *tail;
    CircularLinkedList():head(nullptr),tail(nullptr){}


    Node * begin(){
        return this -> head;
    }Node * end(){
        return this -> tail;
    }
    void add(int newValue){
        if (this -> head == nullptr && this -> tail ==nullptr){
            Node *first = new Node(newValue);
            this -> head = first;
            this -> tail = first;
        }else{
            Node *newNode = new Node(newValue);
            this -> tail -> next = newNode;
            this -> head -> previous = newNode;
            newNode -> previous = this -> tail;
            newNode -> next = this -> head;
            this -> tail = newNode;
        }

    }
    void printAsc(int loop){
        cout<< "print circular linked list ";
        Node * current = this -> head;
        // int loop = 10;
        while (loop--)
        {
            /* code */
            cout << current -> data << ' ';
            current = current -> next;
        }
        cout << current -> data << '\n';
    }void printDesc(int loop){
        cout<< "print circular linked list ";
        Node * current = this -> tail;
        // int loop = 10;
        while (loop--)
        {
            /* code */
            cout << current -> data << ' ';
            current = current -> previous;
        }
        cout << current -> data << '\n';
    }
    void pop_back(){
        Node * preTail = this -> tail -> previous;
        preTail -> next = this -> head;
        this -> head -> previous = preTail;
        delete this -> tail;
        this -> tail = preTail;
        

    }void pop_front(){
        Node * nextHead = this -> head -> next;
        nextHead -> previous = nullptr;
        delete this -> head;
        this -> head = nextHead;
    }void popAt(int pos){
        Node * current = this -> head;
        while (--pos)
        {
            /* code */
            current = current -> next;
        }
        current -> previous ->next = current -> next;
        current -> next -> previous = current ->previous;
        delete current;
    }bool checkCycle(){
        Node* slow = this -> head;
        Node* fast = this -> head;
        while ( fast != nullptr && fast -> next != nullptr)
        {
            /* code */
            slow = slow -> next;
            fast = fast ->next ->next;
            if (fast == slow){
                return true;
            }
        }
        return false;
        
    }
};
int main()
{
    CircularLinkedList list;
    int size; cin >> size;
    while (size--)
    {
        list.add(size);
    }
    list.printAsc(13);
    list.pop_back();
    list.printAsc(13);
    // cout << "Size: "<<list.size()<<endl;
    // cout << list.checkCycle(); => true

    

    
}   