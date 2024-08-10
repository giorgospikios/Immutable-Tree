///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT RecTree μέσω links
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "ADTRecTree.h"
#include "ADTMap.h"


static Map tree_to_value;
static Map tree_to_left_subtree;
static Map tree_to_right_subtree;
static Map tree_to_size;


static Pointer counter; //αντιπροσωπευει το καθε δεντρο


int compare_pointers(Pointer a, Pointer b)
{
	return a - b; //συγκρινει τους Pointers ως θεσεις μνημης αφου το καθε rectree αντιστοιχιζεται με μια θεση μνημης
}


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

RecTree rectree_create(Pointer value, RecTree left, RecTree right) {

	if(counter == REC_TREE_EMPTY){ //δημιουργειται μονο μια φορα το καθε map αν δεν υπαρχει δεντρο

		tree_to_value = map_create(compare_pointers, NULL, NULL);
		tree_to_left_subtree = map_create(compare_pointers, NULL, NULL);
		tree_to_right_subtree = map_create(compare_pointers, NULL, NULL);
		tree_to_size = map_create(compare_pointers, NULL, NULL);

	} 

	RecTree rectree = ++counter;//αυξανεται καθε φορα ωστε να 

	map_insert(tree_to_value, rectree, value);
	map_insert(tree_to_left_subtree, rectree, left);
	map_insert(tree_to_right_subtree, rectree, right);

	Pointer size = (Pointer)1; //μετραω το δεντρο(κομβο) αρα συν 1
	if(right != REC_TREE_EMPTY){ //αν το δεξι υποδεντρο δεν ειναι κενο προσεθτει το size του στο παρον δεντρο

		Pointer right_size = map_find(tree_to_size, right);
		size = (Pointer)(size_t)((size_t)size + (size_t)right_size);
	}
	if(left != REC_TREE_EMPTY){ //αν το αριστερο υποδεντρο δεν ειναι κενο προσεθτει το size του στο παρον δεντρο

		Pointer left_size = map_find(tree_to_size, left);
		size = (Pointer)(size_t)((size_t)size + (size_t)left_size);
	}
	map_insert(tree_to_size, rectree, size);
	
	return rectree;
}

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.

int rectree_size(RecTree tree) {

	Pointer size = map_find(tree_to_size, tree);
	return (int)(size_t)size;
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.

void rectree_destroy(RecTree tree) {

	//αν δεν ειναι κενο το δεντρο αφαιρω το δεντρο(κομβο) εφοσον ειναι immutable και δεν επιτρεπεται να διαγραφει καποιο subtree αρα διαγραφω απο
	//"πανω προς τα κατω"
	if(rectree_size(tree) != 0){ 
		map_remove(tree_to_value, map_first(tree_to_value));
		map_remove(tree_to_left_subtree, map_first(tree_to_left_subtree));
		map_remove(tree_to_right_subtree, map_first(tree_to_right_subtree));
		map_remove(tree_to_size, map_first(tree_to_size));	
	}
	else{ //οταν ειναι κενο το map το κανω destroy
		map_destroy(tree_to_value);
		map_destroy(tree_to_left_subtree);
		map_destroy(tree_to_right_subtree);
		map_destroy(tree_to_size);
	}
}

// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer rectree_value(RecTree tree) {

	if(tree == REC_TREE_EMPTY)
		return REC_TREE_EMPTY;

	return map_find(tree_to_value, tree);
}

RecTree rectree_left(RecTree tree) {

	if(tree == REC_TREE_EMPTY)
		return REC_TREE_EMPTY;

	return map_find(tree_to_left_subtree, tree);
}

RecTree rectree_right(RecTree tree) {

	if(tree == REC_TREE_EMPTY)
		return REC_TREE_EMPTY;

	return map_find(tree_to_right_subtree, tree);
}

