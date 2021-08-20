#include "data_management.h"



int main() 
    {
        vector<string> test;
        cout << "prova debug";
        test = leggi_file();
        test = sostituisci_una_riga(test, MARCATORE_CAP, "12347", "basgrazu");
        stampa_su_file(test, PERCORSO_FILE_CLIENTI);
        getchar();
        return 0;
    }