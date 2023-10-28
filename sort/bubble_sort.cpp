#include <iostream>
#include <array>

void bubble_sort(int* arr,int length)
{
    
    for(int i =0; i < length - 1; i++)
    {
        int flag = 0;
        for(int j = 0; j < length -1 - i ;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}


int main()
{
    int arr[] = {42,2431,214,513,314,12,6,4,74,34};
    
    for(auto& a : arr)
    {
        std::cout << a <<std::endl;
    }

    std::cout << "------------------------------------\n"; 

    constexpr int length = sizeof(arr) / sizeof(int);
    bubble_sort(arr,length);
    
    for(auto& a : arr)
    {
        std::cout << a <<std::endl;
    }

}

