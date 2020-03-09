int SumOfNodes(Node* subRoot){
	if(subRoot == nullptr)
		return 0 ; 
	return (subRoot->getData() + SumOfNodes(subRoot->getLeft()) + SumOfNodes(subRoot->getRight())) ; 
}
