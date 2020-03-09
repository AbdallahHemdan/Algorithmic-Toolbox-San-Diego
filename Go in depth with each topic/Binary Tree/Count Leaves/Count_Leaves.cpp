int CountLeaves() {
	return Res_CountLeaves(root);
}
int Res_CountLeaves(Node * subRoot) {
	if (subRoot == nullptr)
		return 0; 
	if ((subRoot->getleft() == nullptr) && (subRoot->getright() == nullptr))
		return 1; 
	return Res_CountLeaves(subRoot->getleft()) + Res_CountLeaves(subRoot->getright());
}
