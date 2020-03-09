void Zig_Zag() {
	Zig_Zag_Print(root);
}

void Zig_Zag_Print(Node* subRoot) {
	int Height = GetHeight(subRoot); 
	bool Flag = false; 
	for (int i = 1; i <= Height; i++) {
		if (Flag) {
			Print_Right_To_Left(subRoot, i); 
			Flag = false;
		}
		else {
			Print_Left_To_Right(subRoot, i);
			Flag = true; 
		}
	}
}

int GetHeight(Node* subRoot) {
	if (subRoot == nullptr)
		return;

	int Height_Left = GetHeight(subRoot->getleft()); 
	int Height_Right = GetHeight(subRoot->getright());
	
	return max(Height_Left, Height_Right); 
}

void Print_Right_To_Left(Node* subRoot, int Level) {
	if (subRoot == nullptr)
		return;
	if (Level == 1)
		cout << subRoot->getData() << " ";
	else if (Level > 1) {
		Print_Right_To_Left(subRoot->getRight(), Level - 1);
		Print_Right_To_Left(subRoot->getLeft(), Level - 1);
	}
}
void Print_Left_To_Right(Node* subRoot, int Level) {
	if (subRoot == nullptr)
		return;
	if (Level == 1)
		cout << subRoot->getData() << " ";
	else if (Level > 1) {
		Print_Left_To_Right(subRoot->getLeft(), Level - 1);
		Print_Left_To_Right(subRoot->getRight(), Level - 1);
	}
}

