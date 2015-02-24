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

		TEST_METHOD(sort_Test)
		{
			TextBuddy TextBuddy;
			vector<string> expected;
			string s1 = "sorted!\n";
			string actual;

			expected.push_back("aaaaa");
			expected.push_back("bbbbb");
			expected.push_back("ccccc");
			expected.push_back("ddddd");

			TextBuddy.textList.push_back("ddddd");
			TextBuddy.textList.push_back("ccccc");
			TextBuddy.textList.push_back("bbbbb");
			TextBuddy.textList.push_back("aaaaa");

			for (int j=0; j<TextBuddy.textList.size(); ++j) {
				Assert::AreEqual(expected[j], TextBuddy.textList[j]);
			}

			actual = TextBuddy.sort();

			Assert::AreEqual(s1, actual);
		}
	};
}