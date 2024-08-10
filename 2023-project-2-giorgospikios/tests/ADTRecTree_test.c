//////////////////////////////////////////////////////////////////
//
// Unit tests για τον ADT Priority Queue.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "ADTRecTree.h"


void destroy_full_rectree(RecTree tree){

	if(tree == NULL)
		return;
	
	destroy_full_rectree(rectree_left(tree));
	destroy_full_rectree(rectree_right(tree));
	rectree_destroy(tree);
}


void test_create(void){

	//χτιζω το δεντρο
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	RecTree left_subtree = rectree_create(&value1, REC_TREE_EMPTY, REC_TREE_EMPTY);
	RecTree right_subtree = rectree_create(&value2, REC_TREE_EMPTY, REC_TREE_EMPTY);
	RecTree new_left_subtree = rectree_create(&value3, left_subtree, right_subtree);

	int value4 = 6;
	int value5 = 9;
	int value6 = 8;
	left_subtree = rectree_create(&value4, REC_TREE_EMPTY, REC_TREE_EMPTY);
	right_subtree = rectree_create(&value5, REC_TREE_EMPTY, REC_TREE_EMPTY);
	RecTree new_right_subtree = rectree_create(&value6, left_subtree, right_subtree);

	int value7 = 5;
	RecTree rtree_root = rectree_create(&value7, new_left_subtree, new_right_subtree);





	TEST_ASSERT(rtree_root != REC_TREE_EMPTY);
	TEST_ASSERT(rectree_size(new_right_subtree) == 3);
	TEST_ASSERT(*(int*)rectree_value(new_right_subtree) == 8);

	RecTree tmp_rectree = rectree_left(new_right_subtree);
	TEST_ASSERT(rectree_size(tmp_rectree) == 1);
	TEST_ASSERT(*(int*)rectree_value(tmp_rectree) == 6);



	TEST_ASSERT(*(int*)rectree_value(rtree_root) == 5);
	TEST_ASSERT(rectree_size(rtree_root) == 7);
	TEST_ASSERT(*(int*)rectree_value(rectree_left(rtree_root)) == 4);
	TEST_ASSERT(*(int*)rectree_value(rectree_right(rtree_root)) == 8);

	destroy_full_rectree(rtree_root);
}



// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "test_create", test_create },

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};
