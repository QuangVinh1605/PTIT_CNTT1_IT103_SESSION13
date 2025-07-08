#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *a;
    int top;
    int cap;
} Stack;

Stack create(int cap) {
    Stack s;
    s.a = malloc(sizeof(char) * cap);
    s.top = -1;
    s.cap = cap;
    return s;
}

void push(Stack *s, char c) {
    if (s->top < s->cap - 1)
        s->a[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top == -1)
        return '\0';
    return s->a[(s->top)--];
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    Stack s = create(len);

    for (int i = 0; i < len; i++)
        push(&s, str[i]);

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            free(s.a);
            return 0;
        }
    }

    free(s.a);
    return 1;
}

int main() {
    char str[100];

    printf("nhap chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
