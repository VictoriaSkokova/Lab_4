#include <iostream>
#include "Sort.h"
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;


void Array::Create(int *&Arr, const int size) //Выделение памяти под массив типа int
{
	if (size > 0)
		Arr = new int[size];
	else
		throw out_of_range("Wrong index");
}

void Array::CharCreate(char *&Arr, const int size) //Выделение памяти под массив типа char
{
	if (size > 0)
	{
		setlocale(LC_ALL, "Russian");
		Arr = new char[size];
	}
	else
		throw out_of_range("Wrong index");
}

void Array::Delete(int *Arr)    //Освобождение памяти
{
	delete[]Arr;
	Arr = NULL;   //указываем, что теперь массив должен находится в новом зарезервированном месте и указывает вникуда
}

void Array::DeleteChar(char *Arr)    //Освобождение памяти
{
	delete[]Arr;
	Arr = NULL;   //указываем, что теперь массив должен находится в новом зарезервированном месте и указывает вникуда
}

void Array::Fill(int *Arr, const int size)    // Случайное заполнение массива
{
	for (int i = 0; i < size; i++) Arr[i] = rand() % size + 1;
}

void Array::CharFill(char *Arr, const int size)  // Чтение массива символов
{
	char letter;
	std::cout << "Введите, пожалуйста, массив символов:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> letter;
		Arr[i] = letter;
	}
}

void Array::Print_Array_Char(char *Arr, const int size)  //Вывод массива типа char на экран
{
	for (int i = 0; i < size; i++) std::cout << Arr[i] << "  ";
}

void Array::Print_Array(int *Arr, const int size)  //Вывод массива типа int на экран
{
	for (int i = 0; i < size; i++) std::cout << Arr[i] << "  ";
}


//____________________________________________________________________________________________________



void Array::Swap(int& first, int& second)
{
	const int temp = first;
	first = second;
	second = temp;
}

void Array::heapify(int* arr, size_t count, int i)
{
	int largest = i;
	const int left = 2 * i + 1;
	const int right = 2 * i + 2;

	if (left < count && arr[left] > arr[largest])
		largest = left;

	if (right < count && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		Swap(arr[i], arr[largest]);
		heapify(arr, count, largest);
	}
}

void Array::heapSort(int *Arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(Arr, size, i);

	for (int i = size - 1; i >= 0; i--)
	{
		Swap(Arr[0], Arr[i]);

		heapify(Arr, i, 0);
	}
}

//____________________________________________________________________________________________________


int Array::binarySearch(int *Arr, int size, int searchelem)
{
	int left = 0;
	int right = size - 1;
	int search = -1;
	while (left <= right) // пока левая граница не "перескочит" правую
	{
		int mid = (left + right) / 2; // ищем середину отрезка
		if (searchelem == Arr[mid]) { // если ключевое поле равно искомому
			search = mid; // мы нашли требуемый элемент,
			break; // выходим из цикла
		}
		if (searchelem < Arr[mid]) // если искомое ключевое поле меньше найденной середины
			right = mid - 1; // смещаем правую границу, продолжим поиск в левой части
		else // иначе
			left = mid + 1; // смещаем левую границу, продолжим поиск в правой части
	}
	if (search == -1) // если индекс элемента по-прежнему -1, элемент не найден
	{
		std::cout << "Элемент не найден\n";
		return -1;
	}
	else // иначе выводим элемент, его ключ и значение
	{
		std::cout << "Индекс элемента - " << search;
		return search;
	}

}


//____________________________________________________________________________________________________


void Array::QuickSort(int *Arr, int left, int size)
{
	int median;
	int l_hold = left;
	int r_hold = size;
	median = Arr[left];
	while (left < size)
	{
		while ((Arr[size] >= median) && (left < size))
			size--;
		if (left != size)
		{
			Arr[left] = Arr[size];
			left++;
		}
		while ((Arr[left] <= median) && (left < size))
			left++;
		if (left != size)
		{
			Arr[size] = Arr[left];
			size--;
		}
	}
	Arr[left] = median;
	median = left;
	left = l_hold;
	size = r_hold;
	if (left < median)
		QuickSort(Arr, left, median - 1);
	if (size > median)
		QuickSort(Arr, median + 1, size);
}

void Array::QuickSort_begin(int *Arr, int size)
{
	QuickSort(Arr, 0, size);
}

//____________________________________________________________________________________________________



void Array::bubble_sort(int *Arr, int size)
{
	int i = 0;
	int buf;
	char check = 0;
	if (size == 0)
		std::cout << "Массив пуст";
	while (i < size)
	{
		if (i + 1 != size && Arr[i] > Arr[i + 1])
		{
			buf = Arr[i];
			Arr[i] = Arr[i + 1];
			Arr[i + 1] = buf;
			check = 1;
		}
		i++;
		if (i == size && check == 1)
		{
			check = 0;
			i = 0;
		}
	}
}



//____________________________________________________________________________________________________



int correct(int *Arr, int size)
{
	if (size <= 0)
		return 0;
	else
	{
		while (--size > 0)
			if (Arr[size - 1] > Arr[size])
				return 0;
		return 1;
	}
}


void shuffle(int *Arr, int size) {
	int i;
	for (i = 0; i < size; ++i)
		std::swap(Arr[i], Arr[(rand() % size)]);
}

void bogoSort(int *Arr, int size)
{
	while (!correct(Arr, size))
		shuffle(Arr, size);
}

void Array::Bogo_sort(int *Arr, int size)
{
	if (correct(Arr, size) != 1)
	{
		shuffle(Arr, size);

		bogoSort(Arr, size);
	}
}

//____________________________________________________________________________________________________


void Array::CountingSort(char* Arr, int size)
{
	size_t* SortingArray = new size_t[254];
	for (int i = 0; i < 254; i++)
		SortingArray[i] = 0;
	for (int i = 0; i < size; i++)
	{
		SortingArray[Arr[i]]++;
	}

	int j = 0;

	for (int i = 0; i < 254; i++)
	{
		while (SortingArray[i] != 0)
		{
			char c = i;
			Arr[j] = c;
			j++;
			SortingArray[i]--;
		}
	}
	delete[]SortingArray;
}
