#pragma once
#include <iostream>

inline void swap(int& x, int& y) {
	int tem = x;
	x = y;
	y = tem;
}
//不需要实例化
class Sort
{
private:

	Sort();
	Sort(const Sort&) = delete;
	Sort(Sort&&) = delete; //move 不能用const，正常情况下需要将原有指针置空

public:
	static Sort& GetInstance() {
		static Sort Instance;
		return Instance;
	}

	static void bubbleSort(int array[], int length)
	{
		size_t count = 0;
		if (length == 1 || length == 0) {
			std::cout << "冒泡排序交换次数：  " << count << "\n";
			return;
		}
		for (int i = 0; i < length; i++) {
			for (int j = i + 1; j < length; j++) {
				if (array[j] < array[i]) {
					swap(array[j], array[i]);
					count++;
				}
			}
		}
		std::cout << "冒泡排序交换次数：  " << count << "\n";
	}

	static void selectSort(int array[], int len)
	{
		size_t count = 0;
		if (len == 1 || len == 0) {
			std::cout << "选择排序交换次数：  " << count << "\n";
			return;
		}
		for (int i = 0; i < len - 1; i++) {
			int min = i;//the min is index instead of its value
			for (int j = i + 1; j < len; j++) {
				if (array[j] < array[min]) {
					min = j;
				}
			}
			swap(array[min], array[i]);
			count++;
		}
		std::cout << "选择排序交换次数：  " << count << "\n";
	}

	static void insertSort(int array[], int len)
	{
		size_t count = 0;
		if (len == 1 || len == 0) {
			std::cout << "插入排序交换次数：  " << count << "\n";
			return;
		}

		for (int i = 1; i < len; i++) {
			int current = array[i];
			int j = i - 1;

			while (j >= 0 && current < array[j])
			{
				array[j + 1] = array[j];
				count++;
				j--;
			}

			array[j + 1] = current;
			count++;
		}
		std::cout << "插入排序交换次数：  " << count << "\n";
	}

	static void shellSort(int array[], int length)
	{
		size_t count = 0;
		//增量gap，并逐步缩小增量
	//当gap变为1的时候，就是最普通的插入排序
		for (int gap = length / 2; gap > 0; gap /= 2) {
			//从第gap个元素，逐个对其所在组进行直接插入排序操作
			for (int i = gap; i < length; i++) {
				int j = i;
				while (j - gap >= 0 && array[j] < array[j - gap]) {
					//插入排序采用交换法
					swap(array[j], array[j - gap]);
					count++;
					j -= gap;//此处减去gap的操作在一般的插入排序里就是j--的过程
				}
			}
		}
		std::cout << "希尔排序交换次数：  " << count << "\n";
	}

	static void quickSort(int array[], int left, int right)
	{
		static size_t count;//由于递归，使用static
		static int flag = -1;//为了只输出一次交换次数，每次调用该函数自增一次，flag为0则输出
		

		int L = 0, R(0), temp(0);
		if (left > right)
			return;

		temp = array[left]; //temp中存的就是基准数
		L = left;
		R = right;
		while (L != R)//把当前right-left长度的数组完全排好序
		{
			//顺序很重要，要先从右边开始找
			while (array[R] >= temp && L < R)
				R--;
			//再找右边的
			while (array[L] <= temp && L < R)
				L++;
			//交换两个数在数组中的位置
			if (L < R)
			{
				int t = 0;
				t = array[L];
				array[L] = array[R];
				array[R] = t;
				count++;
			}
		}
		//最终将基准数归位
		array[left] = array[L];
		array[L] = temp;

		quickSort(array, left, L - 1);//继续处理左边的，这里是一个递归的过程
		quickSort(array, L + 1, right);//继续处理右边的，这里是一个递归的过程

		flag++;//注意：应该先递归完再自增

		//std::cout << flag << "\n";

		if (flag == 0)
		{
			std::cout << "快速排序交换次数：  " << count << "\n";
		}
	}

	static void heapSort(int array[], int len)
	{
		size_t count = 0;
		// 初始化，建立一个最大堆，从下往上
		for (int i = len / 2 - 1; i >= 0; i--)
			max_heapify(array, i, len - 1); //create a max heap

		//对于一个最大堆，我们唯一能够确定的顺序就是堆顶元素最大arr[0]，因此当我们已经建立好一个最大堆后，通过交换第一个与最后一个，就把最大值排好了位置，之后去掉它，再构建新的最大堆，继续找最大值，循环即可
		// 
		for (int i = len - 1; i > 0; i--) {
			swap(array[0], array[i]); // swap first and last node , now the last node is the biggest
			count++;
			max_heapify(array, 0, i - 1); // create max heap on reduced array, because the i-1 is reduced, so as if we remove the last node
		}

		std::cout << "堆排序交换次数：    " << count << "\n";

	}

	static void mergeSort(int array[], int length)
	{
		int* reg = new int[length];
		merge_sort_recursive(array, reg, 0, length - 1);
		delete[] reg;
	}

	static void radixSort(int array[], int length)
	{
		if (length <= 1) { return; }

		int max = 0;//they represent the index of number

		for (int i = 0; i < length; i++)
		{
			if (array[i] > array[max]) { max = i; }
		}
		//std::cout << "the biggest number: " << array[max] << "\n";

		max = array[max];

		//提取每一位并进行比较，位数不足的高位补0
		for (int exp = 1; max / exp > 0; exp *= 10) {
			countSortForRadix(array, length, exp);
		}
		return;
	}

	//-----------
	static void max_heapify(int arr[], int start, int end) {

		int dad = start;
		int son = dad * 2 + 1;
		while (son <= end) {
			if (son + 1 <= end && arr[son] < arr[son + 1]) // 选择最大的子节点
				son++;
			if (arr[dad] > arr[son])
				return;
			else {
				swap(arr[dad], arr[son]);
				dad = son; //from top to bottom
				son = dad * 2 + 1;
			}
		}
	}

	static void merge_sort_recursive(int arr[], int reg[], int start, int end) {

		static size_t count = 0;
		static int flag = -1;//为了只输出一次交换次数，每次调用该函数自增一次，flag为0则输出
		

		if (start >= end)
			return;
		int len = end - start, mid = (len / 2) + start;
		int start1 = start, end1 = mid;
		int start2 = mid + 1, end2 = end;

		merge_sort_recursive(arr, reg, start1, end1);
		merge_sort_recursive(arr, reg, start2, end2);

		//flag++;
		int k = start;
		while (start1 <= end1 && start2 <= end2) {
			reg[k++] = arr[start1] < arr[start2]
				? arr[start1++] : arr[start2++];
			count++;
		}
			

		while (start1 <= end1) {
			reg[k++] = arr[start1++];
			count++;
		}

		while (start2 <= end2) {
			reg[k++] = arr[start2++];
			count++;
		}

		for (k = start; k <= end; k++)//reg是临时变量存储数据
			arr[k] = reg[k];

		if (flag == 0) {
			std::cout << "归并排序交换次数：  " << count << "\n";
		}
	}

	//专门为基数排序而实现的计数排序，更加方便基数排序，digit 是位权的信息
	static void countSortForRadix(int* array, int length, int digit)
	{
		static size_t count = 0;
		static int flag = -1;
		flag++;

		int min = 0, max = 0;//they represent the index of number

		int* copy = new int[length];
		for (int i = 0; i < length; i++) {
			copy[i] = array[i];
		}

		int countBucket[10]{};
		//按照各位去给桶计数，由于一位最多只有十种情况，从0 - 9，所以只需要开10个元素大小就可以

		for (int i = 0; i < length; i++)
		{
			int index = (array[i] / digit) % 10;//高位自然是0，即达到了较短数字高位补零的目的
			countBucket[index]++;
		}

		for (int i = 1; i < 10; i++) {
			countBucket[i] = countBucket[i] + countBucket[i - 1];
		}

		for (int j = length; j > 0; j--)
		{
			copy[countBucket[(array[j - 1] / digit) % 10] - 1] = array[j - 1];
			count++;
			countBucket[(array[j - 1] / digit) % 10]--;
		}

		for (int i = 0; i < length; i++) {
			array[i] = copy[i];
		}
		if (flag == 0) {
			std::cout << "基数排序交换次数：  " << count << "\n";

		}

		delete[] copy;
	}

};

