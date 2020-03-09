//function that counts the number of leaves that contain even values in a binary tree.
int CountEvenLeaves(){
	return Rec_CountEvenLeaves(root);
}
int Rec_CountEvenLeaves(Node* subRoot){
	if(subRoot == nullptr)
		return 0;
	if(!(subRoot->getLeft()) && !(subRoot->getRight())
		return (subRoot->getData() % 2 == 0) ; 
	return Rec_CountEvenLeaves(subRoot->getLeft()) + Rec_CountEvenLeaves(subRoot->getRight()) ; 
}
