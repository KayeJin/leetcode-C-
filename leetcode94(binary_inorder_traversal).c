#include<stdio.h>
#include<stdlib.h>

unsigned char checker =0;
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    unsigned char visited;
};
struct StackNode
{
    struct TreeNode* t_pointer;
    struct StackNode* next;
};
struct TreeNode* treeBuild(int val);
struct StackNode* stackBuild();
struct TreeNode* stackTop(struct StackNode* head);
struct StackNode* stackPop(struct StackNode* head);
struct StackNode* stackPush(struct StackNode* head,struct TreeNode* t_pointer);
int IsEmpty(struct StackNode* head);
int* inorderTraversal(struct TreeNode* root,int* returnSize);
void NewChecker(struct TreeNode* tnode);
int IsChecker(struct TreeNode* tnode);
void visit(struct TreeNode* tnode);

int main()
{
    int returnSize;
    struct TreeNode* root = treeBuild(1);
    struct TreeNode* Right = treeBuild(2);
    struct TreeNode* RightLeft = treeBuild(3);

    root->right = Right;
    Right->left = RightLeft;

    int* array1 = inorderTraversal(root,&returnSize);
    for(int i=0;i<3;i++)
    {
        printf("%d ",array1[i]);
    }
    return 0;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    int l=3,p=0;
    int* array=(int*)malloc(sizeof(int)*l);

    struct StackNode* st = stackBuild();
    NewChecker(root);
    struct TreeNode* temp = root;
    st = stackPush(st,root); 
    while(!IsEmpty(st))
    {
        while(temp->left && !IsChecker(temp->left))
        {
            st = stackPush(st,temp);
            temp = temp->left;
        }
        visit(temp);
        array[p]=temp->val;
        //(*returnSize)++;
        p++;
        if(temp->right && !IsChecker(temp->right))
        {
            temp = temp->right;
        }
        else
        {
            temp = stackTop(st);
            st = stackPop(st);
        }
    }
    return array;
}


struct TreeNode* treeBuild(int val)
{
    struct TreeNode* newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->left =NULL;
    newnode->right = NULL;
    newnode->val = val;
    newnode->visited=1;

    return newnode;
}
struct StackNode* stackBuild()
{
    return NULL;
}
struct StackNode* stackPop(struct StackNode* head)
{
    struct StackNode* temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct TreeNode* stackTop(struct StackNode* head)
{
    return head->t_pointer;
}

struct StackNode* stackPush(struct StackNode* head,struct TreeNode* t_pointer)
{
    struct StackNode* newnode=(struct StackNode*)malloc(sizeof(struct StackNode));
    newnode->next = head;
    newnode->t_pointer = t_pointer;

    head = newnode;
    return head;
}
int IsEmpty(struct StackNode* head)
{
    return head==NULL;
}
void NewChecker(struct TreeNode* tnode)
{
    checker = (tnode->visited)+1;
}
int IsChecker(struct TreeNode* root)
{
    return root->visited==checker;
}

void visit(struct TreeNode* tnode)
{
    tnode->visited++;
}
