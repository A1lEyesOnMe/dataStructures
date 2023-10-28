#include <iostream>

class String
{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String(const char* string)
    {
        m_size = strlen(string);
        m_buffer =new char[m_size+1];
        memcpy(m_buffer,string,m_size);

        // for(int i =0;i<m_size;i++)
        //     m_buffer[i] = string[i]; 
    }

    String(const String& other)
        :m_size(other.m_size)
    {
        // memcpy(this,&other,sizeof(String))
        m_buffer = new char [m_size+1];
        memcpy(m_buffer,other.m_buffer,m_size+1);
    }
    

    ~String(){
        delete[] m_buffer;
    }

    char& operator[](unsigned int index){
        return m_buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_buffer;
    return stream;
}

void printString(const String& string){
    
    std::cout << string <<std::endl;
}

int main()
{
    String string("hello");
    String second = string;

    second[1] = 'a';

    printString(string);
    printString(second);
    std::cin.get();
}