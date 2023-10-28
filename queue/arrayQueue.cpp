#include <iostream>

static const int MAX_SIZE {10};


class Queue
{
private:
    int array[MAX_SIZE];
    int front{};
    int rear{};

public:
    Queue() : front(-1),rear(-1) {}

    bool isEmpty(){
        return front == -1 && rear == -1;
    }
    bool isFull(){
        return (rear+1) % MAX_SIZE == front;
    }

    void enQueue(int value){
        if(isFull())
        {
            std::cout << "Full"<<'\n';
            return;
        }

        if(isEmpty())
        {
            front = rear = 0;
        }else{
            rear= (rear+1) % MAX_SIZE;
        }
        array[rear] = value;
    }

    void deQueue(){
        if(isEmpty())
        {
            std::cout << "Empty"<<'\n';
            return;
        }
        if(rear == front)
        {
            front = rear = -1;
        }else{
            front = (front + 1) % MAX_SIZE;
        }

    }

    int getFront(){
        if(isEmpty())
        {
            std::cout << "Empty"<<'\n';
            return -1;
        }
        return array[front];
    }
};


int main() {
    Queue queue;

    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);

     // 获取队头元素并出队
    std::cout << "Front element: " << queue.getFront() << std::endl;
    queue.deQueue();

    // 再次获取队头元素
    std::cout << "Front element: " << queue.getFront() << std::endl;

}