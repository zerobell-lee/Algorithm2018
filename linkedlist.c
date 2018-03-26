#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	char data[20];
	struct _Node* link;
} Node;

void printList(Node *list) {

	Node* p=list;
	while(p!=NULL) {
		printf("[%s]", p->data);
		if (p->link!=NULL)
			printf("->");
		else
			printf("\n");
		p = p->link;

	} 

}

Node *newNode(char data[]) {
	Node *p = (Node*)malloc(sizeof(Node));
	strcpy(p->data, data);
	p->link = NULL;
	return p;
}

Node *addFirstNode(Node *list, Node *p) {
	p->link = list;
	return p;
}

Node *addLastNode(Node *list, Node *p) {
	Node* q=list;
	if (q==NULL) {
		p->link = q;
		return q;
	}
	while (q->link!=NULL)
		q=q->link;
	q->link=p;
	return list;
}

void main() {
	Node* list = NULL;
	
	list = addFirstNode(list, newNode("Wed"));
	printList(list);
	list = addFirstNode(list, newNode("Tue"));
	printList(list);
	list = addFirstNode(list, newNode("Mon"));
	printList(list);

	list = addLastNode(list, newNode("Thu"));
	printList(list);
	list = addLastNode(list, newNode("Fri"));
	printList(list);
}	
