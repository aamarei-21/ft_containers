#include "proby/BST.hpp"

int main(){
	BST<int> tree;
	tree.add_node(67);
	tree.add_node(47);
	tree.add_node(87);
	tree.add_node(32);
	tree.add_node(90);
	tree.add_node(40);
	tree.add_node(68);
	tree.add_node(81);
	tree.add_node(75);
	tree.add_node(92);
	tree.add_node(40);
	tree.add_node(11);
	tree.add_node(17);
	tree.add_node(56);
	tree.add_node(84);
	tree.add_node(84);
	tree.add_node(84);
	tree.add_node(84);


	tree.print_tree();
	std::cout << std::endl;
	tree.erase(67);
	tree.print_tree();
	std::cout << std::endl;
	


	//delete tree;
}
