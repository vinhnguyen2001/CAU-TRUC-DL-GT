#include"BinaryTree.h"

int main() {

	NODE* root = nullptr;
	
	/*root = createNode(15);
	root->p_left = createNode(10);

	root->p_left->p_left = createNode(4);
	
	root->p_left->p_left->p_left = createNode(3);
	root->p_left->p_left->p_right = createNode(7);

	root->p_left->p_right = createNode(12);
	root->p_left->p_right->p_left = createNode(11);
	root->p_left->p_right->p_right = createNode(14);

	root->p_right = createNode(33);
	root->p_right->p_left = createNode(21);
	root->p_right->p_left->p_left = createNode(16);
	root->p_right->p_left->p_right = createNode(27);

	NODE* P = root->p_right->p_right = createNode(35);
	root->p_right->p_right->p_left = createNode(34);
	root->p_right->p_right->p_right = createNode(45);*/


	int a[] = { 15,10,33,4,12,21,35,3,7,11,16,27,34,45 };

	// tao cay 

	root = createTree(a, 14);

	/*
	                                         15

                                       /              \

                                   10                     33

							  /         \             /        \
                            4            12        21          35

						/       \    /       \     /       \     /     \
                      3          7  11           16         27 34       45
	
	*/

	cout << "\nIN CAY THEO NLR: ";
	NLR(root);

	cout << "\nIN CAY THEO LRN: ";
	LRN(root);

	cout << "\nIN CAY THEO LNR: ";
	LNR(root);

	cout << endl;

	cout << "\nIN CAY THEO TANG " << endl;
	LevelOrder(root);

	int val = 12;
	NODE* t = Search(root, val);
	cout << "\nTIM NODE CO GIA TRI: " << t->key << endl;
	
	int value = 14;
	Insert(root, value);
	cout << "\nCAY SAU KHI THEM GIA TRI: " << value << endl;
	LevelOrder(root);

	value = 16;
	Remove(root, value);
	cout << "\nCAY SAU KHI XOA GIA TRI: " << value << endl;
	LevelOrder(root);

	cout << "\nCHIEU CAO CUA CAY: " << Height(root) << endl;

	cout << "\nTONG SO NODE CUA CAY: " << countNode(root) << endl;

	cout << "\nTONG CUA CAC NODE TRONG CAY: " << sumNode(root) << endl;

	cout << "\nSO LA CUA CAY: " <<countLeaf(root) << endl;

	value = 14;
	cout << "\nSO NODE NHO HON GIA TRI " << value<<": " << countLess(root, value);

	value = 14;
	cout << "\nSO NODE LON HON GIA TRI " << value << ": " << countGreater(root, value);

	if (isBST(root)) {

		cout << "\nLA CAY NHI PHAN TIM KIEM " << endl;
	}
	else cout << "\nKHONG PHAI CAY NHI PHAN TIM KIEM" << endl;

	if (isFullBST (root)) {

		cout << "\nLA CAY NHI PHAN TIM KIEM DAY DU " << endl;
	}
	else cout << "\nKHONG PHAI CAY NHI PHAN TIM KIEM DAY DU" << endl;

	

	//XOA CAY

	removeTree(root);
	return 0;
}