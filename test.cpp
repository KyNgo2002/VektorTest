#include "pch.h"
#include "../Vektor/include/vektor.h"

TEST(InitializationTest, DefaultConstructor) {
	Vektor<int> vektor;
	EXPECT_TRUE(vektor.empty());
	EXPECT_EQ(vektor.size(), 0);
	EXPECT_EQ(vektor.capacity(), 10);
}

TEST(InitializationTest, SizeConstructor) {
	Vektor<int> vektor(1);
	EXPECT_FALSE(vektor.empty());
	EXPECT_EQ(vektor.size(), 1);
	EXPECT_EQ(vektor.capacity(), 2);

	Vektor<int> vektor1(10);
	EXPECT_FALSE(vektor1.empty());
	EXPECT_EQ(vektor1.size(), 10);
	EXPECT_EQ(vektor1.capacity(), 20);

	Vektor<int> vektor2(0);
	EXPECT_EQ(vektor2.size(), 0);
	EXPECT_EQ(vektor2.capacity(), 10);
	
	EXPECT_DEATH(Vektor<int> vektor3(-1), ".*");

	Vektor<int> vektor4(10000);
	EXPECT_EQ(vektor4.size(), 10000);
	EXPECT_EQ(vektor4.capacity(), 10000 * 2);
}

TEST(InitializationTest, SizeAndValueConstructor) {
	Vektor<int> vektor(10, 20);
	EXPECT_FALSE(vektor.empty());
	EXPECT_EQ(vektor.size(), 10);
	EXPECT_EQ(vektor.capacity(), 20);
	for (unsigned i = 0; i < vektor.size(); ++i)
		EXPECT_EQ(vektor[i], 20);

	Vektor<int> vektor1(5, -1);
	EXPECT_FALSE(vektor1.empty());
	EXPECT_EQ(vektor1.size(), 5);
	EXPECT_EQ(vektor1.capacity(), 10);
	for (unsigned i = 0; i < vektor1.size(); ++i)
		EXPECT_EQ(vektor1[i], -1);

	EXPECT_DEATH(Vektor<int> vektor2(-10, -10), ".*");
}

TEST(InitializationTest, CopyConstructor) {
	Vektor<int> vektor1(10, 10);
	Vektor<int> vektor2(vektor1);
	EXPECT_EQ(vektor1.size(), vektor2.size());
	EXPECT_EQ(vektor1.capacity(), vektor2.capacity());
	EXPECT_TRUE(vektor1 == vektor2);

	Vektor<int> vektor3(0);
	Vektor<int> vektor4(vektor3);
	EXPECT_EQ(vektor3.size(), vektor4.size());
	EXPECT_EQ(vektor1.capacity(), vektor2.capacity());
	EXPECT_TRUE(vektor3 == vektor4);

	Vektor<int> vektor5(10000, -10);
	Vektor<int> vektor6(vektor5);
	EXPECT_EQ(vektor5.size(), vektor6.size());
	EXPECT_EQ(vektor5.capacity(), vektor6.capacity());
	EXPECT_TRUE(vektor5 == vektor6);
}

TEST(AccesorsTest, GetFirstElementEmpty) {
	Vektor<int> vektor;
	EXPECT_DEATH(vektor.front(), ".*");

	Vektor<int> vektor1(0);
	EXPECT_DEATH(vektor1.front(), ".*");
}

TEST(AccesorsTest, GetFirstElementNonEmpty) {
	Vektor<int> vektor(1, 1);
	EXPECT_EQ(vektor.front(), 1);
	Vektor<int> vektor1(10, -1);
	EXPECT_EQ(vektor1.front(), -1);
}

TEST(AccessorsTest, GetLastElementEmpty) {
	Vektor<int> vektor;
	EXPECT_DEATH(vektor.back(), ".*");
	Vektor<int> vektor1(10, -10);
	EXPECT_EQ(vektor1.front(), -10);

}

TEST(IndexingOperatorTest, IndexingEmptyVektor) {
	Vektor<int> vektor;
	EXPECT_DEATH(vektor[0], ".*");
	EXPECT_DEATH(vektor[20], ".*");

	Vektor<int> vektor1(0);
	EXPECT_DEATH(vektor1[0], ".*");
	EXPECT_DEATH(vektor1[20], ".*");
}

TEST(IndexingOperatorTest, IndexingNegativeIndex) {
	Vektor<int> vektor;
	EXPECT_DEATH(vektor[-1], ".*");
	EXPECT_DEATH(vektor[-10], ".*");

	Vektor<int> vektor1(0);
	EXPECT_DEATH(vektor1[-1], ".*");
	EXPECT_DEATH(vektor1[-11], ".*");
}

TEST(IndexingOperatorTest, IndexingOutOfBounds) {
	Vektor<int> vektor;
	EXPECT_DEATH(vektor[1], ".*");
	EXPECT_DEATH(vektor[10], ".*");

	Vektor<int> vektor1(10, 20);
	EXPECT_DEATH(vektor1[10], ".*");
	EXPECT_DEATH(vektor1[100], ".*");
}

TEST(IndexingOperatorTest, IndexingValidIndex) {
	Vektor<int> vektor(10, 10);
	EXPECT_EQ(vektor[0], 10);
	EXPECT_EQ(vektor[9], 10);

	Vektor<int> vektor1(1);
	EXPECT_EQ(vektor1[0], 0);

	Vektor<int> vektor2(1, 10);
	EXPECT_EQ(vektor2[0], 10);
}

TEST(EqualityOperatorTest, SameVektor) {
	Vektor<int> vektor1;
	Vektor<int> vektor2;
	EXPECT_TRUE(vektor1 == vektor1);
	EXPECT_TRUE(vektor1 == vektor2);

	Vektor<int> vektor3(10);
	Vektor<int> vektor4(10);
	EXPECT_TRUE(vektor3 == vektor3);
	EXPECT_TRUE(vektor3 == vektor4);
	
	Vektor<int> vektor5(100, -1);
	Vektor<int> vektor6(100, -1);
	EXPECT_TRUE(vektor5 == vektor6);
}

TEST(EqualityOperatorTest, DifferentVektor) {
	Vektor<int> vektor1;
	Vektor<int> vektor2(1);
	EXPECT_FALSE(vektor1 == vektor2);

	Vektor<int> vektor3(0);
	Vektor<int> vektor4(1);
	EXPECT_FALSE(vektor3 == vektor4);

	Vektor<int> vektor5(1, 1);
	Vektor<int> vektor6(1, 2);
	EXPECT_FALSE(vektor5 == vektor6);

	Vektor<int> vektor7(2, 2);
	Vektor<int> vektor8(1, 2);
	EXPECT_FALSE(vektor5 == vektor6);

	Vektor<int> vektor9(100, 2);
	Vektor<int> vektor10(100, 1);
	EXPECT_FALSE(vektor5 == vektor6);
}

TEST(CopyAssignmentOperatorTest, StandardCopy) {
	Vektor<int> vektor1(10, 10);
	Vektor<int> vektor2(20, 20);
	vektor1 = vektor2;
	EXPECT_TRUE(vektor1 == vektor2);
}

// Test move constructor and move assignment operator




