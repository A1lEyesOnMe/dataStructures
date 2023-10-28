#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

// 检查数组是否有序
bool isSorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

// 随机打乱数组
void shuffle(std::vector<int>& arr) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
}

// 猴子排序
void bogoSort(std::vector<int>& arr) {
    auto startTime = std::chrono::high_resolution_clock::now();

    while (!isSorted(arr)) {
        shuffle(arr);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    std::cout << "Sorting took " << duration.count() << " milliseconds." << std::endl;
}

int main() {
    // 初始化数组
    std::vector<int> myArray = {5, 2, 9, 1, 5, 6};
    
    // 输出原始数组
    std::cout << "Original Array: ";
    for (int num : myArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 应用猴子排序
    bogoSort(myArray);

    // 输出排序后的数组
    std::cout << "Sorted Array: ";
    for (int num : myArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
