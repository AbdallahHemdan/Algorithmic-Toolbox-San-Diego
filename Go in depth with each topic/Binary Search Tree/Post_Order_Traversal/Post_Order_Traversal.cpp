void Post_Order_Traversal(Node* subRoot) {
	if(subRoot == nullptr)
		return ;
	Post_Order_Traversal(subRoot->getLeft());
	Post_Order_Traversal(subRoot->getRight());
	cout << subRoot->getData() << " " ;
}
