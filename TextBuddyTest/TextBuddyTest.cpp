#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest
{		
	TEST_CLASS(TextBuddyTest)
	{
	public:
		
		TEST_METHOD(addTextMessage_Test)
		{
			TextBuddy TextBuddy;
			string expected = "added to test: \"Hello There\"\n";

			TextBuddy.outputFile = "test";

			Assert::AreEqual(expected, TextBuddy.addText("Hello There"));	
		}

		TEST_METHOD(addedText_Test)
		{
			TextBuddy TextBuddy;
			string expected = "added to test: \"Hello There\"\n";

			TextBuddy.addText("Hello There");

			Assert::IsTrue(TextBuddy.textList[0] == "Hello There");
		}

		TEST_METHOD(clearTextMessage_Test)
		{
			TextBuddy TextBuddy;
			string expected = "all contents deleted from test\n";

			TextBuddy.outputFile = "test";

			Assert::AreEqual(expected, TextBuddy.clearText());
		}

		TEST_METHOD(clearedText_Test)
		{
			TextBuddy TextBuddy;
			string expected = "all contents deleted from test\n";

			TextBuddy.outputFile = "test";
			TextBuddy.addText("testing"); 

			TextBuddy.clearText();

			Assert::IsTrue(TextBuddy.textList.size() == 0);
		}

		TEST_METHOD(sortMessage_Test)
		{
			TextBuddy TextBuddy;
			string expected = "sorted!\n";

			Assert::AreEqual(expected, TextBuddy.sort());
		}

		TEST_METHOD(sort_Test)
		{
			TextBuddy TextBuddy;
			vector<string> expected;
			string actual;

			expected.push_back("aaaaa");
			expected.push_back("bbbbb");
			expected.push_back("ccccc");
			expected.push_back("ddddd");

			TextBuddy.textList.push_back("ddddd");
			TextBuddy.textList.push_back("ccccc");
			TextBuddy.textList.push_back("bbbbb");
			TextBuddy.textList.push_back("aaaaa");

			TextBuddy.sort();

			for (int j=0; j<TextBuddy.textList.size(); ++j) {
				Assert::AreEqual(expected[j], TextBuddy.textList[j]);
			}
		}

		TEST_METHOD(searching_Test)
		{
			TextBuddy TextBuddy;
			string expected = "searching for \"testing\"...\nnot found\n";

			Assert::AreEqual(expected, TextBuddy.search("testing"));
		}

		TEST_METHOD(searchAndFound_Test)
		{
			TextBuddy TextBuddy;
			string expected = "searching for \"there\"...\n1. Hello there\n\n2. Hello there there\n";

			TextBuddy.addText("Hello there");
			TextBuddy.addText("Hello there there");
			TextBuddy.addText("Hello here here");

			Assert::AreEqual(expected, TextBuddy.search("there"));
		}

		TEST_METHOD(searchAndNotFound_Test)
		{
			TextBuddy TextBuddy;
			string expected = "searching for \"testing\"...\nnot found\n";

			TextBuddy.addText("Hello there");
			TextBuddy.addText("Hello there there");
			TextBuddy.addText("Hello here here");

			Assert::AreEqual(expected, TextBuddy.search("testing"));
		}
	};
}