/* 201202564
일본어학전공
이영종*/

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
	Node* f = createNode('2', NULL, NULL);
	Node* g = createNode('7', NULL, NULL);
	Node* e = createNode('3', NULL, NULL);
	Node* d = createNode('4', NULL, NULL);
	Node* c = createNode('*', f, g);
	Node* b = createNode('+', d, e);
	Node* a = createNode('/', b, c);
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