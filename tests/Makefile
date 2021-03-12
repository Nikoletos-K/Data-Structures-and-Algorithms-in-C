# Κάνοντας compile το <foo>_test.c με μια υλοποίηση <foo>.c του
# συγκεκριμένου τύπου, παράγουμε ένα tets για την υλοποίηση αυτή.

HashFunctions_test_OBJS  = HashFunctions_test.o $(MODULES)/HashFunctions/HashFunctions.o
BloomFilter_test_OBJS  = BloomFilter_test.o $(MODULES)/BloomFilter/BloomFilter.o $(MODULES)/HashFunctions/HashFunctions.o
List_test_OBJS = List_test.o $(MODULES)/List/List.o
Queue_test_OBJS = Queue_test.o $(MODULES)/Queue/Queue.o
RBTree_test_OBJS = RBTree_test.o $(MODULES)/RBTree/RBTree.o
DisJointSet_test_OBJS = DisJointSet_test.o $(MODULES)/DisJointSet/DisJointSet.o
HashTable_test_OBJS = HashTable_test.o $(MODULES)/HashTable_withRBT/HashTable.o $(MODULES)/RBTree/RBTree.o



# Dataset_test_OBJS  = Dataset_test.o ./../programs/EntityResolution/Vectorization.o  $(MODULES)/Dataset/Dataset.o
# LogisticRegression_test_OBJS  = LogisticRegression_test.o 	./../programs/EntityResolution/Vectorization.o $(MODULES)/BitArray/bitArray.o  $(MODULES)/LogisticRegression/LogisticRegression.o
# LogisticRegression_test_OBJS  = LogisticRegression_test.o   $(MODULES)/LogisticRegression/LogisticRegression.o  $(MODULES)/JobScheduler/JobScheduler.o $(MODULES)/Queue/Queue.o

# Json_test_OBJS = 																									\
# 	Json_test.o ./../programs/EntityResolution/CamSpec.o 											\
# 	./../programs/EntityResolution/Clique.o 							\
# 	./../programs/EntityResolution/Vectorization.o 					\
# 	./../programs/EntityResolution/PairsImplementation.o 				\
# 	./../programs/EntityResolution/dictionary.o 										\
# 	./../programs/EntityResolution/utils.o 		  		 									\
# 	$(MODULES)/LogisticRegression/LogisticRegression.o 								  					\
# 	$(MODULES)/JobScheduler/JobScheduler.o 								  					\
# 	$(MODULES)/List/list.o 		 																		\
# 	$(MODULES)/DisJointSet/DisJointSet.o 																			\
# 	$(MODULES)/HashTable/HashTable.o  																		\
# 	$(MODULES)/RBTree/RBTree.o 																			\
# 	$(MODULES)/BitArray/bitArray.o  																		\
# 	$(MODULES)/Queue/Queue.o  																		\
# 	$(MODULES)/Dataset/Dataset.o 		

# Makefile main body
include ../common.mk
