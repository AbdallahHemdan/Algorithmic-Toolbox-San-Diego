bool Is_Identical(BSTree & Another_Tree){
	return Rec_Is_Identical(root, Another_Tree.root);
}

bool Rec_Is_Identical(Node* subRoot, Node* anotherRoot){
	if(subRoot == nullptr && anotherRoot == nullptr)
		return true;
	if((subRoot == nullptr && anotherRoot != nullptr) ||  (subRoot != nullptr && anotherRoot == nullptr))
		return false;
	if(subRoot->getData() == anotherRoot->getData())
		return (Rec_Is_Identical(subRoot->getLeft(),anotherRoot->getLeft()) && Rec_Is_Identical(subRoot->getRight(),anotherRoot->getRight())) ; 
	else
		return false;
}
