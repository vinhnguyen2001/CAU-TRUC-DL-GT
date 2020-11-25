#include"BinaryTree.h"

int main() {

	NODE* root = nullptr;
	/*
	root = createNode(15);
	root->p_left = createNode(10);

	root->p_left->p_left = createNode(4);
	
	root->p_left->p_left->p_left = createNode(3);
	root->p_left->p_left->p_right = createNode(7);


	root->p_left->p_right = createNode(12);
	root->p_left->p_right->p_left = createNode(11);*/
//	root->p_left->p_right->p_right = createNode(14);
	int a[] = { 15,10,33,4,21,12,35,3,7,11,34,27,45 };
	root =createTree(a, 13);
	//root->p_right = createNode(33);
	//root->p_right->p_left = createNode(21);
	//root->p_right->p_left->p_left = createNode(16);
	//root->p_right->p_left->p_right = createNode(27);

	//NODE* P = root->p_right->p_right = createNode(35);
	//root->p_right->p_right->p_left = createNode(34);
	//root->p_right->p_right->p_right = createNode(45);

	/*
	                                         15

                                     /                 \
                                   10                     33

							  /         \             /        \
                            4            12        21          35

						/       \    /       \     /       \     /     \
                      3          7  11       14  16         27 34       45
	
	*/
	/*NODE*t =Search(root, 12);
	cout << "\nvalue: " << t->key;*/

	//Insert(root, 9);

	/*Remove(root, 5);
	LNR(root);*/



	//LevelOrder(root);
	/*
	// Tao cay nhi phan tu mang 

	int a[] = { 4,5,6,8,7,10,12 };
	int n = 7;
    LNR(createTree(a, 7));*/

	/*NODE* cur= root;
	removeTree(cur);*/

	//LNR(root);
	//cout << " Height of the binary search tree: " << Height(root->p_right)<<endl;

//	cout<<" The Number of nodes in binary search tree: " <<countNode(root)<<endl;

	//cout << "TONG CUA CAC PHAN TU: " << sumNode(root);

	/*cout<<" Chieu cua node 10: "<<heightNode(root, 10);*/

	/*cout << "so node la trong 1 cay nhi phan tim kiem: " << countLeaf(root);*/

	int value = 16;
//	cout << "\nso node nho hon gia tri " << value<<": " << countLess(root, value);
	//cout << " v " << root->key;
	//Insert(root, 15);
	//cout << "\nSo node lon hon gia tri " << value << ": "<<countGreater(root, value);
	//(root);
//	cout<<"\n"<<Level(root, P);
	/*
	cout << isBST(root);
	cout << isFullBST(root);*/
	//cout << " v " << root->key;
	//cout << "\n tong " << NumberOfNode(root, 100) << endl;
	NODE*p =insertElement(root, 14);
	p = createNode(13);
	cout << "v " << root->p_left->p_right->p_right->key;
	LevelOrder(root);
	return 0;
}