Gestore Catalogo Film
Programma in C per la gestione di un catalogo di film con funzionalità di aggiunta, visualizzazione, ricerca e ordinamento.
Descrizione
Il programma permette di gestire una collezione di film attraverso un'interfaccia a menu interattiva. I dati vengono salvati automaticamente in un file binario all'uscita del programma.
Funzionalità principali

Aggiungi film: Inserimento di nuovi film con titolo, regista, anno di uscita e durata
Visualizza catalogo: Mostra tutti i film presenti nel catalogo
Ricerca per titolo: Trova un film specifico cercando per titolo
Riordina libreria: Ordina i film per durata (dal più corto al più lungo) usando l'algoritmo Bubble Sort
Salvataggio automatico: I dati vengono salvati in formato binario nel file catalogo.txt alla chiusura

Struttura dati
Ogni film è rappresentato da una struct contenente:

titolo (stringa, max 100 caratteri)
regista (stringa, max 100 caratteri)
annoUscita (intero)
durata (float, espressa in ore)

Istruzioni di compilazione
Con GCC (Linux/Mac/Windows con MinGW)
