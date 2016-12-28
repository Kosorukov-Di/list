#include "tstack.h"

#include <gtest.h>

TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> st);
}

TEST(TStack, can_copy_empty_stack)
{
	TStack<int> st;

	ASSERT_NO_THROW(TStack<int> copyst(st));
}

TEST(TStack, new_stack_is_empty)
{
	TStack<int> st;

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, can_push_elem)
{
	TStack<int> st;

	ASSERT_NO_THROW(st.Push(3));
}

TEST(TStack, not_empty)
{
	TStack<int> st;

	st.Push(3);

	EXPECT_EQ(false, st.IsEmpty());
}

TEST(TStack, can_clear_empty_stack)
{
	TStack<int> st;

	ASSERT_NO_THROW(st.Clr());
}

TEST(TStack, can_clear)
{
	TStack<int> st;

	st.Push(3);

	ASSERT_NO_THROW(st.Clr());
}

TEST(TStack, clear_stack_is_empty)
{
	TStack<int> st;

	st.Push(3);
	st.Clr();

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, can_top_elem)
{
	TStack<int> st;

	st.Push(3);

	EXPECT_EQ(3,st.Top());
}

TEST(TStack, can_pop_elem)
{
	TStack<int> st;

	st.Push(3);

	EXPECT_EQ(3,st.Pop());
}

TEST(TStack, elem_delete_after_pop)
{
	TStack<int> st;

	st.Push(3);
	st.Pop();

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, push_and_pop)
{
	TStack<int> st;

	for(int i=0;i<10;i++) st.Push(i);
	for(int i=9;i>=0;i--) 
		EXPECT_EQ(i, st.Pop());	
}