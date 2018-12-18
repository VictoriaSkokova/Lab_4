#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

class Array
{
public:
	void Create(int *&Arr, const int size); //Метод выделения памяти под массив
	void Delete(int *Arr);  //Метод освобождения памяти
	void DeleteChar(char* Arr);
	void Fill(int *Arr, const int size); //Метод заполнения массива значениями
	void Print_Array(int *Arr, const int size);//Метод отображения массива на экране
	void heapSort(int *Arr, int size);
	void Swap(int& first, int& second);
	void heapify(int* arr, size_t count, int i);
	int binarySearch(int *Arr, int size, int searchelem);
	void QuickSort(int *Arr, int left, int size);
	void QuickSort_begin(int *Arr, int size);
	void bubble_sort(int *Arr, int size);
	void Bogo_sort(int *Arr, int size);
	void CharCreate(char *&Arr, const int size);
	void CharFill(char *Arr, const int size);
	void Print_Array_Char(char *Arr, const int size);
	void CountingSort(char* Arr, int size);
	
};

int correct(int *Arr, int size);
void shuffle(int *Arr, int size);
void bogoSort(int *Arr, int size);
