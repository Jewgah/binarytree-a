/**
 * BinaryTree Assignment
 * C++ Course @Ariel_University
 * Part A
 * Author: Jordan Perez
 * https://www.github.com/jewgah
 * 
 * */

#include <iostream>
#include <string>

#include "doctest.h"
#include "BinaryTree.hpp"

using namespace std;
using namespace ariel;

//Binary Trees of ints test
TEST_CASE("add left/right without root")
{
    BinaryTree<int> tree;
        
    //exception is thrown if we add a child when there's no root
    CHECK_THROWS(tree.add_left(0, 1));
    CHECK_THROWS(tree.add_right(0, 1));

}

TEST_CASE("add left/right tests"){

    BinaryTree<int> tree;

    CHECK_NOTHROW(tree.add_root(0)); //add root

    CHECK_NOTHROW(tree.add_left(0,1));
    CHECK_NOTHROW(tree.add_right(0,2));

    CHECK_NOTHROW(tree.add_left(1,4));
    CHECK_NOTHROW(tree.add_right(1,3));
    
    CHECK_NOTHROW(tree.add_left(2,6));
    CHECK_NOTHROW(tree.add_right(2,5));

}

TEST_CASE("int tree check"){

    BinaryTree<int> tree;

    tree.add_root(0);
    tree.add_left(0,1);
    tree.add_right(0,2);
    tree.add_left(1,3);
    tree.add_right(1,4);
    tree.add_left(2,5);
    tree.add_right(2,6);

    /*   tree:

           0
         /   \
        /     \
       1       2
      / \     / \
     /   \   /   \
    3     4 5     6

    */    
    
    //  (left - parent - right)
    SUBCASE("inorder"){

        string inorder_tree;
        for (auto iterator =tree.begin_inorder(); iterator!=tree.end_inorder(); iterator++) {

            inorder_tree+= *iterator +' ';

        }

        CHECK(inorder_tree=="0 1 2 3 4 5 6 ");
    }

    //  (parent - left - right)
    SUBCASE("preorder"){

        string preorder_tree;
        for (auto iterator =tree.begin_preorder(); iterator!=tree.end_preorder(); iterator++) {

            preorder_tree+= *iterator +' ';

        }

        CHECK(preorder_tree=="3 1 4 0 5 2 6 ");
    }    

    //  (left - right - parent)
    SUBCASE("postorder"){

        string postorder_tree;
        for (auto iterator =tree.begin_postorder(); iterator!=tree.end_postorder(); iterator++) {

            postorder_tree+= *iterator +' ';

        }

        CHECK(postorder_tree=="4 3 1 6 5 2 0 ");
    }
}


TEST_CASE("double tree check"){

    BinaryTree<double> tree;

    tree.add_root(0.0);
    tree.add_left(0.0,0.1);
    tree.add_right(0.0,0.2);
    tree.add_left(0.1,0.3);
    tree.add_right(0.1,0.4);
    tree.add_left(0.2,0.5);
    tree.add_right(0.2,0.6);

    /*     tree:

            0.0
          /     \
         /       \
        /         \
       0.1        0.2
      /   \      /   \
     /     \    /     \
    0.3   0.4  0.5    0.6

    */    
    
    //  (left - parent - right)
    SUBCASE("inorder"){

        string inorder_tree;
        for (auto iterator =tree.begin_inorder(); iterator!=tree.end_inorder(); iterator++) {

            inorder_tree+= *iterator +' ';

        }

        CHECK(inorder_tree=="0.0 0.1 0.2 0.3 0.4 0.5 0.6 ");
    }

    //  (parent - left - right)
    SUBCASE("preorder"){

        string preorder_tree;
        for (auto iterator =tree.begin_preorder(); iterator!=tree.end_preorder(); iterator++) {

            preorder_tree+= *iterator +' ';

        }

        CHECK(preorder_tree=="0.3 0.1 0.4 0.0 0.5 0.2 0.6 ");
    }    

    //  (left - right - parent)
    SUBCASE("postorder"){

        string postorder_tree;
        for (auto iterator =tree.begin_postorder(); iterator!=tree.end_postorder(); iterator++) {

            postorder_tree+= *iterator +' ';

        }

        CHECK(postorder_tree=="0.4 0.3 0.1 0.6 0.5 0.2 0.0 ");
    }
}

TEST_CASE("char tree check"){

    BinaryTree<char> tree;

    tree.add_root('a');
    tree.add_left('a','b');
    tree.add_right('a','c');
    tree.add_left('b','d');
    tree.add_right('b','e');
    tree.add_left('c','f');
    tree.add_right('c','g');

    /*   tree:

             a
          /     \
         /       \
        /         \
       b           c
      /   \      /   \
     /     \    /     \
    d       e  f       g

    */    
    
    //  (left - parent - right)
    SUBCASE("inorder"){

        string inorder_tree;
        for (auto iterator =tree.begin_inorder(); iterator!=tree.end_inorder(); iterator++) {

            inorder_tree+= *iterator +' ';

        }

        CHECK(inorder_tree=="a b c d e f g ");
    }

    //  (parent - left - right)
    SUBCASE("preorder"){

        string preorder_tree;
        for (auto iterator =tree.begin_preorder(); iterator!=tree.end_preorder(); iterator++) {

            preorder_tree+= *iterator +' ';

        }

        CHECK(preorder_tree=="d b e a f c g ");
    }    

    //  (left - right - parent)
    SUBCASE("postorder"){

        string postorder_tree;
        for (auto iterator =tree.begin_postorder(); iterator!=tree.end_postorder(); iterator++) {

            postorder_tree+= *iterator +' ';

        }

        CHECK(postorder_tree=="e d b g f c a ");
    }
}

TEST_CASE("string tree check"){

    BinaryTree<string> tree;

    tree.add_root("first");
    tree.add_left("first","second");
    tree.add_right("first","third");
    tree.add_left("second","fourth");
    tree.add_right("second","fifth");
    tree.add_left("third","sixth");
    tree.add_right("third","seventh");

    /*   tree:

             first
           /       \
          /         \
         /           \
     second         third
      /    \        /    \
     /      \      /      \
  fourth  fifth  sixth  seventh

    */    
    
    //  (left - parent - right)
    SUBCASE("inorder"){

        string inorder_tree;
        for (auto iterator =tree.begin_inorder(); iterator!=tree.end_inorder(); iterator++) {

            inorder_tree+= *iterator +' ';

        }

        CHECK(inorder_tree=="first second third fourth fifth sixth seventh ");
    }

    //  (parent - left - right)
    SUBCASE("preorder"){

        string preorder_tree;
        for (auto iterator =tree.begin_preorder(); iterator!=tree.end_preorder(); iterator++) {

            preorder_tree+= *iterator +' ';

        }

        CHECK(preorder_tree=="fourth second fifth first sixth third seventh ");
    }    

    //  (left - right - parent)
    SUBCASE("postorder"){

        string postorder_tree;
        for (auto iterator =tree.begin_postorder(); iterator!=tree.end_postorder(); iterator++) {

            postorder_tree+= *iterator +' ';

        }

        CHECK(postorder_tree=="fifth fourth second seventh sixth third first ");
    } 
}    