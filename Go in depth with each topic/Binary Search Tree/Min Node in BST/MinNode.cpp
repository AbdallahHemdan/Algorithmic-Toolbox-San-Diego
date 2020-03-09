int MinNode(){
	return Rec_Min_Node(root);
}
int Rec_Min_Node(Node* subRoot){
	Node* Current = subRoot;
	while(!Current->getLeft){
		Current = Current->getLeft();
	}
	return Current->getData();
}
