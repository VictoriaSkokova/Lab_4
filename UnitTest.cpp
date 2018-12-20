#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Lab_Alg4\Sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		
		TEST_METHOD(Exception_1)
		{
			int *Array_int = NULL;
			Array Sorting_array;
			
			char error;
			try
			{
				Sorting_array.Create(Array_int, -1);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Wrong index", error.what());
			}
		}


		TEST_METHOD(Exception_2)
		{
			int *Array_char = NULL;
			Array Sorting_array;

			char error;
			try
			{
				Sorting_array.Create(Array_char, -1);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Wrong index", error.what());
			}
		}

		
		
		
		TEST_METHOD(TestCorrect)
		{
			int A[4];
			A[0] = 1;
			A[1] = 2;
			A[2] = 3;
			A[3] = 4;
			Assert::IsTrue(correct(A, 4));
		}

		TEST_METHOD(TestCorrectIsFalse)
		{
			int A[4];
			A[0] = 1;
			A[1] = 2;
			A[2] = 5;
			A[3] = 4;
			Assert::IsFalse(correct(A, 4));
		}


		TEST_METHOD(HeapSort)
		{
			Array Array;
			int *A = NULL;
			Array.Create(A, 10);
			Array.Fill(A, 10);
			Array.heapSort(A, 10);
			Assert::IsTrue(correct(A, 10));
			Array.Delete(A);
		}



		TEST_METHOD(BubbleSort)
		{
			Array Array;
			int *A = NULL;
			Array.Create(A, 10);
			Array.Fill(A, 10);
			Array.bubble_sort(A, 10);
			Assert::IsTrue(correct(A, 10));
			Array.Delete(A);
		}

		TEST_METHOD(BogoSort)
		{
			Array Array;
			int *A = NULL;
			Array.Create(A, 10);
			Array.Fill(A, 10);
			Array.Bogo_sort(A, 10);
			Assert::IsTrue(correct(A, 10));
			Array.Delete(A);
		}


		TEST_METHOD(QuckSort)
		{
			Array Array;
			int *A = NULL;
			Array.Create(A, 10);
			Array.Fill(A, 10);
			Array.QuickSort_begin(A, 10);
			Assert::IsTrue(correct(A, 10));
			Array.Delete(A);
		}

		TEST_METHOD(CountingSort)
		{
			Array Array;
			char *A = NULL;
			Array.CharCreate(A, 10);
			A[0] = 'a';
			A[1] = 'a';
			A[2] = 'b';
			A[3] = 'a';
			A[4] = 'g';
			A[5] = 'g';
			A[6] = 'f';
			A[7] = 'e';
			A[8] = 'c';
			A[9] = 'd';
			Array.CountingSort(A, 10);
			Assert::IsTrue(A[3] == 'b');
			Array.DeleteChar(A);
		}

		TEST_METHOD(CountingSort_Array)
		{
			Array Array;
			char *A = NULL;
			bool check = true;
			Array.CharCreate(A, 10);
			A[0] = 'a';
			A[1] = 'j';
			A[2] = 'i';
			A[3] = 'h';
			A[4] = 'f';
			A[5] = 'g';
			A[6] = 'd';
			A[7] = 'e';
			A[8] = 'c';
			A[9] = 'b';
			Array.CountingSort(A, 10);

			char a[10];
			a[0] = 'a';
			a[1] = 'b';
			a[2] = 'c';
			a[3] = 'd';
			a[4] = 'e';
			a[5] = 'f';
			a[6] = 'g';
			a[7] = 'h';
			a[8] = 'i';
			a[9] = 'j';

			int i = 0;
			while(i<10)
			{
				if (a[i] != A[i])
					check = false;
				i++;
			}
			Assert::IsTrue(check);
			Array.DeleteChar(A);
		}


		TEST_METHOD(BinarySearch)
		{
			Array Array;
			int *A = NULL;
			Array.Create(A, 10);
			A[0] = 1;
			A[1] = 2;
			A[2] = 3;
			A[3] = 6;
			A[4] = 7;
			Assert::IsTrue(Array.binarySearch(A, 5, 6) == 3);
			Array.Delete(A);
		}

		TEST_METHOD(BinarySearchNotFound)
		{
			Array Array;
			int *A = NULL;
			Array.Create(A, 10);
			A[0] = 1;
			A[1] = 2;
			A[2] = 3;
			A[3] = 6;
			A[4] = 7;
			Assert::IsTrue(Array.binarySearch(A, 5, 10) == -1);
			Array.Delete(A);
		}
	};
}
