#include "pch.h"
#include "../Vektor/include/vektor.h"

TEST(InitializationTest, DefaultConstructor) {
	Vektor vektor;
	EXPECT_TRUE(vektor.empty());
	EXPECT_EQ(vektor.size(), 0);
	EXPECT_EQ(vektor.capacity(), 10);
}

TEST(InitializationTest, SizeConstructor) {
	Vektor vektor(1);
	EXPECT_FALSE(vektor.empty());
	EXPECT_EQ(vektor.size(), 1);
	EXPECT_EQ(vektor.capacity(), 2);

	Vektor vektor1(10);
	EXPECT_FALSE(vektor1.empty());
	EXPECT_EQ(vektor1.size(), 10);
	EXPECT_EQ(vektor1.capacity(), 20);

	Vektor vektor2(0);
	EXPECT_EQ(vektor2.size(), 0);
	EXPECT_EQ(vektor2.capacity(), 10);
	
	EXPECT_DEATH(Vektor vektor3(-1), ".*");
}

TEST(InitializationTest, SizeAndValueConstructor) {
	Vektor vektor(10, 20);
	EXPECT_FALSE(vektor.empty());
	EXPECT_EQ(vektor.size(), 10);
	EXPECT_EQ(vektor.capacity(), 20);
	for (unsigned i = 0; i < vektor.size(); ++i)
		EXPECT_EQ(vektor[i], 20);

	Vektor vektor1(5, -1);
	EXPECT_FALSE(vektor1.empty());
	EXPECT_EQ(vektor1.size(), 5);
	EXPECT_EQ(vektor1.capacity(), 10);
	for (unsigned i = 0; i < vektor1.size(); ++i)
		EXPECT_EQ(vektor1[i], -1);

	//EXPECT_DEATH(Vektor vektor2(-10, -10), ".*");

}

TEST(AccesorsTest, GetFirstElementEmpty) {
	Vektor vektor;
	EXPECT_DEATH(vektor.front(), ".*");

	Vektor vektor1(0);
	EXPECT_DEATH(vektor1.front(), ".*");
}

TEST(AccesorsTest, GetFirstElementNonEmpty) {
	Vektor vektor(1, 1);
	EXPECT_EQ(vektor.front(), 1);
	Vektor vektor1(10, -1);
	EXPECT_EQ(vektor1.front(), -1);
}

TEST(AccessorsTest, GetLastElementEmpty) {
	Vektor vektor;
	EXPECT_DEATH(vektor.back(), ".*");
	Vektor vektor1(10, -10);
	EXPECT_EQ(vektor1.front(), -10);

}

TEST(AccessorsTest, IndexingEmptyVektor) {
	Vektor vektor;
	EXPECT_DEATH(vektor[0], ".*");
	EXPECT_DEATH(vektor[20], ".*");

	Vektor vektor1(0);
	EXPECT_DEATH(vektor1[0], ".*");
	EXPECT_DEATH(vektor1[20], ".*");
}

TEST(AccessorsTest, IndexingNegativeIndex) {
	Vektor vektor;
	EXPECT_DEATH(vektor[-1], ".*");
	EXPECT_DEATH(vektor[-10], ".*");

	Vektor vektor1(0);
	EXPECT_DEATH(vektor1[-1], ".*");
	EXPECT_DEATH(vektor1[-11], ".*");
}

TEST(AccessorsTest, IndexingOutOfBounds) {
	Vektor vektor;
	EXPECT_DEATH(vektor[1], ".*");
	EXPECT_DEATH(vektor[10], ".*");

	Vektor vektor1(10, 20);
	EXPECT_DEATH(vektor1[10], ".*");
	EXPECT_DEATH(vektor1[100], ".*");
}

TEST(AccessorsTest, IndexingValidIndex) {
	Vektor vektor(10, 10);
	EXPECT_EQ(vektor[0], 10);
	EXPECT_EQ(vektor[9], 10);

	Vektor vektor1(1);
	EXPECT_EQ(vektor1[0], 0);

	Vektor vektor2(1, 10);
	EXPECT_EQ(vektor1[0], 10);
}



