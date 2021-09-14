#include<stdio.h>

#include<iostream>
using namespace std;

///////////////////////////////////////////////
/////////////////最简单的排序//////////////////

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

////////////////////////////////////////////////
/////////////////最常用的排序///////////////////

////运用了递归的思想，即在函数中调用该函数本身
////时间复杂度是O(Nlog_2N) 

void swap(int* x, int* y) { //// 此时传来的是x和y的地址，若传来值，则x和y的值
    int t = *x;				//// 仅在swap函数作用域内生效，在其他作用域中不发
    *x = *y;				//// 生改变。不理解就硬背这个地方，或者不选择调用
    *y = t;					//// 函数，在需要交换的地方直接交换（但不优雅）。
}
void quick_sort_recursive(int a[], int start, int end) {
    if (start >= end)
        return;
    int mid = a[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (a[left] < mid && left < right)
            left++;
        while (a[right] >= mid && left < right)
            right--;
        swap(&a[left], &a[right]);  //// 前有 & 表示传入的是地址
    }
    if (a[left] >= a[end])
        swap(&a[left], &a[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(a, start, left - 1);
    quick_sort_recursive(a, left + 1, end);
}
void quickSort(int a[], int n) {
    quick_sort_recursive(a, 0, n - 1);
}
////////////////////////////////////////////////

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int tmp = a[min];
            a[min] = a[i];
            a[i] = tmp;
        }
    }
}

///////////////////////////////////////////////

void insertionSort(int a[], int n) {
    int tmp,j;
    for (int i = 0; i < n; ++i)
    {
        tmp = a[i];
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

///////////////////////////////////////////////

void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
void mergeSort(int arr[], const int len) {
    int* reg = new int[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

///////////////////////////////////////////////

void shellSort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}

///////////////////////////////////////////////

int main() {
    int a[] = {4, 7, 6, 5, 3, 8, 2, 9, 1}; // 1 2 3 4 5 6 7 8 9
    int len = sizeof(a)/sizeof(a[0]);

    //bubbleSort(a, len);  // 冒泡排序
    //quickSort(a, len);  // 快速排序
    //selectionSort(a, len);  // 选择排序
    //insertionSort(a, len);  // 插入排序
    //mergeSort(a, len);  // 并归排序
    //shellSort(a, len);  //希尔排序
    
    for (int i = 0; i < len; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
