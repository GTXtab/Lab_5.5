#include "pch.h"
#include "CppUnitTest.h"
#include <cmath> // для pow

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

double rec_fun(double a, double L, double eps, int& depth) {
    depth++;
    double next = (1. / 3.) * (2. * a + (8. / pow(a, 2)));
    if (abs(next - a) < eps) {
        return next;
    }
    return rec_fun(next, L, eps, depth);
}

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            double inputA = 1.0, inputL = 2.0, inputEps = 0.00001;
            int inputDepth = 0;

            double expectedOutput = 2.0;

            double actualOutput = rec_fun(inputA, inputL, inputEps, inputDepth);
            Assert::AreEqual(expectedOutput, actualOutput, 0.00001);
        }
    };
}
