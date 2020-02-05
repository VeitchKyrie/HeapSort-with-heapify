// HeapSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

int  input(int *arr) {
	int temp;
	int cnt = 0;
	while (cin >> temp)
	{
		arr[cnt++] = temp;
	}
	return cnt;
}

void printArr(int * arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int *arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void heapify(int *arr, int size, int i) {
	if (i >= size) {
		return;
	}
	int l_child = 2 * i + 1;
	int r_child = 2 * i + 2;
	int max_index = i;
	if (l_child < size && arr[l_child] > arr[max_index]) {
		max_index = l_child;
	}
	if (r_child < size && arr[r_child] > arr[max_index]) {
		max_index = r_child;
	}
	if (max_index != i) {
		swap(arr, max_index, i);
		heapify(arr, size, max_index);
	}
}

void buildHeap(int *arr, int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

void heapSort(int *arr, int size) {
	buildHeap(arr, size);
	for (int i = size - 1; i >= 0; i--) {
		swap(arr, 0, i);
		heapify(arr, i, 0);
	}
}

int main()
{
	int arr[100];
	int size = input(arr);

	heapSort(arr, size);

	printArr(arr, size);
	system("PAUSE");
}
