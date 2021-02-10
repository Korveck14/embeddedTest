// unittest_Functions.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include "functions.h"

//Test getFirstRepeatedNumber() with two vectors with the same length.
TEST(getFirstRepeatedNumberTest, vectorsWithSameLength) {
  vector<int> viFirst{ 40,10,23,2,3,1 };
  vector<int> viSecond{ 1,0,2,3,50,23 };
  EXPECT_EQ(23, getFirstRepeatedNumber(viFirst, viSecond));
}

//Test getFirstRepeatedNumber() with two vectors with different length.
TEST(getFirstRepeatedNumberTest, vectorsWithDiffLength) {
  vector<int> viFirst{ 40,10,23 };
  vector<int> viSecond{ 1,0,2,3,50,23 };
  EXPECT_EQ(23, getFirstRepeatedNumber(viFirst, viSecond));
}

//Test getFirstRepeatedNumber() with vectors with negative numbers.
TEST(getFirstRepeatedNumberTest, vectorsNegativeNumbers) {
  vector<int> viFirst{ -40,-10,-23 };
  vector<int> viSecond{ -1,0,-2,-3,-50,-23 };
  EXPECT_EQ(-23, getFirstRepeatedNumber(viFirst, viSecond));
}

//Test getFirstRepeatedNumber() with vectors with positive and negative numbers.
TEST(getFirstRepeatedNumberTest, vectorsPosNegNumbers) {
  vector<int> viFirst{ -40,10,-23,50 };
  vector<int> viSecond{ 1,0,-2,3,-50,-23 };
  EXPECT_EQ(-23, getFirstRepeatedNumber(viFirst, viSecond));
}

//Test getFirstRepeatedNumber() with two vectors that do not have any repeated number.
TEST(getFirstRepeatedNumberTest, vectorsWithoutRepeatedNumber) {
  vector<int> viFirst{ 40,10,23 };
  vector<int> viSecond{ 1,0,2,3,50 };
  EXPECT_EQ(-1, getFirstRepeatedNumber(viFirst, viSecond));
}

//Test getFirstRepeatedNumber() with first vector empty.
TEST(getFirstRepeatedNumberTest, firstVectorEmpty) {
  vector<int> viFirst;
  vector<int> viSecond{ 1,0,2,3,50 };
  EXPECT_EQ(-1, getFirstRepeatedNumber(viFirst, viSecond));
}

//Test getFirstRepeatedNumber() with second vector empty.
TEST(getFirstRepeatedNumberTest, secondVectorEmpty) {
  vector<int> viFirst{ 40,10,23 };
  vector<int> viSecond;
  EXPECT_EQ(-1, getFirstRepeatedNumber(viFirst, viSecond));
}

//Test getFirstRepeatedNumber() with both vectors empty.
TEST(getFirstRepeatedNumberTest, vectorsEmpty) {
  vector<int> viFirst;
  vector<int> viSecond;
  EXPECT_EQ(-1, getFirstRepeatedNumber(viFirst, viSecond));
}

//Test getFile() with a known directory.
TEST(getFile, knownDirectory) {
  EXPECT_EQ("Test.exe", getFile("D:/test"));
}

//Test getFile() with a unknown directory.
TEST(getFile, unknownDirectory) {
  EXPECT_EQ("", getFile(""));
}

//Test getFile() with a directory that does not have the file that meets the requirements.
TEST(getFile, directoryWithouFile) {
  EXPECT_EQ("", getFile("D:/test2"));
}

//Test getMinNumberOfPermutations() with the example sequence.
TEST(getFile, exampleSequence) {
  vector<bool> viSequence{ 0, 1, 1, 0 };
  EXPECT_EQ(1, getMinNumberOfPermutations(viSequence));
}

//Test getMinNumberOfPermutations() with a larger sequence.
TEST(getFile, largerSequence) {
  vector<bool> viSequence{ 0, 0, 1, 0, 0, 1, 1, 1, 1, 0 };
  EXPECT_EQ(2, getMinNumberOfPermutations(viSequence));
}

//Test getMinNumberOfPermutations() with one head more than tails.
TEST(getFile, moreHeadThanTails) {
  vector<bool> viSequence{ 1, 1, 1, 0, 0 };
  EXPECT_EQ(1, getMinNumberOfPermutations(viSequence));
}

//Test getMinNumberOfPermutations() with one tail more than heads.
TEST(getFile, moreTailsThanHeads) {
  vector<bool> viSequence{ 1, 1, 0, 0, 0 };
  EXPECT_EQ(1, getMinNumberOfPermutations(viSequence));
}

//Test getMinNumberOfPermutations() with an empty sequence.
TEST(getFile, emptySequence) {
  vector<bool> viSequence;
  EXPECT_EQ(0, getMinNumberOfPermutations(viSequence));
}

//Test getMinNumberOfPermutations() with only a head.
TEST(getFile, onlyOneHead) {
  vector<bool> viSequence{ 1 };
  EXPECT_EQ(0, getMinNumberOfPermutations(viSequence));
}

//Test getMinNumberOfPermutations() with only a tail.
TEST(getFile, onlyOneTail) {
  vector<bool> viSequence{ 0 };
  EXPECT_EQ(0, getMinNumberOfPermutations(viSequence));
}

//Test getMinNumberOfPermutations() with more than one head more than tails.
TEST(getFile, moreThanOneHeadThanTails) {
  vector<bool> viSequence{ 1, 1, 1, 0, 0, 1 };
  EXPECT_EQ(-1, getMinNumberOfPermutations(viSequence));
}

//Test getMinNumberOfPermutations() with more than one tail more than heads.
TEST(getFile, moreThanOneTailsThanHeads) {
  vector<bool> viSequence{ 0, 1, 1, 0, 0, 0 };
  EXPECT_EQ(-1, getMinNumberOfPermutations(viSequence));
}

