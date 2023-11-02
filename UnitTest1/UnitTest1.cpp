#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.1/Lab 6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestGenerateRandom)
		{
			int arr[arraySize];
			generateRandom(arr, arraySize, lowerLimit, upperLimit);

			for (int i = 0; i < arraySize; i++) {
				Assert::IsTrue(arr[i] >= lowerLimit && arr[i] <= upperLimit);
			}
		}


		TEST_METHOD(TestReplaceNegative)
		{
			int arr[] = { -3, 4, -5, 7, -2, 10 };
			int size = sizeof(arr) / sizeof(arr[0]);

			replaceNegative(arr, size);

			for (int i = 0; i < size; i++) {
				if (arr[i] < 0 || arr[i] % 2 != 0) {
					Assert::AreEqual(0, arr[i]);
				}
			}
		}
	};
}
