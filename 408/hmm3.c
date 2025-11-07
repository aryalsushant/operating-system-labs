#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char val;
    struct Node *l, *r;
} Node;

Node* mk(char v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = v; n->l = n->r = NULL;
    return n;
}

typedef struct QN {
    void *x;
    struct QN *next;
} QN;

typedef struct Q {
    QN *front, *back;
} Q;

Q* q_new() {
    Q* q = (Q*)malloc(sizeof(Q));
    q->front = q->back = NULL;
    return q;
}

void q_push(Q* q, void* x) {
    QN* n = (QN*)malloc(sizeof(QN));
    n->x = x; n->next = NULL;
    if (!q->back) q->front = q->back = n;
    else { q->back->next = n; q->back = n; }
}

void* q_pop(Q* q) {
    if (!q->front) return NULL;
    QN* n = q->front;
    void* x = n->x;
    q->front = n->next;
    if (!q->front) q->back = NULL;
    free(n);
    return x;
}

int q_empty(Q* q) { return q->front == NULL; }

typedef struct SN {
    void *x;
    struct SN *next;
} SN;

typedef struct ST {
    SN *top;
} ST;

ST* st_new() {
    ST* s = (ST*)malloc(sizeof(ST));
    s->top = NULL; return s;
}

void st_push(ST* s, void* x) {
    SN* n = (SN*)malloc(sizeof(SN));
    n->x = x; n->next = s->top; s->top = n;
}

void* st_pop(ST* s) {
    if (!s->top) return NULL;
    SN* n = s->top; void* x = n->x;
    s->top = n->next; free(n); return x;
}

int st_empty(ST* s) { return s->top == NULL; }

void bfs(Node* root) {
    if (!root) return;
    Q* q = q_new();
    q_push(q, root);
    while (!q_empty(q)) {
        Node* cur = (Node*)q_pop(q);
        printf("%c ", cur->val);
        if (cur->l) q_push(q, cur->l);
        if (cur->r) q_push(q, cur->r);
    }
    printf("\n");
    free(q);
}

void postorder_iter(Node* root) {
    if (!root) return;
    ST *s1 = st_new(), *s2 = st_new();
    st_push(s1, root);
    while (!st_empty(s1)) {
        Node* n = (Node*)st_pop(s1);
        st_push(s2, n);
        if (n->l) st_push(s1, n->l);
        if (n->r) st_push(s1, n->r);
    }
    while (!st_empty(s2)) {
        Node* n = (Node*)st_pop(s2);
        printf("%c ", n->val);
    }
    printf("\n");
    free(s1); free(s2);
}

int main() {
    Node* r = mk('A');
    r->l = mk('B'); r->r = mk('C');
    r->l->l = mk('D'); r->l->r = mk('E');
    r->r->l = mk('F'); r->r->r = mk('G');
    r->l->l->l = mk('H');
    r->l->r->l = mk('I'); r->l->r->r = mk('J');
    r->r->r->l = mk('K');
    r->l->r->r->r = mk('L');

    printf("Level order:\n");
    bfs(r);
    printf("\nPost order (iterative):\n");
    postorder_iter(r);
    return 0;
}
