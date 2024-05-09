#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_7/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestFibonacciNumbers)
        {
            Assert::IsTrue(isFibonacci(0));
            Assert::IsTrue(isFibonacci(1));
            Assert::IsTrue(isFibonacci(1));
            Assert::IsTrue(isFibonacci(2));
            Assert::IsTrue(isFibonacci(3));
            Assert::IsTrue(isFibonacci(5));
            Assert::IsTrue(isFibonacci(8));
            Assert::IsTrue(isFibonacci(13));
            Assert::IsTrue(isFibonacci(21));
            Assert::IsTrue(isFibonacci(34));
        }

        TEST_METHOD(TestNonFibonacciNumbers)
        {
            Assert::IsFalse(isFibonacci(-1));
            Assert::IsFalse(isFibonacci(4));
            Assert::IsFalse(isFibonacci(6));
            Assert::IsFalse(isFibonacci(7));
            Assert::IsFalse(isFibonacci(10));
            Assert::IsFalse(isFibonacci(15));
            Assert::IsFalse(isFibonacci(20));
            Assert::IsFalse(isFibonacci(25));
            Assert::IsFalse(isFibonacci(30));
        }
    };
}
