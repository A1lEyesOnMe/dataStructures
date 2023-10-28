#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{20,30,10,14,40};
    constexpr int length { static_cast<int>(std::size(array))};

    for(int startIndex {0};startIndex <length -1;++startIndex)
    {
        int smallestIndex{ startIndex };
        for (int currentIndex{ startIndex +1 };currentIndex <length; ++currentIndex)
        {
            if(array[currentIndex] < array[smallestIndex])
                smallestIndex = currentIndex;
        }

        std::swap(array[startIndex],array[smallestIndex]);
    }

    for(auto& n : array )
        std::cout << n << ' ';
}