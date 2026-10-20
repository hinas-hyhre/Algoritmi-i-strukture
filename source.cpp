#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Student student;
typedef struct Student* pozicija;
typedef struct Datum datum;
int unos_na_pocetak(pozicija);
void ispis(pozicija);
int dodaj_na_kraj(pozicija);
pozicija pronadji(pozicija, char[]);
void brisi(pozicija, char);

struct Datum {
	int dan;
	int mjesec;
	int godina;


};

struct Student {

	char ime[20];
	char prezime[20];
	datum datum_rodjenja;
	pozicija next;
	

};

int unos_na_pocetak(pozicija head) {
	pozicija novi = (pozicija)malloc(sizeof(student));

	printf("\nunesite ime:\n");
	scanf(" %s", novi->ime);
	printf("\nunesite prezime:\n");
	scanf(" %s", novi->prezime);
	printf("\nunesite datum rodjenja:\n");
	scanf(" %d.%d.%d", &novi->datum_rodjenja.dan, &novi->datum_rodjenja.mjesec, &novi->datum_rodjenja.godina);

	novi->next = head->next;
	head->next = novi;

	return 0;


}

void ispis(pozicija head) {

	while (head != NULL) {
		printf("\n%s %s %d.%d.%d", head->ime, head->prezime, head->datum_rodjenja.dan, head->datum_rodjenja.mjesec, head->datum_rodjenja.godina);
		head = head->next;
	}


}

int dodaj_na_kraj(pozicija head) {
	pozicija novi = (pozicija)malloc(sizeof(student));

	printf("\nunesite ime:\n");
	scanf(" %s", novi->ime);
	printf("\nunesite prezime:\n");
	scanf(" %s", novi->prezime);
	printf("\nunesite datum rodjenja:\n");
	scanf(" %d.%d.%d", &novi->datum_rodjenja.dan, &novi->datum_rodjenja.mjesec, &novi->datum_rodjenja.godina);

	while (head->next != NULL) {
		head = head->next;
	}

	novi->next = head->next;
	head->next = novi;

	return 0;
}

pozicija pronadji(pozicija head, char prezime[]) {

	while (head != NULL && (strcmp(prezime, head->prezime) != 0)) {
		head = head->next;
	}

	if (head == NULL) {
		printf("\ngreska ne postoji");
	

		return NULL;
	}
	else
	{
		return head;
	}

}

void brisi(pozicija head, char prezime[])
{
	
	pozicija temp;

	while (head->next != NULL && strcmp(prezime, head->next->prezime) != 0) {
		head = head->next;
	}

	if (head->next == NULL) {
		printf("\nGreska, ne postoji");
	}
	else {
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}

 
int main() {

	student head = { 0 };
	pozicija neki_student = (pozicija)(malloc)(sizeof(student));
	char prezime[20] = "abc";
	unos_na_pocetak(&head);
	
	dodaj_na_kraj(&head);

	ispis(head.next);

	neki_student = pronadji(&head, prezime);

	printf("\npronadjeni student:\n%s %s %d.%d.%d", neki_student->ime, neki_student->prezime, neki_student->datum_rodjenja.dan, neki_student->datum_rodjenja.mjesec, neki_student->datum_rodjenja.godina);

	brisi(&head, prezime);


	ispis(head.next);

	

	
	

	return 0;
}