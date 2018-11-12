#include<stdio.h>
#include<stdint.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* treeBuild(int val);
struct Stack
{
    struct TreeNode *tree_p;
    struct Stack *next;
};
struct Stack* stackBuild();
struct TreeNode* stackPop(struct Stack* s);
struct TreeNode* StackTop(struct Stack* s);
struct Stack*  stackPush(struct Stack* s, struct TreeNode* tree_p);
int stackIsEmpty(struct Stack* s);
int num(struct Stack* s);
int findTilt(struct TreeNode* root);

int main()
{
    struct TreeNode* root = treeBuild(1);
    struct TreeNode* Left = treeBuild(2);
    struct TreeNode* Right =treeBuild(3);

    root->left = Left;
    root->right = Right;

    int findTilt(root);
}
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* treeBuild(int val)
{
    struct TreeNode* newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = val;

    return newnode;

}
struct Stack* stackBuild()
{
    return NULL;
}

struct TreeNode* stackPop(struct Stack* s)
{
    struct Stack* temp = NULL;
    temp = s;
    s=s->next;
    free(temp);
    return s;
}

struct TreeNode* StackTop(struct Stack* s)
{
    return s->tree_p;
}
struct Stack*  stackPush(struct Stack* s, struct TreeNode* tree_p)
{
    struct Stack* newnode=(struct Stack*)malloc(sizeof(struct Stack));
    newnode->next = s;
    newnode->tree_p = tree_p;

    s=newnode;

    return s;
}
int stackIsEmpty(struct Stack* s)
{
    return s==NULL;//if is empty,return 1,else return 0;
}
int num(struct Stack* s)
{
    struct Stack* temp = s;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int findTilt(struct TreeNode* root)
{
    struct TreeNode* temp = root;
    struct Stack* ins = stackBuild();
    while(num(ins) != 1)
    {

    }

}

