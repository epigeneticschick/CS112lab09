/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Lorrayya Williams
 * Date: November 20, 2018
 */
 
#include "BST.h"


BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::BST(){
	myRoot = NULL;
	myNumItems = 0;

}
BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

//processes the binary search tree before going through either side
void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
		cout << ' ' << myItem;
}

//Processes Binary Search tree after going through both the left and right side.
void BST::traversePostorder(){
	if(!isEmpty()){
		myRoot->traversePostorder();
	}

}

void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

//Processes the Binary Search Tree after going through the left side
void BST::traverseInorder(){
	if(!isEmpty()){
		myRoot->traverseInorder();
	}
}
void BST::Node::traverseInorder(){
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

//Adds item to the Binary Search Tree
void BST::insert(const Item& it){
	if (isEmpty()){
		myRoot = new Node(it);
	}
	else{
		try {
			myRoot->insert(it);
		}
		catch (const Exception& e){
			throw Exception("Node::insert(it)", "Insertion Failed!");
		}
	}
	myNumItems++;
}


void BST::Node::insert(const Item& it){
	if( it < myItem){
		if(myLeft == NULL){
			myLeft = new Node(it);
		}
		else{
			myLeft->insert(it);
		}
	}
	else if(it > myItem){
		if(myRight == NULL){
			myRight = new Node(it);
		}
		else{
			myRight->insert(it);
		}
	}
	else{
		throw Exception("Node::insert(it)", "The item is already in the list!");
	}
}

//Checks if search tree has an item
bool BST::contains(const Item& item) const{
	if(isEmpty()){
		return false;
	}
	else{
		myRoot->contains(item);
	}

}

bool BST::Node::contains(const Item& item) const{
	if(item < myItem){
		if(myLeft == NULL){
			return false;
		}
		else{
			myLeft->contains(item);
		}
	}
	else if(item > myItem){
		if(myRight == NULL){
			return false;
		}
		else{
			myRight->contains(item);
		}
	}
	else{
		return true;
	}

}
