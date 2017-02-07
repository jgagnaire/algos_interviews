class BST
{
public:
        struct tree
        {
	  int data;
	  tree *left;
	  tree *right;
	};

  BST()
    : root(0)
  {
  }

  ~BST()
  {
    delete_tree(this->root);
  }

  void    insert(tree **root, int start, int end)
  {
    if (start == end)
      {
	tree *n = new tree;
	n->left = nullptr;
	n->right = nullptr;
	n->data = start;
	*root = n;
      }
    else if (start < end)
      {
	int middle = start + (end - start) / 2;

	tree *n = new tree;
	n->left = nullptr;
	n->right = nullptr;
	n->data = middle;
	*root = n;

	insert(&(*root)->left, start, middle - 1);
	insert(&(*root)->right, middle + 1, end);
      }
  }

  void    build(int start, int end)
  {
    insert(&this->root, start, end);
  }

private:
  void	delete_tree(tree *root)
  {
    if (root == nullptr)
      return ;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
  }

  tree *root;
};

int    main()
{
  BST tree;

  tree.build(1, 10);
}
