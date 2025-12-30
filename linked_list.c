#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertEnd(struct Node *head, int val) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;

    if (!head) return n;

    struct Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    return head;
}

void display(struct Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int n, x;

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    display(head);
    return 0;
}
