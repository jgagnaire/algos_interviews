
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "structs_list_tree.h"

void add_to_stack(stack **s, int a)
{
  stack *n = new stack;

  n->data = a;
  n->next = *s;
  *s = n;
}

void free_list(list *x)
{
  if (x == nullptr)
    return ;

  list *tmp = x->next;

  while (tmp)
    {
      delete (x);
      x = tmp;
      tmp = tmp->next;
    }
  delete (x);
}

void add_to_queue(queue **q, int a)
{
  queue *n = new queue;
  queue *tmp;

  n->data = a;
  n->next = nullptr;

  if (*q == nullptr)
    {
      *q = n;
      return ;
    }

  tmp = *q;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = n;
}

void print_list(list *list)
{
  while (list)
    {
      std::cout << list->data << " ";
      list = list->next;
    }
  std::cout << std::endl;
}

void bst_insert(tree **root, int data)
{
  if (*root == nullptr)
    {
      tree *n = new tree;

      n->data = data;
      n->already_visited = false;
      n->left = nullptr;
      n->right = nullptr;
      *root = n;
      return ;
    }
  if ((*root)->data <= data)
    return bst_insert(&(*root)->right, data);
  return bst_insert(&(*root)->left, data);
}

void free_tree(tree *root)
{
  if (root == nullptr)
    return ;
  ::free_tree(root->left);
  ::free_tree(root->right);
  delete root;
}

void inorder_rec_dfs(tree *root)
{
  if (root == nullptr)
    return ;
  inorder_rec_dfs(root->left);
  std::cout << root->data << " ";
  inorder_rec_dfs(root->right);
}

void preorder_rec_dfs(tree *root)
{
  if (root == nullptr)
    return ;
  std::cout << root->data << " ";
  ::preorder_rec_dfs(root->left);
  ::preorder_rec_dfs(root->right);
}

void postorder_rec_dfs(tree *root)
{
  if (root == nullptr)
    return ;
  ::postorder_rec_dfs(root->left);
  ::postorder_rec_dfs(root->right);
  std::cout << root->data << " ";
}

void inorder_it_dfs(tree *root)
{
  std::stack<tree *> s;

  while (root || s.size() > 0)
    {
      if (root)
	{
	  s.push(root);
	  root = root->left;
	}
      else
	{
	  root = s.top();
	  s.pop();
	  std::cout << root->data << " ";
	  root = root->right;
	}
    }
}

void preorder_it_dfs(tree *root)
{
  std::stack<tree *> s;

  while (root || s.size() > 0)
    {
      if (root)
	{
	  std::cout << root->data << " ";
	  if (root->right)
	    s.push(root->right);
	  root = root->left;
	}
      else
	{
	  root = s.top();
	  s.pop();
	}
    }
}

void postorder_it_dfs(tree *root)
{
  std::stack<tree *> s;
  tree *already_visited_node = nullptr;

  while (root || s.size() > 0)
    {
      if (root)
	{
	  s.push(root);
	  root = root->left;
	}
      else
	{
	  if (s.top()->right && already_visited_node != s.top()->right)
	    root = s.top()->right;
	  else
	    {
	      std::cout << s.top()->data << " ";
	      already_visited_node = s.top();
	      s.pop();
	    }
	}
    }
}

void bfs(tree *root)
{
  std::queue<tree *> q;

  q.push(root);
  while (q.size() > 0)
    {
      root = q.front();
      q.pop();
      std::cout << root->data << " ";
      if (root->left && !root->left->already_visited)
	{
	  root->left->already_visited = true;
	  q.push(root->left);
	}
      if (root->right && !root->right->already_visited)
	{
	  root->right->already_visited = true;
	  q.push(root->right);
	}
    }
}

bool is_bst(tree *root)
{
  if (!root)
    return true;

  if ((root->left && root->data < root->left->data)
      || (root->right && root->data > root->right->data))
    return false;

  return is_bst(root->left) && is_bst(root->right);
}

int level_count(tree *root)
{
  if (!root)
    return 0;

  return std::max(level_count(root->left), level_count(root->right)) + 1;
}

#define ABS(x) ((x) < 0 ? -(x) : (x))

bool is_height_balanced(tree *root)
{
  if (!root)
    return true;

  int count_left = level_count(root->left);
  int count_right = level_count(root->right);

  return ABS(count_left - count_right) <= 1
    && is_height_balanced(root->left)
    && is_height_balanced(root->right);
}

int	main(void)
{
  tree *root = nullptr;

  std::vector<int> tab({5, 3, 4, 2, 7, 6, 8});

  for (int a = 0; a < tab.size(); ++a)
    ::bst_insert(&root, tab[a]);

  /*
  ::preorder_rec_dfs(root);
  std::cout << std::endl;
  ::preorder_it_dfs(root);
  std::cout << std::endl << std::endl;

  ::inorder_rec_dfs(root);
  std::cout << std::endl;
  ::inorder_it_dfs(root);
  std::cout << std::endl << std::endl;

  ::postorder_rec_dfs(root);
  std::cout << std::endl;
  ::postorder_it_dfs(root);
  std::cout << std::endl;
  */


  ::bfs(root);
  std::cout << std::endl;

  // std::cout << is_bst(root) << std::endl;
  
  std::cout << is_height_balanced(root) << std::endl;

  ::free_tree(root);
  return 0;
}
