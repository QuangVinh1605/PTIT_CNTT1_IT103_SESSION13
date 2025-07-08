#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int top;
    int max;
} Stack;

Stack create(int max) {
    Stack s;
    s.a = malloc(max * sizeof(int));
    s.top = -1;
    s.max = max;
    return s;
}

int main() {
    Stack s = create(5);
    printf("Stack max = %d, top = %d\n", s.max, s.top);
    free(s.a);
    return 0;
}
