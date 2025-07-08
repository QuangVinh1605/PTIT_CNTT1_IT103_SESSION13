#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int top;
    int cap;
} Stack;

Stack create(int cap) {
    Stack s;
    s.a = malloc(cap * sizeof(int));
    s.top = -1;
    s.cap = cap;
    return s;
}

void push(Stack *s, int x) {
    if (s->top < s->cap - 1)
        s->a[++(s->top)] = x;
}

void printStackInfo(Stack s) {
    printf("stack={\nelements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.a[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\ntop: %d,\ncap: %d\n}\n", s.top, s.cap);
}

void viewAll(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%d\n", s.a[i]);
    }
}

int main() {
    Stack s = create(5);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    printStackInfo(s);
    viewAll(s);

    free(s.a);
    return 0;
}
