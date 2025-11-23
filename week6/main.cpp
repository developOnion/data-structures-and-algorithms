#include <vector>

#include "../src/BinarySearchTree.hpp"

typedef BinarySearchTree<int> IntBST;

int main(void)
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    IntBST bst;
    bst.root = bst.insert(bst.root, v[0]);

    for (int i = 1; i < v.size(); ++i)
    {
        bst.insert(bst.root, v[i]);
    }

    bst.inorder();

    return 0;
}