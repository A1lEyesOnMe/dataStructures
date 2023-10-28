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
class linkedListStack{
private:
    Node<T>* top;
public:
    linkedListStack() :top(nullptr) {}
    ~linkedListStack() 
    {
        while(!isEmpty())
            pop();
    }
    
    bool isEmpty() const {
        return top == nullptr;
    }

    void push(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(!isEmpty())
        {
            Node<T>* temp =top;
            top = top->next;
            delete temp;
        }else{
            std::cerr <<"Error: Stack is empty. Cannot pop from an empty stack." << std::endl;
        }
    }

    T peek() const {
        if(!isEmpty())
        {
            return top->data;
        }else{
            std::cerr << "Error: Stack is empty. Cannot peek an empty stack." << std::endl;
            return T();
        }
    }
};


int main()
{
    linkedListStack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    // 出栈并打印
    while (!intStack.isEmpty()) {
        std::cout << intStack.peek() << " ";
        intStack.pop();
    }

}