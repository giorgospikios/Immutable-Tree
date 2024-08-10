#include <stdlib.h>
#include <stdio.h>
#include "ADTVector.h"
#include "ADTMap.h"
#include "ADTRecTree_Utils.h"


static bool flag1 = false;
static bool flag2 = false;
static Vector steps_to_root;
static Vector root_to_pos;
int pos_indicator;
static RecTree holding_new_subtree;


int* create_int(int value) {
	int* p = malloc(sizeof(int));
	*p = value;
	return p;
}

RecTree rectree_get_subtree(RecTree tree, int pos) // επειδη ηταν πολλες οι λεπτομερειες τις περιεγραψα ολες στο readme σαν εκτελεση και σκεψη
{ 
	if(flag1 == false){

		int temp_pos = pos;
		steps_to_root = vector_create(0, free);
		while(temp_pos > 1){

			if(temp_pos % 2 == 0)
				vector_insert_last(steps_to_root, create_int(2));
			else
				vector_insert_last(steps_to_root, create_int(1));

			temp_pos = temp_pos/2;
		}
		flag1 = true;
	}

	if(tree == REC_TREE_EMPTY)
		return REC_TREE_EMPTY;
	else
		if(vector_size(steps_to_root) == 0)
			return tree;

	int left_or_right_index;
	left_or_right_index = *(int*)vector_node_value(steps_to_root, vector_last(steps_to_root));
	vector_remove_last(steps_to_root);
	// if(vector_size(steps_to_root) == 0) //το εχω κανει κομμεντ γιατι νομιζω οτι πρεπει να το κανω destroy οταν αδειασει αλλα αντιμετοπιζα συνεχεια
	// 	vector_destroy(steps_to_root);	   //seg fault
	

	if(left_or_right_index == 2)
		return rectree_get_subtree(rectree_left(tree), pos);
	else
		return rectree_get_subtree(rectree_right(tree), pos);
}

RecTree rectree_replace_subtree(RecTree tree, int pos, RecTree subtree)
{
	if(flag2 == false){

		int temp_pos = pos;
		root_to_pos = vector_create(0, free);
		while(temp_pos > 1){

			if(temp_pos % 2 == 0)
				vector_insert_last(root_to_pos, create_int(2));
			else
				vector_insert_last(root_to_pos, create_int(1));

			temp_pos = temp_pos/2;
		}
		flag2 = true;
	}

	if(tree == REC_TREE_EMPTY)
		return REC_TREE_EMPTY;
	else
		if(vector_size(root_to_pos) == 0){
			rectree_destroy(tree);
			pos_indicator++;

			return tree;
		}
			

	int left_or_right_index;
	left_or_right_index = *(int*)vector_node_value(root_to_pos, vector_last(root_to_pos));
	vector_remove_last(root_to_pos);
	// if(vector_size(steps_to_root) == 0) //το εχω κανει κομμεντ γιατι νομιζω οτι πρεπει να το κανω destroy οταν αδειασει αλλα αντιμετοπιζα συνεχεια
	// 	vector_destroy(steps_to_root);	   //seg fault


	if(left_or_right_index == 2){
		rectree_replace_subtree(rectree_left(tree), pos, subtree);

		if(pos_indicator == 1){
			RecTree new_rectree = rectree_create(rectree_value(tree), subtree, rectree_right(tree));
			holding_new_subtree = new_rectree;

			pos_indicator--;
			rectree_destroy(tree);
			return holding_new_subtree;
			
		}
		else{
			RecTree new_rectree = rectree_create(rectree_value(tree) ,rectree_left(holding_new_subtree), rectree_right(tree));
			holding_new_subtree = new_rectree;

			rectree_destroy(tree);
			return holding_new_subtree;
		}

	}
	else{
		rectree_replace_subtree(rectree_right(tree), pos, subtree);

		if(pos_indicator == 1){
			RecTree new_rectree = rectree_create(rectree_value(tree), subtree, rectree_right(tree));
			holding_new_subtree = new_rectree;
			
			pos_indicator--;
			rectree_destroy(tree);
			return holding_new_subtree;
		}
		else{
			RecTree new_rectree = rectree_create(rectree_value(tree), rectree_left(tree), rectree_right(holding_new_subtree));
			holding_new_subtree = new_rectree;

			rectree_destroy(tree);
			return holding_new_subtree;
		}
	}

}

