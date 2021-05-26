/**
 * BinaryTree Assignment
 * C++ Course @Ariel_University
 * Part A
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

/*** 
 *  In a previous course you learned about binary trees, and the three ways to tour them: preorder, inorder, postorder.
 *  In this task the goal is to implement a binary tree with iterators that can go through it in all three arrangements.
***/

/** ******************** Details ********************
 * 
 * The tree is not necessarily arranged in ascending order, nor is it balanced.
 * The order of the data in the tree is according to the way they are inserted. See Demo.
 * 
 * ---------------------------------------------------------------------------------
 * 
 * if the first input does not exist in the tree - an exception must be thrown.
 * If it exists twice or more - choose one of the two options and add there
 * (in the automatic tests do not enter such situations, so that the result will be unambiguous)
 * 
 * ---------------------------------------------------------------------------------
 * 
 * For part A of the assignment: The following commands should work without error:
 * 
 * make demo && ./demo
 * make test && ./test
 * 
 * ---------------------------------------------------------------------------------
 * 
**/
#pragma once

#include <iostream>


using namespace std;
namespace ariel
{

    enum{
        INORDER,PREORDER,POSTORDER
    };

    template <typename T>
    class BinaryTree{

    private:
        struct Node{

            Node *left;
            Node *right;
            
            //Value of type T
            T val;
        
            
            //  Constructor as Initialization List
            Node(const T &v) : left(nullptr), right(nullptr), val(v) {}

            //  Deconstructor
            ~Node(){
                delete right;
                delete left;
            }
        };

        Node *root;

    public:

        //  Constructor as Initialization List
        BinaryTree() : root(nullptr) {}

        //  Deconstructor
        ~BinaryTree(){  delete root;  }    


/************************************PREORDER*****************************************/        
        class Preorder{
        private:
            Node *node_;

        public:

            //  Constructor as Initialization List
            Preorder() : node_(nullptr){};

            // Operators Overloaded
            Preorder &operator++(){return *this;}
            const Preorder operator++(int){return *this;}
            bool operator==(const Preorder &other) const {return false;}
            bool operator!=(const Preorder &other) const{return false;}
            T &operator*() const{return node_->val;}
            T *operator->() const{return &(node_->val);}            
        };
          

/************************************INORDER*****************************************/  
        class Inorder
        {
         private:
            Node *node_;

        public:

            //  Constructor as Initialization List
            Inorder() : node_(nullptr){};

            // Operators Overloaded
            Inorder &operator++(){return *this;}
            const Inorder operator++(int){return *this;}
            bool operator==(const Inorder &other) const {return false;}
            bool operator!=(const Inorder &other) const{return false;}
            T &operator*() const{return node_->val;}
            T *operator->() const{return &(node_->val);}            
        };

/************************************POSTORDER*****************************************/  
        
        class Postorder
        {
         private:
            Node *node_;

        public:

            //  Constructor as Initialization List
            Postorder () : node_(nullptr){};

            // Operators Overloaded
            Postorder &operator++(){return *this;}
            const Postorder operator++(int){return *this;}
            bool operator==(const Postorder &other) const {return false;}
            bool operator!=(const Postorder &other) const{return false;}
            T &operator*() const{return node_->val;}
            T *operator->() const{return &(node_->val);}
        };
          

   /************************************ITERATORS*****************************************/ 

        //  Inorder Iterators (left - parent - right).
        Inorder begin_inorder(){return Inorder{};}
        Inorder end_inorder(){return Inorder{};}

        //  Preorder Iterators (parent - left - right).
        Preorder begin_preorder(){return Preorder{};}
        Preorder end_preorder(){return Preorder{};}

        //  Postorder iterators (left - right - parent)
        Postorder begin_postorder(){return Postorder{};}
        Postorder end_postorder(){return Postorder{};}        

        //  Iterators are in inorder by default
        Inorder begin(){return begin_inorder();};
        Inorder end(){return end_inorder();};        

   /************************************TO STRING*****************************************/  

    //recursive preorder print for tests
     void preorderPrint( BinaryTree *root ) {
        if ( root != NULL ) {
           cout << root->item << " ";
           preorderPrint( root->left );
           preorderPrint( root->right );
        }
     }

    //recursive inorder print for tests
     void inorderPrint( BinaryTree *root ) {
        if ( root != NULL ) {
           inorderPrint( root->left );
            cout << root->item << " ";
           inorderPrint( root->right );
        }
     }  

    //recursive postorder print for tests
     void postorderPrint( BinaryTree *root ) {
        if ( root != NULL ) {
           postorderPrint( root->left );
           postorderPrint( root->right );
            cout << root->item << " ";
           
        }
     }         

        //  Prints the tree
        friend ostream &operator<<(ostream &out, const BinaryTree<T> &b)
        {
            //TO DO
            return out;
        }

        //  Receives one input and places it at the root of the tree. If there is already something in the root, it is replaced
        BinaryTree &add_root(T r)
        {
            //TO DO
            return *this;
        }

        //  Receives two inputs: The first input indicates something that already exists in the tree.
        //  The second input indicates something new to be added as his left child 
        //  (if he already has a left child - his content should be replaced)
        BinaryTree &add_left(T n1, T n2)
        {
            //TO DO
            return *this;
        }

        //  Receives two inputs: The first input indicates something that already exists in the tree.
        //  The second input indicates something new to be added as his right child 
        //  (if he already has a right child - his content should be replaced)
        BinaryTree &add_right(T n1, T n2)
        {
            //TO DO
            return *this;
        }

    };

}