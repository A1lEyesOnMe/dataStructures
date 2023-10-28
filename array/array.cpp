#include <iostream>

template<typename T>
class ArrayList
{
private:
    T* elements;
    size_t capacity;
    size_t length;

public:
    ArrayList(size_t initialCapacity = 10)
        :capacity(initialCapacity),
         length(0)
    {
        elements = new T[capacity];
    }

    ~ArrayList()
    {
        delete[] elements;
    }

    void insert(T value)
    {
        if(length == capacity)
        {
            resize();
        }
        elements[length++] = value;
    }

    size_t size() const {
        return length;
    }

    T get(size_T index) const {
        if(index <length)
        {
            return elements[index];
        }else{
            return T();
        }
    }

    void display() const {
        for(size_t i = 0; i < length; ++i)
            std::cout << elements[i];
        std::cout << '\n';
    }

private:
    void resize()
    {
        T* newElements = new T[capacity];

        memcpy(newElements,elements,capacity*=2);

        delete[] elements;
        elements = newElements;
    }
    
};

int main()
{
    ArrayList<int> arrayList;

    arrayList.insert(1);
    arrayList.insert(2);
    arrayList.insert(3);

    std::cout << "ArrayList: ";
    arrayList.display();

    std::cout << "Size: " << arrayList.size() << "\n";
    std::cout << "Element at index 1: " << arrayList.get(1) << "\n";

    return 0;
}