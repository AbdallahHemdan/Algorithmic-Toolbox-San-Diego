//Q: Check if a binary tree is a binary-search-tree
// My approach is to use In-Order traversal to get the ascending order of the nodes
// then check if the nodes in ascending order or not 

	vector<int> Nodes; 

	 void In_Order_Traversal(Node* subRoot) {
		if (subRoot == nullptr)
			return;
		In_Order_Traversal(subRoot->getLeft());
		Nodes.push_back(subRoot->getData());
		In_Order_Traversal(subRoot->getRight());
	}

	void Check_BST_Or_Not(Node* subRoot) {
		In_Order_Traversal(subRoot); 
		for (int i = 0; i < Nodes.size() - 1; i++) {
			// check if there is nodes violent the right order
			if (Node[i] >= Node[i + 1])
				return false; 
		}
		return true; 
	}
