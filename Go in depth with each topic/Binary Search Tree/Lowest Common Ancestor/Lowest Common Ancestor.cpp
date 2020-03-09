// Find the lowest common ancestor of 2 nodes
int Lowest_Common_Ancestor(Node* subRoot, int Node1, int Node2){
	if(subRoot == nullptr)
		return ;
	if(subRoot->getData() > Node1 && subRoot->getData() > Node2){
		return Lowest_Common_Ancestor(subRoot->getLeft(),Node1,Node2);
	}
	if(subRoot->getData() < Node1 && subRoot->getData() < Node2){
		return Lowest_Common_Ancestor(subRoot->getRight(),Node1,Node2);
	}
	return subRoot->getData();
}
