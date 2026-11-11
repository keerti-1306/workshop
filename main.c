#include <stdio.h>
#include <string.h>

int main(void) {
    char s[10005];
    char stack[10005];
    int top = -1;

    scanf("%10000s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top < 0) {
                printf("false\n");
                return 0;
            }

            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                printf("false\n");
                return 0;
            }
        }
    }

    printf("%s\n", top == -1 ? "true" : "false");
    return 0;
}
