#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct LNode {
	int coef;  //系数
	int expon; //指数
	struct LNode *next;
}LNode, *Polynomial;
void Attach(int a, int b, Polynomial *rear)
{
	Polynomial temp = (Polynomial)malloc(sizeof(LNode));
	temp->coef = a;
	temp->expon = b;
	temp->next = NULL;
	(*rear)->next = temp;
	(*rear) = temp;
}
Polynomial PolyAdd(Polynomial p1, Polynomial p2)
{
	Polynomial front, rear, temp;
	int sum;
	front = rear = (Polynomial)malloc(sizeof(LNode));
	while (p1 && p2) {
		if (p1->expon > p2->expon) {
			Attach(p1->coef, p1->expon, &rear);
			p1 = p1->next;
		}
		else if (p1->expon < p2->expon) {
			Attach(p2->coef, p2->expon, &rear);
			p2 = p2->next;
		}
		else {
			sum = p1->coef + p2->coef;
			if (sum) Attach(sum, p1->expon, &rear);
				p1 = p1->next;
				p2 = p2->next;
		}
	}
	for (; p1; p1 = p1->next) Attach(p1->coef, p1->expon, &rear);
	for (; p2; p2 = p2->next) Attach(p2->coef, p2->expon, &rear);
	temp = front;
	front = front->next;
	free(temp);
	return front;
}
void create(Polynomial p)
{
	int n, coef, expon;
	Polynomial rear = p;
	cin >> n;
	while (n--) {
		cin >> coef >> expon;
		Polynomial temp = (Polynomial)malloc(sizeof(LNode));
		temp->coef = coef; temp->expon = expon; temp->next = NULL;
		rear->next = temp;
		rear = temp;
	}
}
int main()
{
	Polynomial p1, p2, p3;
	p1 = (Polynomial)malloc(sizeof(LNode));
	p2 = (Polynomial)malloc(sizeof(LNode));
	create(p1);
	create(p2);
	p1 = p1->next;
	p2 = p2->next;
	p3 = PolyAdd(p1, p2);
	Polynomial tmp = p3;
	while (tmp) {
		cout << tmp->coef << " " << tmp->expon << endl;
		tmp = tmp->next;
	}

	return 0;
}