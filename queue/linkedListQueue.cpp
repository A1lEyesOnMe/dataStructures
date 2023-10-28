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
class Queue
{
private:
    Node<T>* front {};
    Node<T>* rear {};

public:
    
    bool isEmpty() {
        return front == nullptr;
    }

    void enQueue(T& value) {
        New<T>* newNode { new Node<T>(value)}

        if(isEmpty())
        {
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deQueue() {
        if(isEmpty())
        {
            std::cout <<"Empty" <<'\n';
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
    }
    T getFront() {
        if(isEmpty())
        {
            std::cout <<"Empty" <<'\n';
            return T();
        }
        return front->data;
    }
};

int main()
{

}