#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

/**
  * Construct the tree.
  */ 
template < class T > 
BinarySearchTree < T >::BinarySearchTree (const T & notFound)
:root (NULL), ITEM_NOT_FOUND (notFound) 
{
} 

/**
  * Copy constructor.
  */ 
template < class T > 
BinarySearchTree < T >::BinarySearchTree (const BinarySearchTree < T > &rhs)
: root (NULL), ITEM_NOT_FOUND (rhs.ITEM_NOT_FOUND) 
{
 *this = rhs;
}

/**
  * Destructor for the tree.
  */ 
template < class T > 
BinarySearchTree < T >::~BinarySearchTree () 
{
  makeEmpty ();
}

/**
  * Insert x into the tree; duplicates are ignored.
  */ 
template < class T > 
void BinarySearchTree <T >::insert (const T &x) 
{
  insert (x, root);
}

/**
  * Remove x from the tree. Nothing is done if x is not found.
  */ 
template < class T > 
void BinarySearchTree <T >::remove (const T &x) 
{
	remove (x, root);
}

/**
  * Find the smallest item in the tree.
  * Return smallest item or ITEM_NOT_FOUND if empty.
  */ 
template < class T > 
const T & BinarySearchTree <T >::findMin () const 
{
  return elementAt (findMin (root));
}

/**
  * Find the largest item in the tree.
  * Return the largest item of ITEM_NOT_FOUND if empty.
  */ 
template < class T > 
const T & BinarySearchTree <T >::findMax () const 
{
  return elementAt (findMax (root));
}


/**
  * Find item x in the tree.
  * Return the matching item or ITEM_NOT_FOUND if not found.
  */ 
template < class T > 
const T & BinarySearchTree <T >::find (const T &x) const 
{
  return elementAt (find (x, root));
}


/**
  * Make the tree logically empty.
  */ 
template < class T > 
void BinarySearchTree <T >::makeEmpty () 
{
  makeEmpty (root);
}

/**
  * Test if the tree is logically empty.
  * Return true if empty, false otherwise.
  */ 
template < class T > 
bool BinarySearchTree <T >::isEmpty () const 
{
  return root == NULL;
}


/**
  * Print the tree contents in sorted order.
  */ 
template < class T > 
void BinarySearchTree <T >::printTree () const 
{
  if (isEmpty ())
    cout << "Empty tree" << endl;
  else
    printTree (root);
	cout << endl;
}


template < class T > 
void BinarySearchTree <T >::inorder () const 
{
  if (isEmpty ())
    cout << "Empty tree" << endl;
  else
    inorder (root);
	cout << endl;
}

/**
  * Deep copy.
  */ 
template < class T > 
const BinarySearchTree < T >&BinarySearchTree < T >::operator= (const BinarySearchTree < T > &rhs) 
{
  if (this != &rhs)
    {
      makeEmpty ();
      root = clone (rhs.root);
    }
  return *this;
}


/**
  * Internal method to get element field in node t.
  * Return the element field or ITEM_NOT_FOUND if t is NULL.
  */ 
template < class T > 
const T & BinarySearchTree <T >::elementAt (BinaryNode < T > *t) const 
{
 	if (t == NULL)
    return ITEM_NOT_FOUND;
  
  else
    return t->element;
}


/**
  * Internal method to insert into a subtree.
  * x is the item to insert.
  * t is the node that roots the tree.
  * Set the new root.
  */ 
template < class T > 
void BinarySearchTree < T >::insert (const T & x, BinaryNode < T > *&t) const 
{
  if (t == NULL)
    t = new BinaryNode < T > (x, NULL, NULL);
  
  else if (x < t->element)
    insert (x, t->left);
  
  else if (t->element < x)
    insert (x, t->right);
  
  else
    ;				// Duplicate; do nothing
}

/**
  * Internal method to remove from a subtree.
  * x is the item to remove.
  * t is the node that roots the tree.
  * Set the new root.
  */ 
template < class T > 
void BinarySearchTree < T >::remove (const T &x, BinaryNode < T > *&t) 
{
  if (t == NULL)
    return;			// Item not found; do nothing
  if (x < t->element)
    remove (x, t->left);
  else if (t->element < x)
    remove (x, t->right);
  else if (t->left != NULL && t->right != NULL)	// Two children
  {
		 /* swap the element for better debug message */
		 BinaryNode<T> *node = findMin(t->right);
		 T tmp = node->element;
		 node->element = t->element;
		 t->element = tmp;
     remove (node->element, t->right);
  }
  else
  {
		 /* node has one child */
		 /* Code to actually deleting node */
     BinaryNode < T > *oldNode = t;
     t = (t->left != NULL) ? t->left : t->right;
		 cout <<"Removing element x : " << oldNode->element << endl;
     delete oldNode;
		 oldNode = NULL;
  }
}

/**
  * Internal method to find the smallest item in a subtree t.
  * Return node containing the smallest item.
  */ 
template < class T > 
BinaryNode < T > *BinarySearchTree < T >::findMin (BinaryNode < T > *t) 

{
  if (t == NULL)
    return NULL;
  if (t->left == NULL)
    return t;
  return findMin (t->left);
}


/**
  * Internal method to find the largest item in a subtree t.
  * Return node containing the largest item.
  */ 
template < class T > 
BinaryNode < T > *BinarySearchTree < T >::findMax (BinaryNode < T > *t) const 
{
  if (t != NULL)
    while (t->right != NULL)
      t = t->right;
  return t;
}


/**
  * Internal method to find an item in a subtree.
  * x is item to search for.
  * t is the node that roots the tree.
  * Return node containing the matched item.
  */ 
template < class T > 
BinaryNode < T > *BinarySearchTree < T >::find (const T & x, BinaryNode < T > *t) const 
{
  if (t == NULL)
    return NULL;
  
  else if (x < t->element)
    return find (x, t->left);
  
  else if (t->element < x)
    return find (x, t->right);
  
  else
    return t;			// Match
}


/**
  * Internal method to make subtree empty.
  */ 
template < class T > 
void BinarySearchTree < T >::makeEmpty (BinaryNode < T > *&t) const 
{
  if (t != NULL)
  {
      makeEmpty (t->left);
      makeEmpty (t->right);
      delete t;
  }
  t = NULL;
}


/**
  * Internal method to print a subtree rooted at t in sorted order.
  */ 
template < class T > 
void BinarySearchTree <T >::printTree (BinaryNode < T > *t) const 
{
  if (t != NULL)
  {
     printTree (t->left);
     cout << t->element << '\t';
     printTree (t->right);
  }
}

template < class T >
void BinarySearchTree < T >::inorder (BinaryNode < T > *t) const
{
	if (t != NULL)
	{
		inorder (t->left);
		cout << t->element << '\t';
		inorder (t->right);
	}
}


/**
  * Internal method to clone subtree.
  */ 
template < class T > 
BinaryNode < T > *BinarySearchTree < T >::clone (BinaryNode < T > *t) const 
{
  if (t == NULL)
   return NULL;
  
  else
    return new BinaryNode < T > (t->element, clone (t->left),
					   clone (t->right));
}
