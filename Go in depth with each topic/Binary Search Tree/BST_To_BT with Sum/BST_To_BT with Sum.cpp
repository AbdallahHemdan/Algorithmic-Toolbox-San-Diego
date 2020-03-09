// Convert a BST to a Binary Tree such that sum of all greater keys is added to every key
void BST_To_BT_With_Sum(Node* subRoot, int &Sum){
	if(subRoot == nullptr)
		return ;
	BST_To_BT_With_Sum(subRoot->getLeft(),Sum);
	Sum+= subRoot->getData();
	subRoot->setData(Sum);
	BST_To_BT_With_Sum(subRoot->getRight(),Sum);
}

void BST_TO_BT(){
	int Sum = 0 ; 
	BST_To_BT_With_Sum(root, Sum);
}
