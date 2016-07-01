#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    }

   if(pRoot == NULL){
            return ;
        }
         
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
         
        if(pRoot->left){
            Mirror(pRoot->left);
        }
         
        if(pRoot->right){
           Mirror(pRoot->right);
        }