# Κάνοντας compile το <foo>_test.c με μια υλοποίηση <foo>.c του
# συγκεκριμένου τύπου, παράγουμε ένα tets για την υλοποίηση αυτή.

# Υλοποιήσεις μέσω Heap: ADTPriorityQueue
# Το Heap χρησιμοποιεί Vector, οπότε χρειαζόμαστε και μια υλοποίηση του ADTVector.
#
UsingHeap_ADTPriorityQueue_test_OBJS  = ADTPriorityQueue_test.o $(MODULES)/UsingHeap/ADTPriorityQueue.o $(MODULES)/UsingDynamicArray/ADTVector.o

UsingLinkedTree_ADTRecTree_test_OBJS = ADTRecTree_test.o $(MODULES)/UsingLinkedTree/ADTRecTree_alt.o $(MODULES)/UsingADTSet/ADTMap.o $(MODULES)/UsingBinarySearchTree/ADTSet.o

#UsingLinkedTree_ADTRecTree_test_OBJS = ADTRecTree_test.o $(MODULES)/UsingLinkedTree/ADTRecTree.o

#UsingLinkedTree_ADTRecTree_utils_test_OBJS = ADTRecTree_utils_test.o $(MODULES)/ADTRecTree_utils.o $(MODULES)/UsingADTSet/ADTMap.o $(MODULES)/UsingLinkedTree/ADTRecTree_alt.o $(MODULES)/UsingDynamicArray/ADTVector.o $(MODULES)/UsingBinarySearchTree/ADTSet.o

UsingLinkedTree_ADTRecTree_utils_test_OBJS = ADTRecTree_utils_test.o $(MODULES)/ADTRecTree_utils.o  $(MODULES)/UsingLinkedTree/ADTRecTree.o $(MODULES)/UsingDynamicArray/ADTVector.o
# Ο βασικός κορμός του Makefile
include ../common.mk