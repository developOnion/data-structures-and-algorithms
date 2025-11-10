#include "../src/BinaryTree.hpp"

int main(void)
{
    char numbers[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    BinaryTree<char> bt;
    bt.createTreeFromArr(numbers, sizeof(numbers) / sizeof(numbers[0]));
    std::cout << "preOrder: ";
    bt.preOrder();

    std::cout << "inOrder: ";
    bt.inOrder();

    std::cout << "postOrder: ";
    bt.postOrder();

    return 0;
}