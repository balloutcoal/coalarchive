# Binary tree
* Basically a linked list but each node is two pointers and they branch down
	* These nodes cannot branch into eachother
	* Endings of the tree are just nullptrs
## Terminology
* Successor of nodes is a parent
* Predecessor of nodes is a child
* The first node is called a root (no parent)
* The last node is called a leaf (no child)
* Depth is the number of nodes gone through to get to a specific node
## Binary Search Tree
* Binary Search Tree Property
	* The value stored at a node is greater than the value stored at its left child and less than the value store at its right child
### How to search a BST
1. Start at the root
2. Compare the value of the item you're searching with the value at the root
3. If the values are equal then the item is found unless you're at a leaf node
4. If the value you want to find is less than the value at the root, then search the left subtree, if more then search the right tree
5. Repeat steps 2-5 for the root of the subtree chosen in step 4
### Tree Node Structure
```
template<class ItemType>
	struct TreeNode<ItemType>{
		ItemType info;
		TreeNode<ItemType>* left;
		TreeNode<ItemType>* right;
	};
```
### Insertion in BST
* Use the Binary Search Tree property to insert the new item at the correct place