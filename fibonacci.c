#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    TypeTag type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    FIBO,
    CONST
} TypeTag;

Node* makeFunc(TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* makeConst(int value) {
    Node* newNode = makeFunc(CONST);
    newNode->value = value;
    return newNode;
}

void calc(Node* node) {
    if (node == NULL) return;

    switch (node->type) {
        case ADD:
            node->value = node->left->value + node->right->value;
            printf("add: %d\n", node->value);
            break;
        case SUB:
            node->value = node->left->value - node->right->value;
            printf("sub: %d\n", node->value);
            break;
        case MUL:
            node->value = node->left->value * node->right->value;
            printf("mul: %d\n", node->value);
            break;
        case DIV:
            node->value = node->left->value / node->right->value;
            printf("div: %d\n", node->value);
            break;
        case FIBO:
            node->value = fibonacci(node->left->value);
            printf("fibo: %d\n", node->value);
            break;
        case CONST:
            node->value = node->value;
            break;
        default:
            printf("Invalid operation\n");
            break;
    }
}

int fibonacci(int n) {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    Node* add = makeFunc(ADD);
    add->left = makeConst(10);
    add->right = makeConst(6);

    Node* mul = makeFunc(MUL);
    mul->left = makeConst(5);
    mul->right = makeConst(4);

    Node* sub = makeFunc(SUB);
    sub->left = mul;
    sub->right = add;

    Node* fibo = makeFunc(FIBO);
    fibo->left = sub;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    return 0;
}
