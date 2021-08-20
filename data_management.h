#include <stdio.h>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <map>
#include <cassert>
#include <iterator>


using namespace std;
// namespace std;


#define PERCORSO_FILE_CLIENTI "test.txt"
#define PERCORSO_FILE_ABBONAMENTI "percorso"
#define MARCATORE_DI_CONFRONTO "marcatore: batistuta"
#define MARCATORE_NOME "Nome"
#define MARCATORE_COGNOME "Cogn"
#define MARCATORE_CODICEF "Codi"


//definisco un metodo per scrivere le stringhe su char array, mi servirà per inserire i comandi nella funzione system
char* stringa_to_malloc(string da_inserire, char *p);

// creo una funzione apposita per usare le potenze
int power(int base, int exp);

//funzione che serve a separare la parte inutile al confronto da quella confrontabile durante la ricerca
string parser_scarta_inutile(string tutta);

//ritorna l'indice che corrisponde al secondo parametro
int dammi_indice(vector<string> v, string s);


//uso la seguente funzione per convertire i valori numerici in formato stringa in interi. Serve ad aggiornare i totali del db clienti o delle fatture emesse.
int converti_num_string_to_int(string num);

//creo una funzione che scrive un file da 0 partendo da un vector string
void scrivi_file(vector<string> v);

//creo una funzione che legge un file dentro un array di stringhe e lo restituisce al chiamante
map<string, string> leggi_file();

//funzione per sostituire il numero di clienti. In testa al file aggiorno il numero di clienti aumentandolo di 1 unità dopo l'inserimento
bool sostituisci_una_riga(string n);

// Una semplice funzione che stampa a video tutto il contenuto di un vector
void stampa_vector(vector<string> da_stampare);

//questa funzione prende in ingresso tutto un file letto in precedenza e stampa a video il record prescelto passato come parametro di ricerca
bool cerca_record(vector<string> l, string comparable, int offset_up, int offset_down, string iniziale);

// ora con tutte le funzioni di supporto alla ricerca dentro un file txt e alla stampa dei risultati posso implementare la funzione cerca_cliente
bool cerca_cliente();

void format_data(char *p, int size);













