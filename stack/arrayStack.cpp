#include <iostream>
#include <array>
#include <stdexcept>

template<typename T,std::size_t size>
class Stack
{
private:
    std::array<T,size> m_data;
    std::size_t m_size;

public:
    Stack() :m_size(0) {};

    void push(const T& value) {
        if(m_size == size)
            throw std::overflow_error("Stack overflow");
        m_data[m_size++] =value;
    }

    void pop()
    {
        if(m_size == 0)
            throw std::underflow_error("Stack underflow");
        --m_size;
    }

    T& top()
    {
        if(m_size == 0)
            throw std::underflow_error("Stack is empty");
        return m_data[m_size-1];
    }

    bool isEmpty()
    {
        return m_size ==0;
    }

    std::size_t getSize() const
    {
        return m_size;
    }
};


int main()
{
    try
    {
        Stack<int,5> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << stack.top() <<'\n';
        std::cout << stack.getSize() << '\n';


        stack.pop();

        std::cout << "Top element after pop: " << stack.top() << std::endl;
        std::cout << "Stack size after pop: " << stack.getSize() << std::endl;

        while (!stack.isEmpty()) {
            stack.pop();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
}