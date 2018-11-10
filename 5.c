#include <stdio.h>
#include <stdlib.h>

#define N 32

typedef struct Node
{
    int data;
    struct Node* child[2];
} Node;

Node* new_node()
{
    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = 0;
    node -> child[0] = node -> child[1] = NULL;
    return node;
}

void erase(Node* root)
{
    if(root == NULL)
        return;
    erase(root -> child[0]);
    erase(root -> child[1]);
    free(root);
}

int main()
{
    int n, i, t, d;
    Node* root = new_node();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &d);
        Node* node = root;
        for(i = N-1; i >= 0; i--)
        {
            int bit = ((d >> i) & 1) ^ 1;
            if(node -> child[bit])
                node = node -> child[bit];
            else
                node = node -> child[bit] = new_node();
        }
        node -> data = d;
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &d);
        Node* node = root;
        for(i = N-1; i >= 0; i--)
        {
            int bit = (d >> i) & 1;
            if(node -> child[bit])
                node = node -> child[bit];
            else
                node = node -> child[1-bit];
        }
        printf("%d\n", d ^ (node -> data));
    }
    erase(root);
    return 0;
}