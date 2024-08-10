//////////////////////////////////////////////////////////////////
//
// Unit tests για τον ADT Priority Queue.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "ADTRecTree.h"
#include "ADTRecTree_Utils.h"


void destroy_full_rectree(RecTree tree){

	if(tree == NULL)
		return;
	
	destroy_full_rectree(rectree_left(tree));
	destroy_full_rectree(rectree_right(tree));
	rectree_destroy(tree);
}


void test_get_subtree(void){
	
	//building the tree
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	RecTree left_subtree = rectree_create(&value1, NULL, NULL);
	RecTree right_subtree = rectree_create(&value2, NULL, NULL);
	RecTree new_left_subtree = rectree_create(&value3, left_subtree, right_subtree);

	int value4 = 6;
	int value5 = 9;
	int value6 = 8;
	left_subtree = rectree_create(&value4, NULL, NULL);
	right_subtree = rectree_create(&value5, NULL, NULL);
	RecTree new_right_subtree = rectree_create(&value6, left_subtree, right_subtree);

	int value7 = 5;
	RecTree rtree_root = rectree_create(&value7, new_left_subtree, new_right_subtree);

	//
	RecTree returned_subtree = rectree_get_subtree(rtree_root, 5);

	TEST_ASSERT(returned_subtree != NULL);
	TEST_ASSERT(rectree_size(returned_subtree) == 1);
	TEST_ASSERT(*(int*)rectree_value(returned_subtree) == 3);


	destroy_full_rectree(rtree_root);
}

void test_rectree_replace_subtree(void){

	//building the tree
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	RecTree left_subtree = rectree_create(&value1, NULL, NULL);
	RecTree right_subtree = rectree_create(&value2, NULL, NULL);
	RecTree new_left_subtree = rectree_create(&value3, left_subtree, right_subtree);

	int value4 = 6;
	int value5 = 9;
	int value6 = 8;
	left_subtree = rectree_create(&value4, NULL, NULL);
	right_subtree = rectree_create(&value5, NULL, NULL);
	RecTree new_right_subtree = rectree_create(&value6, left_subtree, right_subtree);

	int value7 = 5;
	RecTree rtree_root = rectree_create(&value7, new_left_subtree, new_right_subtree);

	int value8 = 29;
	RecTree subtree_replacement = rectree_create(&value8, NULL, NULL);


	RecTree new_rtree_root = rectree_replace_subtree(rtree_root, 3, subtree_replacement);

	RecTree returned_subtree = rectree_get_subtree(new_rtree_root, 1);
	printf("\n\n *(int*)rectree_value(returned_subtree) = %d \n\n", *(int*)rectree_value(returned_subtree));
	TEST_ASSERT(*(int*)rectree_value(returned_subtree) == 29);
	printf("\n\n rectree_size(returned_subtree) = %d \n\n", rectree_size(returned_subtree));
	TEST_ASSERT(rectree_size(returned_subtree) == 1);
	printf("\n\n rectree_size(new_rtree_root) = %d \n\n", rectree_size(new_rtree_root));
	TEST_ASSERT(rectree_size(new_rtree_root) == 5);
	printf("\n\n here2 \n\n");

	destroy_full_rectree(returned_subtree);

}



// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "test_get_subtree", test_get_subtree},
	{ "test_rectree_replace_subtree", test_rectree_replace_subtree},

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};
