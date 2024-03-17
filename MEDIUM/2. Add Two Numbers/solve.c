/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Tlist;

void insert(Tlist ** l, int x){
    if ((*l) == NULL) {
        (*l) = malloc(sizeof(Tlist));
        (*l) -> next = NULL;
        (*l) -> val = x;
    }
    else {
        Tlist* curr = *l;
        while (curr -> next != NULL) {
            curr = curr -> next;
        }
        Tlist* Node = malloc(sizeof(Tlist));
        Node -> val = x;
        Node -> next = NULL;
        (curr) -> next = Node;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 -> val == 0 && l2 -> val == 0 && l1 -> next == NULL && l2 -> next == NULL) return l1;
    Tlist *Node = NULL;
    int remainder = 0;
    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL && l2 != NULL) {
            insert(&Node, (l1 -> val + l2 -> val + remainder) % 10);
            remainder = l1 -> val + l2 -> val + remainder >= 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        else if ( l1 != NULL) {
            insert(&Node, (l1 -> val + remainder) % 10);
            remainder = l1 -> val + remainder >= 10;
            l1 = l1 -> next;
        }
        else if ( l2 != NULL) {
            insert(&Node, (l2 -> val + remainder) % 10);
            remainder = l2 -> val + remainder >= 10;
            l2 = l2 -> next;
        }
        if ( l1 == l2 && l2 == NULL) {
            Tlist *curr = Node;
            while (curr -> next != NULL) {
                curr = curr -> next;
            }
            if (remainder != 0) {
                insert(&curr, 1);
            }
        } 
    }
    return Node;
}
