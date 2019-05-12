/**
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int weighttree(struct TreeNode* root);
int max(int a, int b);

bool isBalanced(struct TreeNode* root){
    if(!root)return true;
    if(abs(weighttree(root->left) - weighttree(root->right)) >1) return false;
    return isBalanced(root->left) && isBalanced(root->right);

}

int weighttree(struct TreeNode* root){
    if(!root)return 0;
    return 1+ max(weighttree(root->left),weighttree(root->right));
}

int max(int a, int b){
    if(a>=b)return a;
    else return b;
}
