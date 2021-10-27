#include "AVL.hpp"
#include <vector>

int main(){
	AVL<int> tree;
//	tree.add_node(20);
//	tree.print_tree();
//	tree.add_node(10);
//	tree.print_tree();
//	tree.add_node(40);
//	tree.print_tree();
//	tree.add_node(5);
//	tree.print_tree();
//	tree.add_node(15);
//	tree.print_tree();
//	tree.add_node(30);
//	tree.print_tree();
//	tree.add_node(60);
//	tree.print_tree();
//	tree.add_node(3);
//	tree.print_tree();
//	tree.add_node(18);
//	tree.print_tree();
//	tree.add_node(25);
//	tree.print_tree();
//	tree.add_node(70);
//	tree.print_tree();
//	tree.add_node(27);


//	tree.erase(15);
//	tree.print_tree();
//	tree.erase(30);
//	tree.print_tree();
//	tree.erase(60);




	tree.add_node(782);
	tree.print_tree();
	tree.add_node(858);
	tree.print_tree();
	tree.add_node(397);
	tree.print_tree();
	tree.add_node(506);
	tree.print_tree();
	tree.add_node(443);
	tree.print_tree();
	tree.add_node(756);
	tree.print_tree();
	tree.add_node(84);
	tree.print_tree();
	tree.add_node(785);
	tree.print_tree();
	tree.add_node(981);
	tree.print_tree();
	tree.add_node(855);
	tree.print_tree();
	tree.add_node(889);
	tree.print_tree();
	tree.add_node(47);
	tree.print_tree();
	tree.add_node(927);
	tree.print_tree();
	tree.add_node(486);
	tree.print_tree();
	tree.add_node(764);
	tree.print_tree();
	tree.add_node(901);
	tree.print_tree();
	tree.add_node(875);
	tree.print_tree();
	tree.add_node(985);
	tree.print_tree();
	tree.add_node(784);
	tree.print_tree();
	tree.add_node(752);
	tree.print_tree();
	tree.add_node(760);
	tree.print_tree();
	tree.add_node(758);
	tree.print_tree();
	tree.add_node(49);
	tree.print_tree();
	tree.add_node(48);

	tree.print_tree();
	tree.erase(486);
	tree.print_tree();
	tree.erase(47);
	tree.print_tree();
	tree.erase(397);
	tree.print_tree();
	tree.erase(785);


//	tree.print_tree();
//	tree.add_node(736);
//	tree.print_tree();
//	tree.add_node(204);
//	tree.print_tree();
//	tree.add_node(701);
//	tree.print_tree();
//	tree.add_node(789);
//	tree.print_tree();
//	tree.add_node(120);
//	tree.print_tree();
//	tree.add_node(681);
//	tree.print_tree();
//	tree.add_node(686);
//	tree.print_tree();
//	tree.add_node(189);
//	tree.print_tree();
//	tree.add_node(399);
//	tree.print_tree();
//	tree.add_node(123);
//	tree.print_tree();
//	tree.add_node(517);
//	tree.print_tree();
//	tree.add_node(740);
//	tree.print_tree();
//	tree.add_node(359);
//	tree.print_tree();
//	tree.add_node(938);
//	tree.print_tree();
//	tree.add_node(285);
//
//	tree.print_tree();
//	tree.add_node(667);
//	tree.print_tree();
//	tree.add_node(537);
//	tree.print_tree();
//	tree.add_node(202);
//
//	tree.print_tree();
//	tree.add_node(737);
//	tree.print_tree();
//	tree.add_node(775);
//	tree.print_tree();
//	tree.add_node(834);
//	tree.print_tree();
//	tree.add_node(554);
//	tree.print_tree();
//	tree.add_node(575);
//	tree.print_tree();
//	tree.add_node(217);
//	tree.print_tree();
//	tree.add_node(613);
//	tree.print_tree();
//	tree.add_node(263);


	tree.print_tree();

	std::cout << "MAX = " << tree.max()->_Val << std:: endl;
	std::cout << "MIN = " << tree.min()->_Val << std:: endl;
	AVLNode<int>* node = tree.max();
	for(;node != tree.min(); node = node->decrem())
		std::cout<< node->_Val << "   ";
	std::cout << std::endl;





	tree.print_n();

//	delete tree;

};