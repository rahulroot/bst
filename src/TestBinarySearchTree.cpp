#include <iostream>
#include <stdlib.h>

#include "BinarySearchTree.h"

// Test program
int main (int argc, char *argv[]) 
{

  const int ITEM_NOT_FOUND = -9999;

	if(argc < 2 )
	{
		cout <<"Usage : ./a.out no_of_records." << endl;
		cout <<"Usage : ./a.out 2000 " << endl;
		exit(-1);
	}
	
	int maxnum = atoi(argv[1]);
	int *a = new int[maxnum];
	if(!a) {
		cout <<" Insufficient Memory. " << endl;
		exit(-1);
	}

	int lb = 0, ub = maxnum - 1;
	for(int i = lb; i <= ub; ++i)
	{
		a[i] = rand()%maxnum;
	}
	
	for(int i = 0; i < maxnum; ++i)
		cout << a[i] <<" ";
	cout << endl;


  BinarySearchTree <int> t(ITEM_NOT_FOUND);

  for (int i = 0; i < maxnum; i++)
    t.insert (a[i]);

	cout <<"Printing tree.." << endl;
	t.printTree();

  for (int i = 0; i < maxnum; i += 3)
    t.remove (a[i]);

	delete []a;

	cout <<"Printing tree again after removing some element..." << endl;
  t.printTree ();


  for (int i = 0; i < maxnum; i++)
    if (t.find (i) == ITEM_NOT_FOUND)
      cout << "Find error!, not found : " << i << endl;
		else
			cout <<"Element found :  " << i << endl;

  BinarySearchTree <int> t2(ITEM_NOT_FOUND);
  t2 = t;
	cout <<"Printing tree after deep copy.." << endl;
	t2.printTree();
  for (int i = 0; i < maxnum; i++)
    if (t2.find (i) == ITEM_NOT_FOUND)
      cout << "Find error!, not found : " << i << endl;
		else
			cout <<"Element found :  " << i << endl;

	cout <<"Inorder Traversal of tree.." << endl;
	t2.inorder();

	cout <<"Deleting tree..." << endl;
	t2.makeEmpty();
  return 0;
}
