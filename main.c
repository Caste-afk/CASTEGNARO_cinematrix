#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char titolo[100];
    char regista[100];
    int annoUscita;
    float durata;
} Film;

bool file_esiste(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}


void Salva(const char *filename, Film **lista, int dim) {
    FILE *fileBinarioWrite = fopen(filename, "wb");
    if (fileBinarioWrite == NULL) {
        printf("Errore: impossibile aprire il file '%s' per la scrittura\n", filename);
        return;
    }

    fwrite(&dim, sizeof(int), 1, fileBinarioWrite);
    fwrite(lista, sizeof(Film), dim, fileBinarioWrite);
    fclose(fileBinarioWrite);
}

void stampa(Film **listaFilm, int attuale){
    for (int i = 0; i < attuale; i++) {
        Film *elemento = listaFilm[i];
        printf("\n=== Film %d ===\n", i + 1);
        printf("Titolo: %s\n", elemento->titolo);
        printf("Regista: %s\n", elemento->regista);
        printf("Anno uscita: %d\n", elemento->annoUscita);
        printf("Durata: %.2f ore\n", elemento->durata);
    }
}

void aggiungiFilm(Film *film) {
    printf("Inserire titolo: ");
    scanf(" %[^\n]", film->titolo);
    printf("Inserire regista: ");
    scanf(" %[^\n]", film->regista);
    printf("Inserire anno uscita: ");
    scanf("%d", &film->annoUscita);
    printf("Inserire durata (ore): ");
    scanf("%f", &film->durata);
}

void Ricerca(Film **lista, int attuale, char criterioRicerca[]) {
    bool trovato = false;
    for (int i = 0; i < attuale; i++) {
        Film *elemento = lista[i];

        if (strcmp(elemento->titolo, criterioRicerca) == 0) {
            printf("\n=== Film trovato: %d ===\n", i + 1);
            printf("Titolo: %s\n", elemento->titolo);
            printf("Regista: %s\n", elemento->regista);
            printf("Anno uscita: %d\n", elemento->annoUscita);
            printf("Durata: %.2f ore\n", elemento->durata);
            trovato = true;
        }
    }
    if (!trovato) {
        printf("Nessun film trovato con il titolo: %s\n", criterioRicerca);
    }
}

void Riordina(Film **lista, int n) {
    int i, j;
    Film *temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (lista[j]->durata > lista[j + 1]->durata) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
    printf("Libreria riordinata per durata!\n");
}

int main(void) {
    char *filename = "../catalogo.txt";
    int dimensione = 1;
    int attuale = 0;
    bool continua = true;

    Film **listaFilm = malloc(dimensione * sizeof(Film*));

    while (continua) {
        if (attuale >= dimensione) {
            dimensione = dimensione + 4;
            listaFilm = realloc(listaFilm, dimensione * sizeof(Film*));
        }

        int input;
        printf("\n=== MENU ===\n");
        printf("1) Aggiungi film\n");
        printf("2) Visualizza catalogo\n");
        printf("3) Ricerca per titolo\n");
        printf("4) Riordina libreria\n");
        printf("Altro) Esci\n");
        printf("Scelta: ");
        scanf("%d", &input);

        if (input == 1) {
            listaFilm[attuale] = malloc(sizeof(Film));
            aggiungiFilm(listaFilm[attuale]);
            attuale++;
            printf("Film aggiunto con successo!\n");
        } else if (input == 2) {
            if (attuale == 0) {
                printf("Catalogo vuoto!\n");
            } else {
                stampa(listaFilm, attuale);
            }
        } else if (input == 3) {
            if (attuale == 0) {
                printf("Catalogo vuoto!\n");
            } else {
                char criterioRicerca[100];
                printf("\nInserisci un titolo: ");
                scanf(" %s\n", criterioRicerca);
                Ricerca(listaFilm, attuale, criterioRicerca);
            }
        } else if (input == 4) {
            if (attuale == 0) {
                printf("Catalogo vuoto!\n");
            } else {
                Riordina(listaFilm, attuale);
            }
        } else {
            continua = false;
        }
    }

    Salva(filename, listaFilm, attuale);
    for (int i = 0; i < attuale; i++) {
        free(listaFilm[i]);
    }
    free(listaFilm);


    printf("Arrivederci!\n");
    return 0;
}