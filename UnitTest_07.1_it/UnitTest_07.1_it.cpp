#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07.1_it/lab_07.1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest071it
{
	TEST_CLASS(UnitTest071it)
	{
	public:

		TEST_METHOD(TestMethod1){
			int S = 0;
			int amount = 0;
			int** arr = new int*[7];
			for (int i = 0; i != 7; i++) {
				arr[i] = new int[6];
			}

			int a[7][6] = { { 9,52,58,42,56,27},
							{12,35,47,20,54,35},
							{35,50,30,30,61,56},
							{40,53,31,13,20,14},
							{43,47,40,33,19,16},
							{44,14,43,54,16,19},
							{55,20,52,33,19,38}};

			for (int i = 0; i != 7; i++) {
				for (int j = 0; j != 6; j++) {
					arr[i][j] = a[i][j];
				}
			}

			int expected[7][6] = { {9,0,0,0,0,0},
								   {0,0,0,0,0,0},
								   {0,0,0,0,0,0},
								   {0,0,0,0,0,0},
								   {0,0,0,33,0,0},
								   {0,0,43,0,0,0},
								   {0,0,0,0,0,0} };
			Calc(arr,7,6,S,amount);
			for (int i = 0; i != 7; i++) {
				for (int j = 0; j != 6; j++) {
					Assert::AreEqual(arr[i][j], expected[i][j]);
				}
			}
		}
	};
}
