#include "tlist.h"

#include <gtest.h>

TEST(TList, can_create_node)
{
	ASSERT_NO_THROW(node<int> nd);
}

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> ls);
}

TEST(TList, new_list_is_empty)
{
	TList<int> ls;

	EXPECT_EQ(true, ls.IsEmpty());
}

TEST(TList, can_print_empty_list)
{
	TList<int> ls;

	ASSERT_NO_THROW(ls.Print());
}

TEST(TList, can_insert_at_begin)
{
	TList<int> ls;
	node<int>* nd=new node<int>;	nd->data=3;

	ASSERT_NO_THROW(ls.InsertAtBegin(nd));
}

TEST(TList, throw_error_beg)
{
	TList<int> ls;
	node<int>* nd=0;

	ASSERT_ANY_THROW(ls.InsertAtBegin(nd));
}

TEST(TList, can_insert_at_end)
{
	TList<int> ls;
	node<int>* nd=new node<int>;	nd->data=3;

	ASSERT_NO_THROW(ls.InsertAtEnd(nd));
}

TEST(TList, throw_error_end)
{
	TList<int> ls;
	node<int>* nd=0;

	ASSERT_ANY_THROW(ls.InsertAtEnd(nd));
}

TEST(TList, can_insert_after_elem)
{
	TList<int> ls;
	node<int>* start=new node<int>;	start->data=3;
	node<int>* nd=new node<int>;	nd->data=3;

	ls.InsertAtBegin(start);

	ASSERT_NO_THROW(ls.Insert(start, nd));
}

TEST(TList, throw_error_ins)
{
	TList<int> ls;
	node<int>* start=new node<int>;	start->data=3;
	node<int>* nd=0;

	ls.InsertAtBegin(start);

	ASSERT_ANY_THROW(ls.Insert(start, nd));
}

TEST(TList, xxx_insert)
{
	TList<int> ls;
	node<int>* first=new node<int>;		first->data=0;
	node<int>* second=new node<int>;	second->data=1;

	ls.InsertAtBegin(first);
	for(int i=2;i<10;i++)
	{
		ls.Insert(first, second);
		first=second;
		second=new node<int>;	second->data=i;
	}
	ls.Print();

	ASSERT_NO_THROW(ls.InsertAtEnd(second));
}

TEST(TList, can_delete_at_begin)
{
	TList<int> ls;
	node<int>* first=new node<int>;		first->data=0;
	node<int>* second=new node<int>;	second->data=1;

	ls.InsertAtBegin(first);
	ls.Insert(first, second);

	ASSERT_NO_THROW(ls.DeleteAtBegin());
	ls.Print();
}

TEST(TList, can_delete_at_end)
{
	TList<int> ls;
	node<int>* first=new node<int>;		first->data=0;
	node<int>* second=new node<int>;	second->data=1;

	ls.InsertAtBegin(first);
	ls.Insert(first, second);

	ASSERT_NO_THROW(ls.DeleteAtEnd());
	ls.Print();// "0"
}

TEST(TList, can_delete_after_elem)
{
	TList<int> ls;
	node<int>* first=new node<int>;		first->data=0;
	node<int>* second=new node<int>;	second->data=1;
	node<int>* third=new node<int>;		third->data=2;

	ls.InsertAtBegin(first);
	ls.Insert(first, second);
	ls.Insert(second, third);

	ASSERT_NO_THROW(ls.Delete(first));
	ls.Print();
}

TEST(TList, search_in_white_list)
{
	TList<int> ls;

	EXPECT_EQ(0, ls.Search(3));
}

TEST(TList, search_elem)
{
	TList<int> ls;
	node<int>* first=new node<int>;		first->data=0;
	node<int>* second=new node<int>;	second->data=1;
	node<int>* third=new node<int>;		third->data=2;
	ls.InsertAtBegin(first);
	ls.Insert(first, second);
	ls.InsertAtEnd(third);

	EXPECT_EQ(second, ls.Search(1));
}