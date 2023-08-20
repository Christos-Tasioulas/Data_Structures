// functions that test the data structures in the folder and some assisstant functions

#include "AVLTree.h"
#include "HashTable.h"
#include "Tests.h"

void visit_int(void* value)
{
    int i = *((int*) value);
    cout << "[" << i << "]";
}

int compare_ints(void* v1, void* v2)
{
    int i1 = *((int*) v1);
    int i2 = *((int*) v2);
    return i1 - i2;
}

/**********
 * Test 1 *
 **********/

void Tests::test_1()
{
    std::cout << "\n*******************************\n"
    << "*           Test 1            *\n"
    << "*******************************\n"
    << std::endl;

    int i1 = 10;
    int i2 = 5;
    int i3 = 20;
    int i4 = 120;
    int i5 = 75;

    BinaryTree *bt = new BinaryTree();
    bt->InsertRoot(&i1);

    BinaryTreeNode *root = bt->get_root();
    bt->InsertLeft(&i2, root);
    bt->InsertRight(&i3, root);

    BinaryTreeNode *leftChild = root->get_left_child();
    bt->InsertLeft(&i4, leftChild);
    bt->InsertRight(&i5, leftChild);

    std::cout << "Preorder Traversal:" << std::endl;
    bt->print_pre_order(visit_int);

    std::cout << "\nInorder Traversal:" << std::endl;
    bt->print_in_order(visit_int);

    std::cout << "\nPostorder Traversal:" << std::endl;
    bt->print_post_order(visit_int);

    std::cout << "\nLevelorder Traversal:" << std::endl;
    bt->print_level_order(visit_int);

    delete bt;
}

/**********
 * Test 2 *
 **********/

void Tests::test_2()
{
    std::cout << "\n*******************************\n"
    << "*           Test 2            *\n"
    << "*******************************\n"
    << std::endl;

    int i1 = 10;
    int i2 = 5;
    int i3 = 20;
    int i4 = 120;
    int i5 = 75;

    Heap *bh = new Heap();

    bh->HeapInsert(&i1, compare_ints);
    bh->HeapInsert(&i2, compare_ints);
    bh->HeapInsert(&i3, compare_ints);
    bh->HeapInsert(&i4, compare_ints);
    bh->HeapInsert(&i5, compare_ints);

    std::cout << "Preorder Traversal:" << std::endl;
    bh->print_pre_order(visit_int);

    std::cout << "\nInorder Traversal:" << std::endl;
    bh->print_in_order(visit_int);

    std::cout << "\nPostorder Traversal:" << std::endl;
    bh->print_post_order(visit_int);

    std::cout << "\nLevelorder Traversal:" << std::endl;
    bh->print_level_order(visit_int);

    delete bh;
}

/**********
 * Test 3 *
 **********/

void Tests::test_3()
{
//     std::cout << "\n*******************************\n"
//         << "*           Test 3            *\n"
//         << "*******************************\n"
//         << std::endl;

//     char *s1 = new char[7];
//     strcpy(s1, "Nature");
//     int i11 = 10;
//     int i12 = 5;
//     int i13 = 20;
//     int i14 = 120;
//     int i15 = 75;

//     char *s2 = new char[6];
//     strcpy(s2, "Water");
//     int i21 = 100;
//     int i22 = 50;
//     int i23 = 60;
//     int i24 = 90;
//     int i25 = 55;

//     char *s3 = new char[5];
//     strcpy(s3, "Fire");
//     int i31 = 110;
//     int i32 = 25;
//     int i33 = 35;
//     int i34 = 45;
//     int i35 = 85;

//     char *s4 = new char[7];
//     strcpy(s4, "Poison");
//     int i41 = 7;
//     int i42 = 17;
//     int i43 = 27;
//     int i44 = 37;
//     int i45 = 98;

//     char *s5 = new char[35];
//     strcpy(s5, "Supercalifragilisticexpialidocious");
//     int i51 = 8;
//     int i52 = 18;
//     int i53 = 28;
//     int i54 = 38;
//     int i55 = 88;

//     BinaryHeap *bh1 = new BinaryHeap(MINHEAP);
//     bh1->insert(&i11, &i11, compare_ints);
//     bh1->insert(&i12, &i12, compare_ints);
//     bh1->insert(&i13, &i13, compare_ints);
//     bh1->insert(&i14, &i14, compare_ints);
//     bh1->insert(&i15, &i15, compare_ints);

//     BinaryHeap *bh2 = new BinaryHeap(MINHEAP);
//     bh2->insert(&i21, &i21, compare_ints);
//     bh2->insert(&i22, &i22, compare_ints);
//     bh2->insert(&i23, &i23, compare_ints);
//     bh2->insert(&i24, &i24, compare_ints);
//     bh2->insert(&i25, &i25, compare_ints);

//     BinaryHeap *bh3 = new BinaryHeap(MINHEAP);
//     bh3->insert(&i31, &i31, compare_ints);
//     bh3->insert(&i32, &i32, compare_ints);
//     bh3->insert(&i33, &i33, compare_ints);
//     bh3->insert(&i34, &i34, compare_ints);
//     bh3->insert(&i35, &i35, compare_ints);

//     BinaryHeap *bh4 = new BinaryHeap(MINHEAP);
//     bh4->insert(&i41, &i41, compare_ints);
//     bh4->insert(&i42, &i42, compare_ints);
//     bh4->insert(&i43, &i43, compare_ints);
//     bh4->insert(&i44, &i44, compare_ints);
//     bh4->insert(&i45, &i45, compare_ints);

//     BinaryHeap *bh5 = new BinaryHeap(MINHEAP);
//     bh5->insert(&i51, &i51, compare_ints);
//     bh5->insert(&i52, &i52, compare_ints);
//     bh5->insert(&i53, &i53, compare_ints);
//     bh5->insert(&i54, &i54, compare_ints);
//     bh5->insert(&i55, &i55, compare_ints);

//     BinaryHeap *bh = new BinaryHeap(MINHEAP);
//     bh->insert(bh1, s1, compare_strings);
//     bh->insert(bh2, s2, compare_strings);
//     bh->insert(bh3, s3, compare_strings);
//     bh->insert(bh4, s4, compare_strings);
//     bh->insert(bh5, s5, compare_strings);

//     std::cout << "Preorder Traversal:" << std::endl;
//     bh->traverse(Preorder, traverseOuterTree);

//     std::cout << "\nInorder Traversal:" << std::endl;
//     bh->traverse(Inorder, traverseOuterTree);

//     std::cout << "\nPostorder Traversal:" << std::endl;
//     bh->traverse(Postorder, traverseOuterTree);

//     std::cout << "\nLevelorder Traversal:" << std::endl;
//     bh->traverse(Levelorder, traverseOuterTree);

//     /* Free all the allocated memory */

//     bh->traverse(Postorder, freeMemory);
//     delete bh; 
}

/**********
 * Test 4 *
 **********/

void Tests::test_4()
{
    
}

int* create_int(int i)
{
    int* pointer = new int(i);
    return pointer;
}

int hash_i(void* v, int capacity)
{
    int i = *((int*) v);
    return i % capacity;
}

void list_testing()
{
    List* l = new List();
    int integer[10]={1, 3, 17, 18, 5, 6, 8, 15, 9, 20};

    l->ListInsertFirst(&integer[0]);

    for(int i=1; i<5; i++)
    {
        l->ListInsertAfter(&integer[i], &integer[i-1], compare_ints);
    }

    l->print1(visit_int);
    cout << endl;

    for(int i=5; i<9; i++)
    {
        l->ListInsertBefore(&integer[i], &integer[4], compare_ints);
    }

    l->ListInsertLast(&integer[9]);

    l->print1(visit_int);

    l->Remove(&integer[4], compare_ints);

    l->RemoveFirst();

    cout << endl;
    l->print2(visit_int);

    delete l;

}

void binary_tree_testing()
{
    BinaryTree* BT = new BinaryTree();

    int integer[7]={1, 3, 17, 18, 5, 6, 8};

    BT->InsertRoot(&integer[0]);
    BinaryTreeNode* Root = BT->get_root();

    BT->InsertLeft(&integer[1], Root);
    BT->InsertRight(&integer[2], Root);
    BinaryTreeNode* Left = Root->get_left_child();
    BinaryTreeNode* Right = Root->get_right_child();

    BT->InsertLeft(&integer[3], Left);
    BT->InsertLeft(&integer[4], Right);
    BT->InsertRight(&integer[5], Left);
    BT->InsertRight(&integer[6], Right);

    cout << "pre order" << endl;
    BT->print_pre_order(visit_int);

    cout << "in order" << endl;
    BT->print_in_order(visit_int);

    cout << "post order" << endl;
    BT->print_post_order(visit_int);

    cout << "level order" << endl;
    BT->print_level_order(visit_int);

    cout << "removing some shit" << endl;
    BT->RemoveLeaf(Left->get_left_child());
    BT->RemoveLeaf(Right->get_right_child());
    
    cout << "pre order" << endl;
    BT->print_pre_order(visit_int);

    cout << "in order" << endl;
    BT->print_in_order(visit_int);

    cout << "post order" << endl;
    BT->print_post_order(visit_int);

    cout << "level order" << endl;
    BT->print_level_order(visit_int);

    delete BT;
}

void queue_testing()
{
    Queue* Q = new Queue();
    int integer[10]={1, 3, 17, 18, 5, 6, 8, 15, 9, 20};

    for(int i=0; i<10; i++)
    {
        Q->Enqueue(&integer[i]);
    }

    Q->print1(visit_int);
    cout << endl; 

    Q->Dequeue();

    Q->print1(visit_int);
    cout << endl;

    delete Q;
}

void complete_binary_tree_testing()
{
    CompleteBinaryTree* CBT = new CompleteBinaryTree();
    int integer[10]={1, 3, 17, 18, 5, 6, 8, 15, 9, 20};  

    for(int i=0; i<10; i++)
    {
        CBT->Insert(&integer[i]);   
    } 

    cout << "level order 1" << endl;
    CBT->print_level_order(visit_int);

    for(int i=0; i<5; i++)
    {
        CBT->RemoveLast();
    }

    cout << "level order 2" << endl;
    CBT->print_level_order(visit_int);

    for(int i=5; i<10; i++)
    {
        CBT->Insert(&integer[i]);   
    }

    cout << "level order 3" << endl;
    CBT->print_level_order(visit_int);

    for(int i=0; i<5; i++)
    {
        CBT->RemoveLast();
    }

    cout << "level order 4" << endl;
    CBT->print_level_order(visit_int);

    for(int i=5; i<10; i++)
    {
        CBT->Insert(&integer[i]);   
    }

    cout << "level order 5" << endl;
    CBT->print_level_order(visit_int);

    delete CBT;
}

void heap_testing()
{
    Heap* H = new Heap();
    int integer[10]={1, 3, 17, 18, 5, 6, 8, 15, 9, 20};

    for(int i=0; i<10; i++)
    {
        H->HeapInsert(&integer[i], compare_ints);   
    }

    cout << "level order 1" << endl;
    H->print_level_order(visit_int);

    H->RemoveMax(compare_ints);

    cout << "level order 2" << endl;
    H->print_level_order(visit_int);

    H->RemoveMax(compare_ints);

    cout << "level order 3" << endl;
    H->print_level_order(visit_int);

    H->RemoveMax(compare_ints);

    cout << "level order 4" << endl;
    H->print_level_order(visit_int);

    delete H;

}

void min_heap_testing()
{
    MinHeap* H = new MinHeap();
    int integer[10]={1, 3, 17, 18, 5, 6, 8, 15, 9, 20};

    for(int i=0; i<10; i++)
    {
        H->HeapInsert(&integer[i], compare_ints);   
    }

    cout << "level order 1" << endl;
    H->print_level_order(visit_int);

    H->RemoveMin(compare_ints);

    cout << "level order 2" << endl;
    H->print_level_order(visit_int);

    H->RemoveMin(compare_ints);

    cout << "level order 3" << endl;
    H->print_level_order(visit_int);

    H->RemoveMin(compare_ints);

    cout << "level order 4" << endl;
    H->print_level_order(visit_int);

    delete H;

}

void binary_search_tree_testing()
{
    BinarySearchTree* BST = new BinarySearchTree();
    int integer[10]={1, 3, 17, 18, 5, 6, 8, 15, 9, 20};
    for(int i=0; i<10; i++)
    {
        BST->Insert(&integer[i], compare_ints);   
    }

    cout << "In Order 1" << endl;
    BST->print_in_order(visit_int);
    cout << endl;

    for(int i=0; i<10; i++)
    {
        if(BST->Search(&integer[i], compare_ints)) cout << integer[i] << " found!" << endl;  
    }

    BST->Remove(&integer[4], compare_ints);

    cout << "In Order 2" << endl;
    BST->print_in_order(visit_int);
    cout << endl;

    for(int i=0; i<10; i++)
    {
        if(i == 4) continue;
        
        BST->Remove(&integer[i], compare_ints);

        cout << "In Order " << i+3 << endl;
        BST->print_in_order(visit_int);
        cout << endl;

        cout << "Level Order " << i+3 << endl;
        BST->print_level_order(visit_int);
        cout << endl;
    }

    delete BST;    
}

void avl_tree_testing()
{
    AVLTree* AVL = new AVLTree();

    int integer[10]={1, 3, 17, 18, 5, 6, 8, 15, 9, 20};
    for(int i=0; i<10; i++)
    {
        AVL->AVL_Insert(&integer[i], compare_ints);

        cout << "Pre Order " << i << endl;
        AVL->print_pre_order(visit_int);
        cout << endl;

        cout << "Level Order " << i << endl;
        AVL->print_level_order(visit_int);
        cout << endl;
    }

    for(int j=9; j>=0; j--)
    {
        AVL->AVL_Remove(&integer[j], compare_ints);

        cout << "Pre Order " << 19-j << endl;
        AVL->print_pre_order(visit_int);
        cout << endl;

        cout << "Level Order " << 19-j << endl;
        AVL->print_level_order(visit_int);
        cout << endl;
    }

    delete AVL;
}

void hash_testing()
{
    HashTable* HT = new HashTable(7, 0.75, true);

    int integer[10]={1, 3, 17, 18, 5, 6, 8, 15, 9, 20};
    for(int i=0; i<10; i++)
    {
        HT->Insert(&integer[i], hash_i);
    }

    for(int i=0; i<10; i++)
    {
        if(HT->Search_Element(&integer[i], hash_i, compare_ints)) cout << integer[i] << " Found!" << endl; 
    }

    HT->Print(visit_int);

    for(int i=0; i<10; i++)
    {
        HT->Remove(&integer[i], hash_i, compare_ints);
        if(!(HT->Search_Element(&integer[i], hash_i, compare_ints)))
        cout << integer[i] << " Removed!" << endl;
    }

    HT->Print(visit_int);   

    delete HT; 
}

int main(void)
{
    Tests::test_1();
    Tests::test_2();
    // list_testing();

    // binary_tree_testing();

    // queue_testing();

    // complete_binary_tree_testing();

    // heap_testing();

    // min_heap_testing();

    // binary_search_tree_testing();

    // avl_tree_testing();

    // hash_testing();

    return 0;
}