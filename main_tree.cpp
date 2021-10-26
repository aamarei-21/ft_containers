#include "proby/BST.hpp"

int main(){
	BST<int> tree;
	tree.add_node(782);
	tree.add_node(858);
	tree.add_node(397);
	tree.add_node(506);
	tree.add_node(443);
	tree.add_node(756);
	tree.add_node(84);
	tree.add_node(785);
	tree.add_node(981);
	tree.add_node(855);
	tree.add_node(889);
	tree.add_node(47);
	tree.add_node(927);
	tree.add_node(486);
	tree.add_node(764);
	tree.add_node(901);
	tree.add_node(875);
	tree.add_node(985);

	tree.add_node(736);
	tree.add_node(204);
	tree.add_node(701);
	tree.add_node(789);
	tree.add_node(120);
	tree.add_node(681);
	tree.add_node(686);
	tree.add_node(189);
	tree.add_node(399);
	tree.add_node(123);
	tree.add_node(517);
	tree.add_node(740);
	tree.add_node(359);
	tree.add_node(938);
	tree.add_node(285);
	tree.add_node(667);
	tree.add_node(537);
	tree.add_node(202);

	tree.add_node(737);
	tree.add_node(775);
	tree.add_node(834);
	tree.add_node(554);
	tree.add_node(575);
	tree.add_node(217);
	tree.add_node(613);
	tree.add_node(263);



	tree.print_tree();
	std::cout << std::endl;
	tree.erase(92);
	tree.print_tree();
	std::cout << std::endl;
	


//	delete tree;
}
