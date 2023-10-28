#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(T value)
    {   
        Node<T>* newNode = new Node<T>(value);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void prepend(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void remove(T value)
    {
        Node<T>* current = head;
        while(current != nullptr)
        {
            if(current->data == value)
            {
                if(current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }else{
                    head = current->next;
                }
                if(current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }else{
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void print()
    {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            current = current->next;
        }
        std::cout << "\n";
    }
};