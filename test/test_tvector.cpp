#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> s1(3);
	for (int i = 0; i < s1.GetSize(); i++)
		s1[i] = i;
	TVector<int> s2(s1);
	EXPECT_EQ(s1, s2);
}

TEST(TVector, copied_vector_has_its_own_memory) // у скопированного вектора своя память
{
	TVector<int>* s;
	s = new TVector<int>(3);
	int a = (*s).GetSize();
	for (int i = 0; i < a; i++)
		(*s)[i] = i;
	TVector<int> s1(*s);
	delete s;
	int b = s1.GetSize();
	EXPECT_EQ(a, b);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[-1] = 100);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[5] = 100);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> s(3);
	for (int i = 0; i < 3; i++)
		s[i] = i;
	s = s;

	EXPECT_EQ(0, s[0]);
	EXPECT_EQ(1, s[1]);
	EXPECT_EQ(2, s[2]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> s1(3), s2(3);
	for (int i = 0; i < 3; i++)
		s1[i] = i;
	s2 = s1;

	EXPECT_EQ(s2, s1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	const int size = 10;
	TVector<int> s(size);

	EXPECT_EQ(10, s.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> s1(3), s2(5);
	for (int i = 0; i < 3; i++)
		s1[i] = i;
	s2 = s1;

	EXPECT_EQ(s1, s2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> s1(3), s2(3);
	for (int i = 0; i < 3; i++) {
		s1[i] = 1;
		s2[i] = 1;
	}

	ASSERT_TRUE(s1 == s2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> s(3);
	for (int i = 0; i < 3; i++)
		s[i] = i;

	ASSERT_TRUE(s == s);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> s1(3), s2(5);
	for (int i = 0; i < 3; i++)
		s1[i] = i;
	for (int i = 0; i < 5; i++)
		s2[i] = i;

	ASSERT_FALSE(s1 == s2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> s(3);
	for (int i = 0; i < 3; i++)
		s[i] = 0;
	const int value = 35;
	s = s + value;

	EXPECT_EQ(35, s[0]);
	EXPECT_EQ(35, s[1]);
	EXPECT_EQ(35, s[2]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> s(3);
	for (int i = 0; i < 3; i++)
		s[i] = 5;
	const int value = 3;
	s = s - value;

	EXPECT_EQ(2, s[0]);
	EXPECT_EQ(2, s[1]);
	EXPECT_EQ(2, s[1]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> s(3);
	for (int i = 0; i < 3; i++)
		s[i] = 2;
	const int value = 2;
	s = s * value;

	EXPECT_EQ(4, s[0]);
	EXPECT_EQ(4, s[1]);
	EXPECT_EQ(4, s[2]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> s1(3), s2(3);
	for (int i = 0; i < 3; i++) {
		s1[i] = 1;
		s2[i] = 2;
	}
	TVector<int> res = s1 + s2;
	
	EXPECT_EQ(3, res[0]);
	EXPECT_EQ(3, res[1]);
	EXPECT_EQ(3, res[2]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> s1(5), s2(10);
	for (int i = 0; i < 5; i++) 
		s1[i] = 1;
	for (int i = 0; i < 10; i++)
		s2[i] = 2;
	TVector<int> res;

	ASSERT_ANY_THROW(res = s1 + s2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> s1(3), s2(3);
	for (int i = 0; i < 3; i++) {
		s1[i] = 1;
		s2[i] = 2;
	}
	TVector<int> res = s1 + s2;

	EXPECT_EQ(3, res[0]);
	EXPECT_EQ(3, res[1]);
	EXPECT_EQ(3, res[2]);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> s1(5), s2(10);
	for (int i = 0; i < 5; i++)
		s1[i] = 1;
	for (int i = 0; i < 10; i++)
		s2[i] = 2;
	TVector<int> res;

	ASSERT_ANY_THROW(res = s1 - s2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> s1(3), s2(3);
	for (int i = 0; i < 3; i++) {
		s1[i] = 1;
		s2[i] = 2;
	}

	int res = s1 * s2;

	EXPECT_EQ(6, res);

}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> s1(3), s2(4);
	for (int i = 0; i < 3; i++)
		s1[i] = 1;
	for (int i = 0; i < 4; i++)
		s2[i] = 2;
	TVector<int> res;

	ASSERT_ANY_THROW(res = s1 * s2);
}

