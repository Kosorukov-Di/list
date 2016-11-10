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

TEST(TStack, can_put_elem)
{
	TStack<int> st;

	ASSERT_NO_THROW(st.Put(3));
}

TEST(TStack, not_empty)
{
	TStack<int> st;

	st.Put(3);

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

	st.Put(3);

	ASSERT_NO_THROW(st.Clr());
}

TEST(TStack, clear_stack_is_empty)
{
	TStack<int> st;

	st.Put(3);
	st.Clr();

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, can_look_elem)
{
	TStack<int> st;

	st.Put(3);

	EXPECT_EQ(3,st.Look());
}

TEST(TStack, can_get_elem)
{
	TStack<int> st;

	st.Put(3);

	EXPECT_EQ(3,st.Get());
}

TEST(TStack, elem_delete_after_get)
{
	TStack<int> st;

	st.Put(3);
	st.Get();

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, Put_and_Get)
{
	TStack<int> st;

	for(int i=0;i<10;i++) st.Put(i);
	for(int i=9;i>=0;i--) 
		EXPECT_EQ(i, st.Get());	
}