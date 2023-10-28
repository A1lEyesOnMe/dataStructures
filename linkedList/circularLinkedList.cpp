#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value) : data(value),next(nullptr) {}
};

template <typename T>
class CircularLinkList
{
private:
    Node<T>* head;
public:
    CircularLinkList() :head(nullptr) {}

void insert(T value)
{
    Node<T>* newNode = new Node<T>(value);
    if(!head)
    {
        head = newNode;
        head->next = head;
    }else{
        Node<T>* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void print()
{
    if(!head)
    {
        return;
    }
    Node<T>* temp = head;
    do{
        std::cout << temp->data << ' ';
        temp = temp->next;
    }while(temp != head);

    std::cout << '\n';
}
};

int main()
{
    CircularLinkList<int> cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.print();
}