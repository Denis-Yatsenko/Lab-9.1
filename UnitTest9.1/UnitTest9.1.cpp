#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91
{
	TEST_CLASS(UnitTest91)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* p = new Student[N];
			int k = LineSearch(p, N);
			p = new Student;
			p->prizv = "яценко";
			p->rik_nar = 2003;
			p->physics = 4;
			Assert::AreEqual(k, 0);
		}
	};
}
