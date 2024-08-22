#include <iostream>
#include <cmath>
#include<list>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    // Node *previous;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        // this->previous = nullptr;
    }
};
class SinglyLinkedList{
    public:
    Node * head;
    Node* tail;
    SinglyLinkedList() : head(nullptr){}
    
    Node* begin(){
        return this -> head;
    }
    void add(int value){
        if (this -> head == nullptr){
            Node * first = new Node(value);
            this -> head = first;
            this -> tail = first;
        }else{
            Node * newNode = new  Node(value);
            this -> tail -> next = newNode;
            this -> tail = newNode;
        }
    }
    void print(){
        cout<< "print double linked list ";
        Node * current = this -> head;
        while (current ->next != nullptr)
        {
            /* code */
            cout << current -> data << ' ';
            current = current -> next;
        }
        cout << current -> data << '\n';
    }
    /**
     * The function reverses the order of a linked list.
     */
    void reverseRecursive(){
        reverseRecursive(this -> head);
    }
    
    /**
     * The reverseRecursive function reverses a linked list using recursion.
     * 
     * @param current A pointer to the current node in the linked list.
     */
    void  reverseRecursive(Node * current){
        if (!current -> next){
            this -> head = current;
            return;
        }
        reverseRecursive(current -> next);
        current -> next -> next = current;
        current -> next = nullptr;
        // return nextNode;
    }
    void reverseList(){
        Node * current = this -> head ->next;
        Node * next ;
        Node * prev = nullptr;
        // int i = 4;
        while (current != nullptr)
        {
            /* code */
            next = current -> next;
            current -> next = prev;
            prev = current;
            this -> head = current;
            current = next;
        }

    }
    void reverseSubList(){
        Node* current = this -> head;
        int start = 2;
        int timesReverse = 4;
        while (--start)
        {
            /* code */
            current = current -> next;
        }
        Node * beforeStart = current;
        cout << "current data: "<<current -> data <<'\n';
        Node * temp = current -> next;
        cout << "temp data: " << temp ->data << '\n'    ;
        Node * next;
        Node * prev = nullptr;
        while (timesReverse--)
        {
            /* code */
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next; 
        }

        cout <<"current data: " <<current -> data<< '\n';
        cout << "prev data: "<< prev -> data << '\n';
        temp -> next = current;
        beforeStart -> next = prev;
    }
    int recursionLen(){
        Node * current = this -> head;
        return recursionLen(current);
    }
    int recursionLen(Node * current){
        if (current -> next == nullptr){
            return 1;
        }else {
            return 1 + recursionLen(current -> next) * 2;
        }
    }int len(){
        Node * current = this -> head;
        int i = 0;
        while(current != nullptr){
            i = pow(i, 2);
            current = current -> next;
        }

        // cout << i << '\n';
        return i;
    }
    void filterElement(){
        Node * current  = this -> head;
        Node * temp;
        while (current -> next != nullptr)
        {
            /* code */
            if (current -> next ->data == current -> data){
                temp = current -> next -> next;
                // free(current -> next);
                current -> next = temp;
                // delete temp;
            }else{
                current = current -> next;
            }
        }
    }
    void mergeTwoList(Node *  list2){
        this -> head = mergeTwoList(this -> head, list2);
    }
    Node* mergeTwoList(Node* list1, Node* list2){
        if (list1 -> data <= list2 -> data){
            Node * head = list1 ;
        }else{
            Node * head = list2;
        }
        Node * temp ;
        while (list1 != nullptr || list2 != nullptr)    {
            if (list1 -> data <= list2 -> data){
                temp = list1 -> next;
                list1 -> next = list2;
                list1 = temp;
            }else{
                temp = list2 -> next;
                list2 -> next = list1;
                list2 = temp;
            }
        }   
        return head;
    }
};

int main()
{
    
    

}   