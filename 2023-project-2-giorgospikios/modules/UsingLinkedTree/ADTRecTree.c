///////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT RecTree μέσω links
//
///////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "ADTRecTree.h"



//  Ένα δέντρο είναι pointer σε αυτό το struct
struct rec_tree {
	Pointer value;
	RecTree left;
	RecTree right;
	int size;
};


// Δημιουργεί και επιστρέφει ένα νέο δέντρο, με τιμή (στη ρίζα) value και υποδέντρα left και right.

RecTree rectree_create(Pointer value, RecTree left, RecTree right) {

	RecTree rectree = malloc(sizeof(*rectree));
	if(rectree == NULL){
		printf("\n\n ERROR: NOT AVAILABLE MEMORY \n\n");
		assert(rectree == NULL);
	}

	rectree->size++; //αυξανω συν 1 το size γιατι μετραω το δεντρο(κομβο) που δημιουργησα

	rectree->value = value;
	rectree->left = left;
	rectree->right = right;
	if(rectree->left != REC_TREE_EMPTY)
		rectree->size += left->size; //αν το αριστερο δεντρο δεν ειναι κενο το προσθετω
	if(rectree->right != REC_TREE_EMPTY)
		rectree->size += right->size; //αν το δεξι δεντρο δεν ειναι κενο το προσθετω

	return rectree;
}

// Επιστρέφει τον αριθμό στοιχείων που περιέχει το δέντρο.

int rectree_size(RecTree tree) {
	
	if(tree == REC_TREE_EMPTY)
		return 0;
	
	return tree->size;
}

// Ελευθερώνει όλη τη μνήμη που δεσμεύει το δέντρο tree.

void rectree_destroy(RecTree tree) {

	free(tree); //κανω μονο free γιατι η εκφωνηση θελει πολυπλοκοτητα Ο(1) και εχω χτισει μια αναδρομικη συναρτηση στο unit test destroy_full_rectree
				//ακομα επειδη τα δεντρα ειναι immutables σκεφτηκα οτι θα βολευει περισσοτερο ετσι ωστε να μπορω να ελε
}

// Επιστρέφουν την τιμή (στη ρίζα), το αριστερό και το δεξί υποδέντρο του δέντρου tree.

Pointer rectree_value(RecTree tree) {

	if(tree == REC_TREE_EMPTY)
		return REC_TREE_EMPTY;

	return tree->value;
}

RecTree rectree_left(RecTree tree) {
	
	if(tree == REC_TREE_EMPTY)
		return REC_TREE_EMPTY;

	return tree->left;
}

RecTree rectree_right(RecTree tree) {
	
	if(tree == REC_TREE_EMPTY)
		return REC_TREE_EMPTY;

	return tree->right;
}

