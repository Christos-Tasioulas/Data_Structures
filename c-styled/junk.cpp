// // Inserting a value at the last place to preserve the tree's completeness
// void CompleteBinaryTree::Insert(void* value)
// {
//     // taking the case if this is the only value
//     if(this->get_size() == 0)
//     {
//         // inserting the root
//         this->InsertRoot(value);
//         BinaryTreeNode* node = this->get_root();
//         this->Last = node;
//     }
//     else
//     {
//         BinaryTreeNode* last = this->Last;
//         // case if this the second node we add
//         BinaryTreeNode* root = this->get_root();
//         if(last == root)
//         {
//             // inserting the second node as the root's left child 
//             this->InsertLeft(value, root);
//             BinaryTreeNode* node = root->get_left_child();
//             this->Last = node;
//         }
//         else
//         {
//             BinaryTreeNode* parent = last->get_parent();
//             // case if the last node is a left child of the node
//             if(parent->get_left_child() == last)
//             {
//                 // inserting the new node as a right sibling for the current last one
//                 this->InsertRight(value, parent);
//                 BinaryTreeNode* node = parent->get_right_child();
//                 this->Last = node;
//             }
//             else
//             {
//                 // traversing the tree until we find the correct place to insert the new node
//                 BinaryTreeNode* temp = last;
//                 // flag that allows the continuous left movement of our pointer
//                 int flag = 0;
//                 // we don't want the node we will reach to have a left child
//                 while(temp->get_left_child() != NULL)
//                 {
//                     BinaryTreeNode* parent_temp = temp->get_parent();
//                     if(flag == 1)
//                     {
//                         //moving the pointer lefter and lefter to add a new level
//                         temp = temp->get_left_child();
//                     }
//                     else if(parent_temp->get_left_child() == temp)
//                     {
//                         // moving onto the node's sibling
//                         temp = parent_temp->get_right_child();
//                         // indicating that we have passed through the tree's root
//                         if(parent_temp == root) flag = 2;
//                     }
//                     else if(parent_temp->get_right_child() == temp)
//                     {
//                         // we have reached the tree's root
//                         if(parent_temp == root)
//                         {
//                             // we have passed it before so we move to the left child
//                             if(flag == 2)
//                             {
//                                 temp = temp->get_left_child();
//                             }
//                             else
//                             {
//                                 // this is the first time we pass from the root so the only way is left
//                                 temp = parent_temp->get_left_child();
//                                 flag = 1;
//                             }
                            
//                         }
//                         // moving up to the parent
//                         else temp = parent_temp;
//                     }
//                 }
//                 // giving children to a leaf
//                 this->InsertLeft(value, temp);
//                 BinaryTreeNode* node = temp->get_left_child();
//                 this->Last = node;
//             }
//         }
//     }
// }

// void clear_list(List* l)
// {
//     ListNode* node = l->get_first();
//     while(node != NULL)
//     {
//         int* i = (int*) node->get_value();
//         delete i;
//         node = node->get_next();
//     }

//     delete l;
// }

// case if the node has both children
// if(node->get_left_child() && node->get_right_child())
// {
//     // the new value of the node will be near the bottom of the tree
//     BinaryTreeNode* Successor = this->find_successor(node);

//     // swapping the values of the successor node and the current one
//     this->swap_values(node, Successor);

//     // no need to keep the successor node now that the values have been swapped
//     this->RemoveLeaf(Successor);
// }
// // case that the node only has a left child
// else if(node->get_left_child())
// {
//     BinaryTreeNode* Child = node->get_left_child();
//     // case the node is the root
//     if(node == this->get_root())
//     {
//         // we have a new root
//         this->set_root(Child);
//         Child->set_parent(NULL);
//     }
//     else
//     {
//         // connecting the parent and child node accordingly
//         BinaryTreeNode* Parent = node->get_parent();
//         // finding out what child of its parent is the current node
//         if(compare(Parent->get_value(), Child->get_value()) > 0) Parent->set_left_child(Child);
//         else Parent->set_right_child(Child);
//         Child->set_parent(Parent);
//     }

//     delete node;
//     // this->size--
//     this->decrease();
// }
// // case the node only has a right child
// else if(node->get_right_child())
// {
//     BinaryTreeNode* Child = node->get_right_child();
//     // case the node is the root
//     if(node == this->get_root())
//     {
//         // we have a new root
//         this->set_root(Child);
//         Child->set_parent(NULL);
//     }
//     else
//     {
//         // connecting the parent and child node accordingly
//         BinaryTreeNode* Parent = node->get_parent();
//         // finding out what child of its parent is the current node
//         if(compare(Parent->get_value(), Child->get_value()) > 0) Parent->set_left_child(Child);
//         else Parent->set_right_child(Child);
//         Child->set_parent(Parent);
//     }

//     delete node;
//     // this->size--
//     this->decrease();
// }
// // case the node is a leaf
// else this->RemoveLeaf(node);