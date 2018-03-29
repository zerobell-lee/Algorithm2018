#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char data;
	struct _Node *left;
	struct _Node *right;
} Node;

Node *createNode(char data,
	Node *left, Node *right) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->left = left;
	p->right = right;
	return p;
}

void inorder(Node *p) {
	if (p == NULL) return;
	inorder(p->left);
	printf("%c ", p->data);
	inorder(p->right);
}

void preorder(Node *p) {
	if (p == NULL) return;
	printf("%c ", p->data);
	preorder(p->left);
	preorder(p->right);
}

void postorder(Node *p) {
	if (p == NULL) return;
	postorder(p->left);
	postorder(p->right);
	printf("%c ", p->data);
}

void main() {
	Node* h = createNode('H', NULL, NULL);
	Node* i = createNode('I', NULL, NULL);
	Node* j = createNode('J', NULL, NULL);
	Node* f = createNode('F', NULL, NULL);
	Node* k = createNode('K', NULL, NULL);
	Node* g = createNode('G', NULL, k);
	Node *e = createNode('E', i, j);
	Node *d = createNode('D', h, NULL);
	Node *c = createNode('C', f, g);
	Node *b = createNode('B', d, e);
	Node *a = createNode('A', b, c);
	printf("Preorder: ");
	preorder(a);
	printf("\n");
	printf("Inorder: ");
	inorder(a);
	printf("\n");
	printf("Postorder: ");
	postorder(a);
	printf("\n");
}