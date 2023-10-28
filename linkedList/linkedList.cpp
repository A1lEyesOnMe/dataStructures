#include <iostream>


template<typename T>
class Node
{
public:
    T data;
    Node* next;

    Node(T value) : data(value),next(nullptr) {}
};

template<typename T>
class LinkedList
{
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList(){
        clear();
    }

    void prepend(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void remove(T value)
    {
        if(head == nullptr)
        {
            return;
        }

        if(head->data == value)
        {
            Node<T>* temp = head;
            head = head->data;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while(current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if(current->next != nullptr)
        {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
    void display()
    {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
    
};