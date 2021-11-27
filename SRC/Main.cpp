#include <iostream>
#include "Sort.h"
#include "Timer.h"

#define DEBUG 0
//check if the number is positive
bool check(int& number);

int main()
{

	using namespace std;
	
	cout << " 排序算法比较\n\n";
	cout << " 1. 冒泡排序\n";
	cout << " 2. 选择排序\n";
	cout << " 3. 直接插入排序\n";
	cout << " 4. 希尔排序\n";
	cout << " 5. 快速排序\n";
	cout << " 6. 堆排序\n";
	cout << " 7. 归并排序\n";
	cout << " 8. 基数排序\n";
	cout << " 9. 退出\n";

	cout << "请输入要产生的随机数的个数（温馨提示：计算机无法表示无穷）\n";
	int Size;
	cin >> Size;
	check(Size);

	int* array = new int[Size];
	int* copy  = new int[Size];
	srand((unsigned)time(NULL));
	//通用公式: a + rand() % n；其中的 a 是起始值，n 是整数的范围。

	//initialize
	for (int i = 0; i < Size; i++)
	{
		array[i] = copy[i] = rand() % (Size * 2 + 1) + 0;

		#if DEBUG
		cout << array[i] << " ";
		if (i % 10 == 0 && i)cout << "\n";
		#endif // DEBUG
	}
	cout << "\n";

	int choice = 0;
	enum CHOICE { nul, bubble, select, insert, shell, quick, heap, merge, radix, quit };

	while (1)
	{
		cout << "选择一种排序算法\n";
		cin >> choice;
		check(choice);

		switch (choice)
		{
			case bubble: 
			{
				Timer timer;
				cout << "bubble!\n";

				#if DEBUG
				cout << "before sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 20 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif			
				Sort::bubbleSort(array, Size);
				#if DEBUG

				cout << "after sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 20 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif // DEBUG

				for (int i = 0; i < Size; i++)
				{
					array[i] = copy[i];//恢复数组原型
				}
				break;
			}
			case select:
			{
				Timer timer;
				cout << "select!\n";
				#if DEBUG
				cout << "before sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 20 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif		

				Sort::selectSort(array, Size);
				#if DEBUG

				cout << "after sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 10 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif // DEBUG

				for (int i = 0; i < Size; i++)
				{
					array[i] = copy[i];//恢复数组原型
				}
				break;
			}
			case insert:
			{
				cout << "insert!\n";

				#if DEBUG
				cout << "before sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 20 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif		

				Timer timer;
				Sort::insertSort(array, Size);
				#if DEBUG

				cout << "after sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 10 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif // DEBUG

				for (int i = 0; i < Size; i++)
				{
					array[i] = copy[i];//恢复数组原型
				}
				break;
			}
			case shell:
			{
				#if DEBUG
				cout << "before sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 20 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif		
				cout << "shell!\n";
				Timer timer;
				Sort::shellSort(array, Size);
				#if DEBUG

				cout << "after sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 10 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif // DEBUG

				for (int i = 0; i < Size; i++)
				{
					array[i] = copy[i];//恢复数组原型
				}
				break;
			}
			case quick:
			{
				cout << "quick!\n";
				Timer timer;
				Sort::quickSort(array, 0, Size - 1);
				#if DEBUG

				cout << "after sort\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 10 == 0 && i)cout << "\n";
				}
				cout << "\n\n";
				#endif // DEBUG

				for (int i = 0; i < Size; i++)
				{
					array[i] = copy[i];//恢复数组原型
				}
				break;
			}
			case heap:
			{
				cout << "heap!\n";
				Timer timer;
				Sort::heapSort(array, Size);
				#if DEBUG

				cout << "after sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 10 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif // DEBUG

				for (int i = 0; i < Size; i++)
				{
					array[i] = copy[i];//恢复数组原型
				}
				break;
			}
			case merge:
			{
				cout << "merge!\n";
				Timer timer;
				Sort::mergeSort(array, Size);
				#if DEBUG

				cout << "after sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 10 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif // DEBUG

				for (int i = 0; i < Size; i++)
				{
					array[i] = copy[i];//恢复数组原型
				}
				break;
			}
			case radix:
			{
				cout << "radix!\n";
				Timer timer;
				Sort::radixSort(array, Size);
				#if DEBUG

				cout << "after sort\n\n";
				for (int i = 0; i < Size; i++)
				{
					cout << array[i] << " ";
					if (i % 10 == 0 && i)cout << "\n";
				}
				cout << "\n";
				#endif // DEBUG

				for (int i = 0; i < Size; i++)
				{
					array[i] = copy[i];//恢复数组原型
				}
				break;
			}
			case quit:
			{
				cout << "quit!\n";
				return 0;
			}
			default:
			{
				;
			}
		}
		

	}
	
	delete[] array;
	delete[] copy;
	return 0;
}

bool check(int& number)
{
	using namespace std;
	while (std::cin.fail() || number <= 0)
	{
		cout << "error input, please input again.\n";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> number;
	}
	return true;
}
