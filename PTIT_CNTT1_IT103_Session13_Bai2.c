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

void print(Stack s) {
    printf("stack={\nelements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.a[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\ntop: %d,\ncap: %d\n}\n", s.top, s.cap);
}

int main() {
    Stack s = create(5);
    int x;

    printf("nhap cac phan tu:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &x);
        push(&s, x);
    }

    print(s);
    free(s.a);
    return 0;
}
