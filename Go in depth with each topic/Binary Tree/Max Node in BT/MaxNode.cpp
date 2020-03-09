// function that returns the maximum value of all the nodes in a binary tree. Assume
// all values are non-negative; return -1 if the tree is empty
int MaxNode(){
	return Rec_MaxNode(root);
}
int Rec_MaxNode(Node* subRoot){
	if(subRoot == null)
		return -1 ; 
	int Maxi_1 = subRoot->getData();
	int Maxi_2 - Rec_MaxNode(subRoot->getLeft());
	int Maxi_3 - Rec_MaxNode(subRoot->getRight());

	return max(Maxi_1,max(Maxi_2,Maxi_3));
}
