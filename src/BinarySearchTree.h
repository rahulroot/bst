#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>	
  
template < class T >
class BinarySearchTree;

template < class T > 
class BinaryNode 
{
  T element;
  BinaryNode * left;
  BinaryNode * right;

	/* constructor initialization list having same order in argument list as mentioned in class definition */
  BinaryNode (const T &theElement, BinaryNode *lt, BinaryNode *rt) 
	:element(theElement), left(lt), right(rt)
  {
  } 
	friend class BinarySearchTree<T>;
};

template < class T > 
class BinarySearchTree 
{
	public:
		explicit BinarySearchTree (const T &notFound);
  	BinarySearchTree (const BinarySearchTree &rhs);
  	~BinarySearchTree ();
  	const T &findMin () const;
  	const T &findMax () const;
  	const T &find (const T & x) const;
  	bool isEmpty ()const;
  	void printTree () const;
		void inorder() const;
		void preorder() const;
		void postorder() const;
  	void makeEmpty ();
  	void insert (const T &x);
  	void remove (const T &x);
  	const BinarySearchTree& operator=(const BinarySearchTree &rhs);
	private:
		BinaryNode <T> *root;
  	const T ITEM_NOT_FOUND;
  	const T& elementAt (BinaryNode <T> *t) const;
  	void insert (const T &x, BinaryNode <T> *&t) const;
  	void remove (const T &x, BinaryNode <T> *&t);
  	BinaryNode <T> *findMin (BinaryNode <T> *t);
  	BinaryNode <T> *findMax (BinaryNode <T> *t) const;
  	BinaryNode <T> *find (const T &x, BinaryNode <T> *t) const;
  	void makeEmpty (BinaryNode <T> *&t) const;
  	void printTree (BinaryNode <T> *t) const;
  	void inorder (BinaryNode <T> *t) const;
  	BinaryNode <T> *clone (BinaryNode <T> *t) const;
};

#include "BinarySearchTree.cpp"
#endif
