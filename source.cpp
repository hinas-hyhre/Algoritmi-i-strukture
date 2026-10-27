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
int dodaj_iza_odredjenog(pozicija, char[]);
int dodaj_ispred_odredjenog(pozicija, char[]);
void sortiraj(pozicija);
void upisi_u_datoteku(pozicija);
void citaj_datoteku(pozicija);

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
		printf("\n\n\n%s %s %d.%d.%d", head->ime, head->prezime, head->datum_rodjenja.dan, head->datum_rodjenja.mjesec, head->datum_rodjenja.godina);
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

int dodaj_iza_odredjenog(pozicija head, char prezime[]) {
	pozicija novi = (pozicija)malloc(sizeof(student));

	printf("\nunesite ime:\n");
	scanf(" %s", novi->ime);
	printf("\nunesite prezime:\n");
	scanf(" %s", novi->prezime);
	printf("\nunesite datum rodjenja:\n");
	scanf(" %d.%d.%d", &novi->datum_rodjenja.dan, &novi->datum_rodjenja.mjesec, &novi->datum_rodjenja.godina);


	while (head->next != NULL && strcmp(head->next->prezime, prezime) != 0) {
		head = head->next;

	}

	if (head->next == NULL) {
		free(novi);
		return -1;

	}
	
	
	novi->next = head->next->next;
	head->next->next = novi;

	return 0;



}

	int dodaj_ispred_odredjenog(pozicija head, char prezime[]) {
		pozicija novi = (pozicija)malloc(sizeof(student));

		printf("\nunesite ime:\n");
		scanf(" %s", novi->ime);
		printf("\nunesite prezime:\n");
		scanf(" %s", novi->prezime);
		printf("\nunesite datum rodjenja:\n");
		scanf(" %d.%d.%d", &novi->datum_rodjenja.dan, &novi->datum_rodjenja.mjesec, &novi->datum_rodjenja.godina);


		while (head->next != NULL && strcmp(head->next->prezime, prezime) != 0) {
			head = head->next;

		}

		if (head->next == NULL) {
			free(novi);
			return -1;
		}


		novi->next = head->next;
		head->next = novi;

			return 0;



		}

	void sortiraj(pozicija head) {
		int promjena = 1;
		pozicija temp = NULL;
		pozicija pocetak = head;

		while (promjena == 1) {
			promjena = 0;
			head = pocetak;

			while (head->next != NULL && head->next->next != NULL) {
				if (strcmp(head->next->prezime,
					head->next->next->prezime) > 0) {

					temp = head->next->next;
					head->next->next = temp->next;
					temp->next = head->next;
					head->next = temp;

					promjena = 1;
				}
				else {
					head = head->next;
				}
			}
		}
	}

	void upisi_u_datoteku(pozicija head) {
		FILE* fp;
		fp = fopen("studenti.txt", "w");
		if (!fp) {
			printf("pogreska u otvaranju");

		}
		else
		{
			printf("\nsada se upisuje u datoteku");

			while (head != NULL) {
				fprintf(fp, "\n%s %s %d.%d.%d", head->ime, head->prezime, head->datum_rodjenja.dan, head->datum_rodjenja.mjesec, head->datum_rodjenja.godina);
				head = head->next;
			}
			
			fclose(fp);
		}

	}

	void citaj_datoteku(pozicija head) {
		FILE* fp;
		pozicija temp = (pozicija)malloc(sizeof(student));

		fp = fopen("studenti.txt", "r");
		if (!fp) {
			printf("pogreskaaaa");
			return;
		}
		else
		{
			printf("\nsada se cita datoteka");
			while (fscanf(fp, "%s %s %d.%d.%d", temp->ime, temp->prezime, &temp->datum_rodjenja.dan, &temp->datum_rodjenja.mjesec, &temp->datum_rodjenja.godina) == 5) {
				printf("\n%s %s %d.%d.%d", temp->ime, temp->prezime, temp->datum_rodjenja.dan, temp->datum_rodjenja.mjesec, temp->datum_rodjenja.godina);
			}
			free(temp);
			fclose(fp);
		}

	}



int main() {

	student head = { 0 };
	pozicija neki_student = (pozicija)(malloc)(sizeof(student));
	char prezime[20] = "abc";
	

	dodaj_na_kraj(&head);

	ispis(head.next);

	dodaj_iza_odredjenog(&head, prezime);

	dodaj_ispred_odredjenog(&head, prezime);

	sortiraj(&head);

	upisi_u_datoteku(head.next);

	citaj_datoteku(head.next);

	ispis(head.next);






	return 0;
}
