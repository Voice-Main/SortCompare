#include <iostream>
#include "Sort.h"
#include "Timer.h"

#define DEBUG 0
//check if the number is positive
bool check(int& number);

int main()
{

	using namespace std;
	
	cout << " �����㷨�Ƚ�\n\n";
	cout << " 1. ð������\n";
	cout << " 2. ѡ������\n";
	cout << " 3. ֱ�Ӳ�������\n";
	cout << " 4. ϣ������\n";
	cout << " 5. ��������\n";
	cout << " 6. ������\n";
	cout << " 7. �鲢����\n";
	cout << " 8. ��������\n";
	cout << " 9. �˳�\n";

	cout << "������Ҫ������������ĸ�������ܰ��ʾ��������޷���ʾ���\n";
	int Size;
	cin >> Size;
	check(Size);

	int* array = new int[Size];
	int* copy  = new int[Size];
	srand((unsigned)time(NULL));
	//ͨ�ù�ʽ: a + rand() % n�����е� a ����ʼֵ��n �������ķ�Χ��

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
		cout << "ѡ��һ�������㷨\n";
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
					array[i] = copy[i];//�ָ�����ԭ��
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
					array[i] = copy[i];//�ָ�����ԭ��
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
					array[i] = copy[i];//�ָ�����ԭ��
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
					array[i] = copy[i];//�ָ�����ԭ��
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
					array[i] = copy[i];//�ָ�����ԭ��
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
					array[i] = copy[i];//�ָ�����ԭ��
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
					array[i] = copy[i];//�ָ�����ԭ��
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
					array[i] = copy[i];//�ָ�����ԭ��
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
