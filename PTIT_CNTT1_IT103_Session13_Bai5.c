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

int pop(Stack *s) {
    if (s->top == -1)
        return -1;
    return s->a[(s->top)--];
}

void reverseArray(int arr[], int n) {
    Stack s = create(n);
    for (int i = 0; i < n; i++)
        push(&s, arr[i]);
    for (int i = 0; i < n; i++)
        arr[i] = pop(&s);
    free(s.a);
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);

    int arr[n];
    printf("nhap cac phan tu:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("truoc khi dao:\n");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("sau khi dao:\n");
    printArray(arr, n);

    return 0;
}
