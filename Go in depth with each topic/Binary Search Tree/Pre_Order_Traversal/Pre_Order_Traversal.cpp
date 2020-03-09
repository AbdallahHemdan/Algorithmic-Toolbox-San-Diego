void Pre_Order_Traversal(Node* subRoot){
	if(subRoot == nullptr)
		return ;
	cout << subRoot->getData() <<  " " ;
	Pre_Order_Traversal(subRoot->getLeft());
	Pre_Order_Traversal(subRoot->getRight());
}
