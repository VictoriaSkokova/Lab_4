#include <iostream>
#include "Sort.h"
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int chosenone;
	do {
		cout << "Добрый день. Лабораторная работа 4. Выполнила Скокова Виктория гр. 7302\n";
		cout << "1. Двоичный поиск (BinarySearch)\n";
		cout << "2. Быстрая сортировка (QuickSort)\n";
		cout << "3. Сортировка пузырьком (BubbleSort)\n";
		cout << "4. Пирамидальная сортировка (HeapSort)\n";
		cout << "5. Глупая сортировка (BogoSort)\n";
		cout << "6. Сортировка подсчётом (CountingSort) для типа char\n";
		cout << "0. Выход\n";

		int *Array_int = NULL;
		char *Array_char = NULL;
		Array Sorting_array;
		int size = 10;
		Sorting_array.Create(Array_int, size);
		Sorting_array.Fill(Array_int, size);
		Sorting_array.Print_Array(Array_int, size);

		cout << "\n";
		cout << "Введите номер из меню - ";
		cin >> chosenone;
		switch (chosenone)
		{
		case 1:
		{
			Sorting_array.QuickSort_begin(Array_int, size - 1);
			cout << "Массив после быстрой сортировки:\n";
			Sorting_array.Print_Array(Array_int, size);
			cout << "\n Массив для двоичного поиска \n";
			int searchelem;
			cout << "Пожалуйста, введите элемент, который будем искать - ";
			cin >> searchelem;
			Sorting_array.binarySearch(Array_int, size, searchelem);
			Sorting_array.Delete(Array_int);
			cout << "\n";
			break;
		}



		case 2:
		{
			cout << "Массив после быстрой сортировки\n";
			clock_t t = clock();
			Sorting_array.QuickSort_begin(Array_int, size - 1);
			t = clock() - t;
			Sorting_array.Print_Array(Array_int, size);
			cout << "\n";
			printf("Сортировка заняла %d (%f секунд).\n", t, ((float)t / CLOCKS_PER_SEC));
			Sorting_array.Delete(Array_int);
			cout << "\n";
			break;
		}

		case 3:
		{
			cout << "Массив после сортировки пузырьком \n";
			clock_t t = clock();
			t = clock();
			Sorting_array.bubble_sort(Array_int, size);
			t = clock() - t;
			Sorting_array.Print_Array(Array_int, size);
			cout << "\n";
			printf("Сортировка заняла %d (%f секунд).\n", t, ((float)t / CLOCKS_PER_SEC));
			Sorting_array.Delete(Array_int);
			cout << "\n";
			break;
		}

		case 4:
		{
			Sorting_array.heapSort(Array_int, size);
			cout << "Массив после сортировки кучей  \n";
			Sorting_array.Print_Array(Array_int, size);
			cout << "\n";

			break;
		}

		case 5:
		{
			cout << "Массив после глупой сортировки\n";
			Sorting_array.Bogo_sort(Array_int, size);
			Sorting_array.Print_Array(Array_int, size);
			Sorting_array.Delete(Array_int);
			cout << "\n";
			break;
		}

		case 6:
		{
			Sorting_array.CharCreate(Array_char, size);
			Sorting_array.CharFill(Array_char, size);
			cout << "Массив символов\n";
			Sorting_array.Print_Array_Char(Array_char, size);
			cout << "\n";
			cout << "Массив после сортировки\n";
			Sorting_array.CountingSort(Array_char, size);
			Sorting_array.Print_Array_Char(Array_char, size);
			cout << "\n";
			Sorting_array.DeleteChar(Array_char);
			break;
		}

		case 0:
			break;

		default:
			cout << "Неправильное значение" << std::endl;
			system("pause");
		}
		system("pause");
		system("cls");
	}
	while (chosenone != 0);

	return 0;


}
