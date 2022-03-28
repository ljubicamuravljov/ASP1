#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char ime;
	struct node* next;
	struct node* niz;
	int pos;
} node;
typedef struct graf {
	node* start;
	node* cilj;
	node** niz;
} graf;
graf* init_graf(graf* G) {
	G->start = NULL;
	G->niz = NULL;
	G->cilj = NULL;
}
node* addNode(char p) {

	node* novi = NULL;
	novi = (node*)malloc(sizeof(node));
	novi->niz = NULL;
	novi->ime = p;
	novi->next = NULL;
	novi->pos = 0;
	return novi;
}
typedef struct queue {
	node* top;
	node* rear;


}queue;
queue* init_Q(queue* Q) {
	Q->top = NULL;
	Q->rear = NULL;
	return Q;
}
node* POP_Q(queue* Q) {
	node* t, * p;
	t = Q->top;
	if (t == Q->rear) {
		p = Q->top;
		Q->top = NULL;
		return p;

	}
	if (t == NULL)return NULL;
	while (t->next != Q->rear) {
		t = t->next;
	}
	p = Q->rear;
	Q->rear = t;
	//t->next = NULL;
	return p;


}
queue* insert_Q(queue* Q, node* temp) {
	node* t = NULL, * pom;
	t = malloc(sizeof(node));
	t->ime = temp->ime;
	t->next = temp->next;
	t->niz = temp->niz;



	if (Q->top == NULL) {
		Q->top = t;
	}
	else {

		Q->rear->next = t;
	}
	Q->rear = t;

	return Q;
}
node* delete_Q(queue* Q) {

	node* t = NULL, * p = NULL;

	if (Q->top != NULL) {
		t = Q->top;

		Q->top = t->next;
		if (Q->top == NULL) {
			Q->rear = NULL;
		}

	}

	return t;
}

int player2najkraci(node** niz, int n, graf* g, node** top, node** rear, int* sanj) {
	queue* red = NULL, * red2 = NULL;
	*sanj = 0;
	node* cilj = NULL;
	node* pomocna = NULL, * pomocna1 = NULL, * pomocna2 = NULL, * pomocna3 = NULL, * izlaz = NULL;
	pomocna1 = malloc(sizeof(node));
	pomocna2 = malloc(sizeof(node));
	pomocna3 = malloc(sizeof(node));
	pomocna1->ime = '0';
	cilj = g->cilj;
	int i = 0, c = 1, flag;
	red = malloc(sizeof(queue));
	red = init_Q(red);
	//red sluzi da stavljam tu sve cvorove koje prodjem, da bih dalje isla njihovim granama
	pomocna = g->start;
	pomocna = pomocna->next;
	red = insert_Q(red, pomocna1);


	while (1) {

		//nizz[i++] = pomocna->ime;
		if (c % 2 == 1) {
			flag = 0;

			//dodam na niz trenutni cvor
			while (pomocna != NULL && pomocna->ime != '0') {
				if (pomocna->ime == cilj->ime) {
					//ako dodjem do cilja vratim duzinu ( to ce biti najkraca)
					return c;
				}
				else {
					//ako nije cilj, dodajem na red i kasnije cu ukoliko treba prolaziti ovim cvorom ka dalje
					pomocna3->ime = pomocna->ime;
					pomocna3->next = pomocna->next;
					pomocna3->niz = pomocna->niz;
					red = insert_Q(red, pomocna3);
				}

				pomocna = pomocna->next;
			}

			//kad sam prosla sve 'sinove' jednog cvora, ukoliko nisam dosla do cilja dodam 0 na red
			//red = insert_Q(red,pomocna1);

		}
		else {

			while (pomocna != NULL && pomocna->ime != '0') {
				pomocna2 = pomocna->niz->next;
				while (pomocna2 != NULL && pomocna2->ime != '0') {
					if (pomocna2->ime == cilj->ime) { return c; }
					else {
						red = insert_Q(red, pomocna2);
						pomocna2 = pomocna2->next;
					}

				}
				pomocna = pomocna->next;

			}
			//red = insert_Q(red, pomocna1);
		}
		pomocna = delete_Q(red);
		if (red->top == 0xCDCDCDCD) return -1;
		if (red->top == NULL)return -1;
		if (pomocna->ime == '0') {
			/*if (c % 2 == 0) {
				(*sanj) += 1;
			}
			else {
				(*sanj)+=2;
			}*/
			//if (red->top == red->rear) return-1;
			red = insert_Q(red, pomocna1);
			c++;
			pomocna = delete_Q(red);
			//ako naidjem na 0 znam da mi se broj grana prolaska povecava
			if (pomocna->ime == '0') return -1;
		}
		int j, m;
		if (c >= (n * n)) return -1;
		flag = 0;


		pomocna = pomocna->niz->next;
		//if ( (c>n/2)&&(red->top == red->rear) && (red->top->ime = '0')) return -1;
	}

}


void player1putevi(int n, graf* g) {


	node* top, * rear;
	node** stek = NULL;
	node* start, * cilj, * pom, * pom2, * pom3;
	int i = 0;

	start = g->start;
	cilj = g->cilj;
	int c = 0, sanj = 0;

	pom = malloc(sizeof(node));
	pom2 = malloc(sizeof(node));
	pom3 = malloc(sizeof(node));

	pom3->ime = start->ime;
	pom3->next = start->next;
	pom3->niz = start->niz;
	stek = realloc(stek, (i + 1) * sizeof(node*));
	stek[i++] = start;
	stek = realloc(stek, (i + 1) * sizeof(node*));

	stek[i++] = pom3;
	//red = insert_Q(red, pom3);
	//red = insert_Q(red, pom3);
	while (stek[0] != NULL) {
		if (pom == NULL) pom = malloc(sizeof(node));
		pom->niz = stek[i - 1]->niz;
		pom->ime = stek[i - 1]->ime;
		pom->next = stek[i - 1]->next;

		stek[--i] = NULL;
		if (i == 0)break;
		pom = pom->next;

		while (pom != NULL && i != n + 2) {
			if (pom->ime != cilj->ime) {
				if (i == n + 1) {
					break;
				}
				/*pom3->ime = pom->ime;
				pom3->next = pom->next;
				pom3->niz = pom->niz;*/
				if (i == n) {

					pom = pom->next;
					continue;
				}
				stek = realloc(stek, (i + 1) * sizeof(node*));
				stek[i++] = pom;
				//red = insert_Q(red, pom3);

				c++;
			}
			else {
				/*pom3->ime = pom->ime;
				pom3->next = pom->next;
				pom3->niz = pom->niz;*/
				stek = realloc(stek, (i + 1) * sizeof(node*));
				stek[i++] = pom;


				if (i == n + 1) {


					for (int j = 0; j < i - 1; j++) {
						pom2 = stek[j];
						printf(" %c ->", pom2->ime);

					}
					pom2 = stek[i - 1];
					printf(" %c\n", pom2->ime);

					pom2 = stek[i - 1];
					stek[--i] = NULL;
					pom = pom->next;

					continue;
				}

			}

			pom = pom->niz->next;

		}

	}

	free(stek);


}

int player1najkraci(node** niz, int n, graf* g, node** top, node** rear) {
	queue* red = NULL;
	char* nizz = NULL;
	node* pomocna = NULL, * pomocna1 = NULL, * pomocna2 = NULL, * pomocna3 = NULL, * izlaz = NULL;
	pomocna1 = malloc(sizeof(node));
	pomocna3 = malloc(sizeof(node));
	pomocna1->ime = '0';
	pomocna1->next = NULL;
	pomocna = g->start;
	pomocna = pomocna->next;
	node* cilj = g->cilj;
	pomocna2 = malloc(sizeof(node));

	int i = 0, flag = 0;


	//nizz sluzi da stavim tu cvorove koje sam vec prosla, da bih proverila da li dolazi do ciklusa
	/*nizz = realloc(nizz, (i+1) * sizeof(char));
	nizz[i++] = start->ime;
	*/
	red = malloc(sizeof(queue));
	red = init_Q(red);
	//red sluzi da stavljam tu sve cvorove koje prodjem, da bih dalje isla njihovim granama
	red = insert_Q(red, pomocna1);


	int c = 1;
	while (1) {
		flag = 0;

		//dodam na niz trenutni cvor
		while (pomocna != NULL && pomocna->ime != '0') {
			if (pomocna->ime == cilj->ime) {
				//ako dodjem do cilja vratim duzinu ( to ce biti najkraca)
				free(pomocna1);
				free(pomocna2);
				free(pomocna3);
				return c;
			}
			else {
				pomocna3->ime = pomocna->ime;
				pomocna3->next = pomocna->next;
				pomocna3->niz = pomocna->niz;
				red = insert_Q(red, pomocna3);
				//ako nije cilj, dodajem na red i kasnije cu ukoliko treba prolaziti ovim cvorom ka dalje

			}

			pomocna = pomocna->next;
		}

		//kad sam prosla sve 'sinove' jednog cvora, ukoliko nisam dosla do cilja dodam 0 na red
		//red = insert_Q(red,pomocna1);

		pomocna = delete_Q(red);
		if (pomocna->ime == '0') {
			c++;

			red = insert_Q(red, pomocna1);

			pomocna = delete_Q(red);
			//ako naidjem na 0 znam da mi se broj grana prolaska povecava
			//if (red->top == red->rear) return-1;
			if (pomocna->ime == '0') { 
				free(pomocna1);
				free(pomocna2);
				free(pomocna3);
				return -1; }
		}
		int j;
		while (1) {

			for (j = 0; j < i; j++) {
				if (pomocna->ime == nizz[j]) {

					pomocna = delete_Q(red);
					break;


				}

				if (pomocna->ime == '0') { 
					free(pomocna1);
					free(pomocna2);
					free(pomocna3);
					return -1; }
			}

			if (j == i) break;

		}
		nizz = realloc(nizz, (i + 1) * sizeof(char));
		for (int j = 0; j < i; j++) {
			if (nizz[j] == pomocna->ime) {
				flag = 1;
			}
		}
		if (flag == 0) { nizz[i++] = pomocna->ime; }
		if (red->top == NULL) { 
			free(pomocna1);
			free(pomocna2);
			free(pomocna3);
			return -1; }
		pomocna = pomocna->niz->next;
		//ukoliko mi na redu sledi 0, proveravam da l trenutnim elementom pravim ciklus


	}
}


char* a1(int* flag, node** start, node** cilj, int* n, node** niz, char* p, char* pp) {

	*flag = 1;
	printf("\nUneti zeljeni broj cvorova: ");
	scanf("%d", n);
	niz = malloc(*n * sizeof(node));
	for (int i = 0; i < *n; i++) {
		printf("Uneti naziv %d-og cvora: ", i + 1);
		scanf(" %c", p);
		niz[i] = addNode(*p);


	}
	for (int i = 0; i < *n; i++) {
		printf("%c ", niz[i]->ime);

	}
	printf("Uneti naziv START-cvora i CILJ-cvora (npr A Y) : ");
	scanf(" %c %c", p, pp);
	for (int i = 0; i < *n; i++) {
		if (niz[i]->ime == *p) *start = niz[i];
		if (niz[i]->ime == *pp) *cilj = niz[i];
	}
	return niz;


}

void a2(node** niz, int* n, char* p) {

	niz = realloc(niz, ((*n)++) * sizeof(node));
	printf("Uneti naziv %d-og cvora: ", *n);
	scanf(" %c", p);
	niz[*n - 1] = addNode(*p);


}

void a3(node** niz, int* n, int* t) {

	for (int i = 0; i < *n; i++) {
		printf("%c ", niz[i]->ime);

	}
	printf("\n Odabrati redni broj cvora za brisanje (1-%d): ", *n);
	scanf("%d", t);
	(*t)--;
	for (int i = *t; i < *n - 1; i++) {
		niz[i] = niz[i + 1];

	}
	(*n)--;
	niz = realloc(niz, (*n) * sizeof(node));

}


void a4(node** niz, int* n, int* flag2, node* pom, char* p) {
	for (int i = 0; i < *n; i++) {
		printf("%c ", niz[i]->ime);

	}

	printf("Za svaki cvor ispisati sa kojim cvorovima zelite da ih povezete: \n");
	for (int i = 0; i < *n; i++) {
		printf("\n %c: ", niz[i]->ime);
		pom = niz[i];
		while (pom->next != NULL) {
			pom = pom->next;
		}
		if (!(*flag2)) *p = getchar();
		*flag2 = 1;
		while ((*p = getchar()) != '\n') {
			if (*p != ' ') {
				pom->next = addNode(*p);
				pom = pom->next;

				for (int j = 0; j < *n; j++) {

					if (niz[j]->ime == *p) pom->niz = niz[j];
				}
			}
			else continue;
		}

	}
}


void a5(node** niz, int* n, char* p, node* pom, node* temp) {

	for (int i = 0; i < *n; i++) {
		printf("%c ", niz[i]->ime);

	}

	printf("Unesite naziv cvora, ciju izlaznu granu zelite da izbrisete\n");
	printf("[Npr, ukoliko zelite da izbirsete vezu A->B, unesite cvor A]:  \n");
	*p = getchar();
	*p = getchar();
	int i = 0;
	while (niz[i]->ime != *p) i++;
	pom = niz[i];
	while (pom->next != NULL) {
		printf("%c -> ", pom->ime);
		pom = pom->next;
	}
	printf("%c ", pom->ime);
	printf("Odabrati cvor s kojim zelite da obrisete granu\n");
	printf("[Npr, ukoliko zelite da izbirsete vezu A->B, unesite cvor B]:  \n");
	*p = getchar();
	*p = getchar();
	pom = niz[i];

	while (pom->next->ime != *p) {
		pom = pom->next;
	}
	temp = pom->next;
	pom->next = pom->next->next;
	free(temp);
}


void a6(node** niz, int* n, node* pom) {



	for (int i = 0; i < *n; i++) {
		pom = niz[i];
		while (pom->next != NULL) {
			printf("%c -> ", pom->ime);
			pom = pom->next;
		}
		printf("%c\n", pom->ime);


	}

}

void menu() {
	int a, n, flag = 0, t, flag2 = 0, c = 0, sanj = 0;
	node* top1 = NULL, * cilj1 = NULL, * pom = NULL, * pom1 = NULL, * top = NULL, * rear = NULL, * start = NULL, * start1 = NULL, * cilj = NULL;
	node** niz = NULL, ** niz2 = NULL;
	graf* g = NULL, * g2 = NULL;
	g = malloc(sizeof(graf));
	g2 = malloc(sizeof(graf));
	node* temp = NULL;
	char p, pp;
	while (1) {
		flag2 = 0;
		printf("\nGLAVNI MENI\n");
		printf("-------------\n");
		printf("\n1. Kreiranje grafa");
		printf("\n2. Unos novog cvora");
		printf("\n3. Brisanje cvora");
		printf("\n4. Dodavanje grana");
		printf("\n5. Brisanje grana");
		printf("\n6. Ispis grafa");
		printf("\n7. Pokretanje programa");
		printf("\n8. Kraj programa\n");

		scanf("%d", &a);
if (a == 1) {

			niz = a1(&flag, &start, &cilj, &n, niz, &p, &pp);
			init_graf(g);
		
			g->start = start;
			g->cilj = cilj;
			g->niz = niz;
			
			continue;


		}
		if (a == 2) {
			if (!flag) {
				printf("\nPrvo unesite pocetno stanje grafa\n");
				continue;
			}
			else {
				a2(niz, &n, &p);
				continue;
			}
		}

		if (a == 3) {
			if (!flag) {
				printf("\nPrvo unesite pocetno stanje grafa\n");
				continue;
			}
			else {

				a3(niz, &n, &t);
				continue;

			}

		}
		if (a == 4) {
			if (!flag) {
				printf("\nPrvo unesite pocetno stanje grafa\n");
				continue;
			}

			else {

				a4(niz, &n, &flag2, &pom, &p);

				continue;

			}

		}
		if (a == 5) {
			if (!flag) {
				printf("\nPrvo unesite pocetno stanje grafa\n");
				continue;
			}
			else {
				a5(niz, &n, &p, pom, temp);
				continue;
			}

		}
		if (a == 6) {
			if (!flag) {
				printf("\nPrvo unesite pocetno stanje grafa\n");
				continue;
			}

			else {

				a6(g->niz, &n, pom);

				continue;
			}



		}
		int m, s;
		if (a == 7) {


			m = player1najkraci(niz, &n, g, top, rear);
			if (m == -1) {
				printf("Ne postoji put do cilja.");
			}
			else {


				printf("Najkraci Maja: %d\n", m);

				s = player2najkraci(niz, n, g, top, rear, &sanj);
				if (s == -1) printf("\nSanja nece stici do cilja.\n");
				else {
					printf("\nNajkraci Sanja: %d \n", s);
					if (m < s) printf("\nMaja je pobedila!\n");
					else if (m > s) printf("\nSanja je pobedila!\n");
					else printf("\nNereseno je!\n");
					printf("Majini putevi: \n");


				}

				player1putevi(m, g);
				printf("--\n");
				if (s % 2) {
					sanj = 3 * (s / 2) + 1;
				}
				else sanj = 3 * s / 2;

				if (s != -1) {
					player1putevi(sanj, g);
				}


			}


		}
		if (a == 8) {

			free(g);
			for (int i = 0; i < n; i++) {
				free(niz[i]);
			}
			free(niz);
			return 0;
		}
	}
}


int main() {
	menu();


	return 0;
}