#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;

    struct ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;
    }

    struct ListNode* result = dummyHead->next;
    free(dummyHead);
    return result;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode* l1_1 = createNode(2);
    l1_1->next = createNode(4);
    l1_1->next->next = createNode(3);

    struct ListNode* l2_1 = createNode(5);
    l2_1->next = createNode(6);
    l2_1->next->next = createNode(4);

    printf("List 1: ");
    printList(l1_1);
    printf("List 2: ");
    printList(l2_1);

    struct ListNode* result1 = addTwoNumbers(l1_1, l2_1);
    printf("Result 1: ");
    printList(result1);

    freeList(l1_1);
    freeList(l2_1);
    freeList(result1);

    printf("\n");

    struct ListNode* l1_2 = createNode(0);
    struct ListNode* l2_2 = createNode(0);

    printf("List 1: ");
    printList(l1_2);
    printf("List 2: ");
    printList(l2_2);

    struct ListNode* result2 = addTwoNumbers(l1_2, l2_2);
    printf("Result 2: ");
    printList(result2);

    freeList(l1_2);
    freeList(l2_2);
    freeList(result2);

    printf("\n");

    struct ListNode* l1_3 = createNode(9);
    l1_3->next = createNode(9);
    l1_3->next->next = createNode(9);
    l1_3->next->next->next = createNode(9);
    l1_3->next->next->next->next = createNode(9);
    l1_3->next->next->next->next->next = createNode(9);
    l1_3->next->next->next->next->next->next = createNode(9);

    struct ListNode* l2_3 = createNode(9);
    l2_3->next = createNode(9);
    l2_3->next->next = createNode(9);
    l2_3->next->next->next = createNode(9);

    printf("List 1: ");
    printList(l1_3);
    printf("List 2: ");
    printList(l2_3);

    struct ListNode* result3 = addTwoNumbers(l1_3, l2_3);
    printf("Result 3: ");
    printList(result3);

    freeList(l1_3);
    freeList(l2_3);
    freeList(result3);

    return 0;
}