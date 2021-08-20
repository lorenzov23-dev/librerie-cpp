#include "data_management.h"



int main() 
    {
        vector<string> test;
        cout << "prova debug";
        test = leggi_file();
        test = sostituisci_una_riga(test, MARCATORE_NOME, "Mario121", "basgrazu");
        stampa_su_file(test, PERCORSO_FILE_CLIENTI);
        getchar();
        return 0;
    }