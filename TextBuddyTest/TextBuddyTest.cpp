#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest
{		
	TEST_CLASS(TextBuddyTest)
	{
	public:
		
		TEST_METHOD(addText_Test)
		{
			TextBuddy TextBuddy;
			string expected = "added to test: \"Hello There\"\n";
			string s1;

			TextBuddy.outputFile = "test";
			s1 = TextBuddy.addText("Hello There");

			Assert::IsTrue(TextBuddy.textList[0] == "Hello There");
			Assert::AreEqual(expected, s1);	
		}

		TEST_METHOD(clearText_Test)
		{
			TextBuddy TextBuddy;
			string expected = "all contents deleted from test\n";
			string s1;

			TextBuddy.outputFile = "test";

			TextBuddy.addText("testing"); 

			s1 = TextBuddy.clearText();

			Assert::AreEqual(expected, s1);
			Assert::IsTrue(TextBuddy.textList.size() == 0);
		}
	};
}