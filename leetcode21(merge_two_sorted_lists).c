#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1,struct ListNode* l2);
struct ListNode* ListNodeBuild(int val);
int main()
{
    struct ListNode* first=ListNodeBuild(1);
    struct ListNode* second = ListNodeBuild(2);
    struct ListNode* third = ListNodeBuild(4);
    first->next = second;
    second->next = third;

    struct ListNode* afirst = ListNodeBuild(1);
    struct ListNode* asecond = ListNodeBuild(3);
    struct ListNode* athird = ListNodeBuild(4);
    afirst->next = asecond;
    asecond->next = athird;

    struct ListNode* res = mergeTwoLists(first,afirst);
}

struct ListNode* ListNodeBuild(int val)
{
    struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}
struct ListNode* mergeTwoLists(struct ListNode* l1,struct ListNode* l2)
{
    struct ListNode* temp = NULL;
    for(int 
}
