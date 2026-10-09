#include "pch.h"
#include "CppUnitTest.h"
#include "../PR05.2/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest052
{
	TEST_CLASS(UnitTest052)
	{
	public:

		
		TEST_METHOD(TestMethodA)
		{
			double x = 2;
			int n = 1;
			double a = 0.5;               
			double expected = 0.5 * 1.0 / (3.0 * 4.0);  

			A(x, n, a);

			Assert::AreEqual(expected, a, 0.0001);
		}

	
		TEST_METHOD(TestMethodS_Sum)
		{
			double x = 2, eps = 0.0001, s = 0;
			int n = 0;
			double expected = 0.5 * log((x + 1) / (x - 1));  

			S(x, eps, n, s);

			Assert::AreEqual(expected, s, eps);
		}

		TEST_METHOD(TestMethodS_N)
		{
			double x = 2, eps = 0.0001, s = 0;
			int n = 0;

			S(x, eps, n, s);

			Assert::AreEqual(5, n);
		}
	};
}