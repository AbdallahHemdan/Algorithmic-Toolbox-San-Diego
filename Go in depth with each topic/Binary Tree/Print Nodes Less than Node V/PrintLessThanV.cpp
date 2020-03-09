// function that prints all the keys that are less than a given value, V, in a binary tree.
void PrintSmaller(Node* subRoot, int Value){
	if(subRoot == nullptr)
		return 0;
	if(subRoot->getData() < Value)
		cout << subRoot->getData() << " " ;
		
	PrintSmaller(subRoot->getLeft());
	PrintSmaller(subRoot->getRight());
}
