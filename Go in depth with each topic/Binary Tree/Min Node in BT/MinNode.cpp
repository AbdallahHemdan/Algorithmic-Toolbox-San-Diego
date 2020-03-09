// function that returns the min value of all the nodes in a binary tree. Assume
// all values are non-negative; return -1 if the tree is empty
int MinNode(){
	return Rec_MinNode(root);
}
int Rec_MinNode(Node* subRoot){
	if(subRoot == null)
		return -1 ; 
	int Mini_1 = subRoot->getData();
	int Mini_2 = Rec_MinNode(subRoot->getLeft());
	int Mini_3 = Rec_MinNode(subRoot->getRight());

	return min(Mini_1,min(Mini_2,Mini_3));
}
