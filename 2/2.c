/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curNode;
    struct ListNode* nextNode;
    curNode = res;
    int singleRes = l1->val + l2->val + carry;
    curNode->val = singleRes % 10;
    carry = singleRes / 10;
    l1 = l1->next;
    l2 = l2->next;
    struct ListNode zero;
    zero.val = 0;
    zero.next = &zero;
    while (l1 && l2) {
        nextNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        curNode->next = nextNode;
        curNode = nextNode;
        singleRes = l1->val + l2->val + carry;
        curNode->val = singleRes % 10;
        carry = singleRes / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1) {
        while (l1) {
            nextNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            curNode->next = nextNode;
            curNode = nextNode;
            singleRes = l1->val + carry;
            curNode->val = singleRes % 10;
            carry = singleRes / 10;
            l1 = l1->next;
        }
    }
    if (l2) {
        while (l2) {
            nextNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            curNode->next = nextNode;
            curNode = nextNode;
            singleRes = l2->val + carry;
            curNode->val = singleRes % 10;
            carry = singleRes / 10;
            l2 = l2->next;
        }
    }
    if (carry) {
        nextNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        curNode->next = nextNode;
        nextNode->val = 1;
        nextNode->next = NULL;
    } else
        curNode->next = NULL;
    return res;
}