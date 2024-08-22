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
class DoubleLinkedList
{
public:
    Node *head;
    Node *tail;
    DoubleLinkedList():head(nullptr),tail(nullptr){}

    int front(){
        return this -> head -> data;
    }
    int back(){
        return this -> tail -> data;
    }
    Node * begin(){
        return this -> head;
    }Node * end(){
        return this -> tail;
    }
    void push_front(int newValue){
        if (this -> head == nullptr && this -> tail ==nullptr){
            Node *first = new Node(newValue);
            this -> head = first;
            this -> tail = first;
        }else{
            Node * newNode = new Node(newValue);
            this -> head -> previous = newNode;
            newNode -> next = this -> head;
            this -> head = newNode;
        }
    }
    void push_back(int newValue){
        if (this -> head == nullptr && this -> tail ==nullptr){
            Node *first = new Node(newValue);
            this -> head = first;
            this -> tail = first;      
        }else{
        // cout << "push back" <<'\n';
            Node * newNode = new Node(newValue);
            this -> tail -> next = newNode;
            newNode -> previous = this -> tail ;
            this -> tail = newNode;}
    }void print(){
        cout<< "print double linked list ";
        Node * current = this -> head;
        while (current ->next != nullptr)
        {
            /* code */
            cout << current -> data << ' ';
            current = current -> next;
        }
        cout << current -> data << '\n';
    }void addAt(int pos, int value){
        Node * newNode = new Node(value);
        Node * current = this -> head;
        while (--pos)
        {
            /* code */
            current = current -> next;
        }
        newNode ->previous = current;
        newNode ->next = current -> next;
        current -> next = newNode;
        current ->next ->previous = newNode;
    }void pop_back(){
        Node * preTail = this -> tail ->previous;
        preTail -> next = nullptr;
        delete this -> tail;
        this -> tail = preTail;
    }void pop_front(){
        Node * nextHead = this -> head -> next;
        nextHead -> previous = nullptr;
        delete this -> head;
        this -> head = nextHead;
    }
    void remove(Node * cur){
        // Node * one = 
        cout << "I'm here ";
        cur -> next -> previous = cur ->previous;
        cur -> previous -> next = cur -> next;
        delete cur;
        cout << "i'm done";
    }
    void removeAt(int pos){
        Node * current = this -> head;
        while (--pos)
        {
            /* code */
            current = current -> next;
        }
        current -> previous ->next = current -> next;
        current -> next -> previous = current ->previous;
        delete current;
    }int middleValue(){
        Node* slow = this -> head;
        Node* fast = this -> head;
        while (fast != nullptr && fast -> next != nullptr)  
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow -> data;
    }void filterElement(){
        Node * current  = this -> head;
        Node * temp;
        while (current -> next != nullptr)
        {
            /* code */
            if (current -> next ->data == current -> data){
                temp = current -> next -> next;
                free(current -> next);
                current -> next = temp;
                // delete temp;
            
            }else{
                current = current -> next;
            }
        }
        
    }Node * reverseList(){
        Node * current = this -> head;
        Node * pre = nullptr;
        // Node * temp ;
        while (current != nullptr)
        {
            /* code */
            Node * temp = current -> next;
            current -> next = pre;
            pre = current;
            current = temp;  

        }
        return pre;
        

    }
    void mergeTwoList(Node* list1,Node* list2){
        Node* temp;
        if (list1 -> data > list2 -> data){
            temp = list1;
            list1 = list2;
            list2 = temp;

        }
        Node* head = list1;
        while(list1 != nullptr && list2 != nullptr){
            if (list1 -> data <= list2 ->data &&  list2 ->data <= list1 ->next -> data){
                temp = list2 -> next;
                list2 -> next = list1 -> next;
                list1 -> next = list2;
                list1 = list2;
                list2 = temp;
            }else{
                list1 = list1 -> next;
            }
        }
        // list1 -> next = temp;
        this -> head = head;

    }
};
int main()
{
    DoubleLinkedList list1;
    DoubleLinkedList list2;
    // list1.push_back(1);
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(9);
    // list1.push_back(7);
    list1.push_back(10);
    list1.push_back(10);
    list1.push_back(10);
    list2.push_back(2);
    list2.push_back(2);
    list2.push_back(4);
    list2.push_back(6);
    list2.push_back(6);
    list2.push_back(8);
    list2.push_back(7);
    list2.push_back(10);

    list1.print();
    list2.print();
    list1.mergeTwoList(list1.begin(),list2.begin());
    list1.print();

}