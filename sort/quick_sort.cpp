#include <iostream>
#include <vector>

// 分区函数，将数组划分为两部分，返回划分点索引
template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];  // 选择最后一个元素作为枢轴
    int i = low - 1;  // 初始化较小元素的索引

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序函数
template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);  // 获取划分点索引

        // 递归对划分后的两部分进行排序
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};

    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
