void InsertBST(int Key){
	Rec_InsertBST(Node* subRoot, int Key);
}
void Rec_InsertBST(Node*& subRoot, int Key){
	if(subRoot == nullptr){
		SubRoot = new Node(Key);
	} else if (subRoot->getData() < Key){
		InsertBST(subRoot->getRight(),Key);	
	} else{
		InsertBST(subRoot->getLeft(),Key);	
	}
}
