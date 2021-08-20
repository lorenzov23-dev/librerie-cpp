#include "data_management.h"


//definisco un metodo per scrivere le stringhe su char array, mi servirà per inserire i comandi nella funzione system
char* stringa_to_malloc(string da_inserire, char *p)
    {
        p = (char*) malloc(sizeof(char)*da_inserire.size());
        int i = 0;
        while(da_inserire[i]!='\n')
            {
                *(p+i) = da_inserire[i];
                i++;
            }
        return p;
    }

// creo una funzione apposita per usare le potenze
int power(int base, int exp) 
    {
        if (exp == 0)
            return 1;
        else if (exp % 2)
            return base * power(base, exp - 1);
        else 
            {
                int temp = power(base, exp / 2);
                return temp * temp;
            }
    }
//funzione che serve a separare la parte inutile al confronto da quella confrontabile durante la ricerca
string parser_scarta_inutile(string tutta)
    
    {
        int index = 0;
        index = tutta.find(":");
        tutta.erase(0, index+2);
        return tutta;
    }
/*
    ritorna l'indice che corrisponde al secondo parametro
*/

int dammi_indice(vector<string> v, string s)
    {
        auto it = find(v.begin(), v.end(), s);

        // If element was found
        if (it != v.end())
            {
                // calculating the index
                // of K
                int index = it - v.begin();
                return index;
            }
        else
            {
                // If the element is not
                // present in the vector
                return -1;
            }
    }
//uso la seguente funzione per convertire i valori numerici in formato stringa in interi. Serve ad aggiornare i totali del db clienti o delle fatture emesse.
int converti_num_string_to_int(string num)
    {
        int massima_lunghezza = 10;
        int finalizzato = 0;
        if(sizeof(num)>>massima_lunghezza)
            {
                cout << "Mi dispiace hai inserito una stringa sbagliata!" << endl;
                return -2;
            }
        //Inizio fase di parsing
        //nota bene i vale sempre 1 unità meno della grandezza dell'array altrimenti vado in index out of bound
        int i=num.size();
        while(i>0)
            {
                i--;
                switch (num[i])
                    {
                        case '0':
                            {
                                finalizzato = finalizzato +(0*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '1':
                            {
                                finalizzato = finalizzato +(1*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '2':
                            {
                                finalizzato = finalizzato +(2*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '3':
                            {
                                finalizzato = finalizzato +(3*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '4':
                            {
                                finalizzato = finalizzato +(4*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '5':
                            {
                                finalizzato = finalizzato +(5*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '6':
                            {
                                finalizzato = finalizzato +(6*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '7':
                            {
                                finalizzato = finalizzato +(7*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '8':
                            {
                                finalizzato = finalizzato +(8*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '9':
                            {
                                finalizzato = finalizzato +(9*power(10,(num.size()-(i+1))));
                                break;
                            }
                        case '\n':
                            {
                                break;
                            }
                        default:
                            {
                                cout << "Errore di parsing!" << endl;
                                cout.flush();
                                break;
                            }
                    }
            }
        return finalizzato;

    }


//creo una funzione che scrive un file da 0 partendo da un vector string
void scrivi_file(vector<string> v)
    {
        ofstream o;
        o.open(PERCORSO_FILE_CLIENTI, ios_base::out);
        int i = 0;
        while(i<v.size())
            {
                o << v[i] << endl;
                i++;
            }
        o.flush();
        o.clear();
        o.close();
    }

string ricomponi_stringa_parsata(string vecchia, string nuovo_valore)
    {
        int index = 0;
        index = vecchia.find(":");
        vecchia.erase(index+2, vecchia.length());
        vecchia.append(nuovo_valore);
        return vecchia;
    }
//funzione per sostituire il numero di clienti. In testa al file aggiorno il numero di clienti aumentandolo di 1 unità dopo l'inserimento
//preso in ingresso un vector string cerco la o le righe da sostituire
vector<string> sostituisci_una_riga(vector<string> g, string marcatore, string precedente, string nuovo)
    {
        
        //primmarcatore pmarcatorerte, si legge tutto il file in unmarcatore struttura array vector di stringhe
        bool trovata = false;
        bool esci = false;
        string utile;
        int i = 0;
        int j = 0;
        while ((i<g.size())&&(!esci))
            {
                //primo check, controllo la prima parte della riga
                j=0;
                if(g[i][j]==marcatore[j])
                    {
                        j++;
                        if(g[i][j]==marcatore[j])
                            {
                                j++;
                                if(g[i][j]==marcatore[j])
                                    {
                                        j++;
                                        if(g[i][j]==marcatore[j])
                                            {
                                                utile = parser_scarta_inutile(g[i]);
                                                //ho messo il valore da correggere nella stringa utile
                                                if(utile==precedente)
                                                    {
                                                        utile = nuovo;
                                                        g[i] = ricomponi_stringa_parsata(g[i], utile);
                                                        esci = true;
                                                    }
                                            }
                                    }
                            }
                    }
                i++;
            }
        return g;
    }

// Una semplice funzione che stampa a video tutto il contenuto di un vector
void stampa_vector(vector<string> da_stampare)
    {
        int i = 0;
        while(i<da_stampare.size())
            {
                cout << da_stampare[i]<<endl;
                i++;
            }
    }


//questa funzione prende in ingresso tutto un file letto in precedenza e stampa a video il record prescelto passato come parametro di ricerca
bool cerca_record(vector<string> l, string comparable, int offset_up, int offset_down, string iniziale)
    
    {
        vector<string> record;
        //variabile di scorrimento array contenente il file
        int i = 0;
        //variabile di scorrimento stringa da confrontare char by char
        int j = 0;
        bool trovato = true;
        int lunghezza_comparable = 0;
        lunghezza_comparable = comparable.size();
        string appoggio;
        /*
            Inizio a scorrere l'array appena caricato dal file per cercare la stringa corrispondente
            a comparable
        */
        while(i<l.size())
            {
                //resetto la variabile di scorrimento stringhe
                j=0;
                //resetto la variabile booleana di verosimiglianza
                trovato = true;
                /*
                    primo confronto. Una volta prelevata la riga devo verificare che i primi 4 char della riga in vector
                    siano uguali ai primi 4 char della riga iniziale facente riferimento al campo di ricerca (Nome, Cogn, Codi, ....)
                    ho trovato una linea che inizia allo stesso modo di quella selezionata
                */
                if(trovato&&l[i][j]==iniziale[j])
                    {
                        j++;
                        if(trovato&&l[i][j]==iniziale[j])
                            {
                                j++;
                                if(trovato&&l[i][j]==iniziale[j])
                                    {
                                        j++;
                                        if(trovato&&l[i][j]==iniziale[j])
                                            {
                                                //ho appena trovato una stringa nel file i cui primi 4 char corrispondono alla mia
                                                if(trovato)
                                                    {
                                                        //mi assicuro che la linea inserita dall'utente non sia più lunga di quella presente nel file
                                                        appoggio = parser_scarta_inutile(l[i]);
                                                        if(!(comparable.size()>appoggio.size()))
                                                            {
                                                                j=0;
                                                                //invece di scorrere tutta la stringa controllo un byte alla volta
                                                                for(j=0;j<comparable.size();j++)
                                                                    {
                                                                        trovato = trovato && appoggio[j]==comparable[j];
                                                                    }
                                                                if(trovato)
                                                                    {
                                                                        trovato=true;
                                                                        for(j=-offset_up; j<offset_down; j++)
                                                                            {
                                                                                record.push_back(l[i+j]);
                                                                            }
                                                                    }

                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                i++;
            }
        if(trovato)
            {
                stampa_vector(record);
                record.clear();
            }
        else
            {
                cout << "Il cliente non è presente in archivio!" <<endl;
            }
        return trovato;
    }




//ora con tutte le funzioni di supporto alla ricerca dentro un file txt e alla stampa dei risultati posso
// implementare la funzione cerca_cliente
// bool cerca_cliente()
//     {
//         char scelta = '0';
//         bool esci = false;
//         bool esistente = false;

//         string parametro, init;
//         vector<string> for_reading;
//         while(!esci)
//             {
//                 cout << "\tScegli uno dei parametri per la ricerca\nNome (1)\nCognome (2)\nCodicef (3)\nComune di residenza(4)\nCodice Cliente(5)"<<endl;
//                 try
//                     {
//                         cin >> scelta;
//                         cin.clear();
//                     }
//                 catch(const exception& e)
//                     {
//                         cerr << e.what() << '\n';
//                     }
//                 switch (scelta)
//                     {
//                         case '1':
//                             {
//                                 //Inserisco nella stringa init il marcatore (i primi caratteri) simile a quello del campo di ricerca
//                                 init="Nome";
//                                 cout<< "Per favore digitare il nome dell'utente selezionato"<<endl;
//                                 try
//                                     {
//                                         cin >> parametro;
//                                         cin.clear();
//                                     }
//                                 catch(const exception& e)
//                                     {
//                                         cerr << e.what() << '\n';
//                                     }
//                                 for_reading = leggi_file();
//                                 esistente = cerca_record(for_reading, parametro, 3, 7, init);
//                                 if(!esistente)
//                                     cout << "Attenzione l'utente cercato non esiste in archivio" <<endl;
//                                 esci=true;
//                                 break;
//                             }
//                         case '2':
//                             {
//                                 //Inserisco nella stringa init il marcatore (i primi caratteri) simile a quello del campo di ricerca
//                                 init="Cogn";
//                                 cout<< "Per favore digitare il cognome dell'utente selezionato"<<endl;
//                                 try
//                                     {
//                                         cin >> parametro;
//                                         cin.clear();
//                                     }
//                                 catch(const exception& e)
//                                     {
//                                         cerr << e.what() << '\n';
//                                     }
//                                 for_reading = leggi_file();
//                                 esistente = cerca_record(for_reading, parametro, 4, 6, init);
//                                 if(!esistente)
//                                     cout << "Attenzione l'utente cercato non esiste in archivio" <<endl;
//                                 esci=true;
//                                 break;
//                             }
//                         case '3':
//                             {
//                                 //Inserisco nella stringa init il marcatore (i primi caratteri) simile a quello del campo di ricerca
//                                 init="Codi";
//                                 cout<< "Per favore digitare il codice fiscale dell'utente selezionato"<<endl;
//                                 try
//                                     {
//                                         cin >> parametro;
//                                         cin.clear();
//                                     }
//                                 catch(const exception& e)
//                                     {
//                                         cerr << e.what() << '\n';
//                                     }
//                                 for_reading = leggi_file();
//                                 esistente = cerca_record(for_reading, parametro, 5, 5, init);
//                                 if(!esistente)
//                                     cout << "Attenzione l'utente cercato non esiste in archivio" <<endl;
//                                 esci=true;
//                                 break;
//                             }
//                         case '4':
//                             {
//                                 //Inserisco nella stringa init il marcatore (i primi caratteri) simile a quello del campo di ricerca
//                                 init="Comu";
//                                 cout<< "Per favore digitare il comune di residenza dell'utente selezionato"<<endl;
//                                 try
//                                     {
//                                         cin >> parametro;
//                                         cin.clear();
//                                     }
//                                 catch(const exception& e)
//                                     {
//                                         cerr << e.what() << '\n';
//                                     }
//                                 for_reading = leggi_file();
//                                 esistente = cerca_record(for_reading, parametro, 6, 4, init);
//                                 if(!esistente)
//                                     cout << "Attenzione l'utente cercato non esiste in archivio" <<endl;
//                                 esci=true;
//                                 break;
//                             }
//                         case '5':
//                             {
//                                 //Inserisco nella stringa init il marcatore (i primi caratteri) simile a quello del campo di ricerca
//                                 init="Clie";
//                                 cout<< "Per favore digitare il codice ID cliente di residenza dell'utente selezionato"<<endl;
//                                 try
//                                     {
//                                         cin >> parametro;
//                                         cin.clear();
//                                     }
//                                 catch(const exception& e)
//                                     {
//                                         cerr << e.what() << '\n';
//                                     }
//                                 for_reading = leggi_file();
//                                 esistente = cerca_record(for_reading, parametro, 2, 7, init);
//                                 if(!esistente)
//                                 cout << "Attenzione l'utente cercato non esiste in archivio" <<endl;
//                                 esci=true;
//                                 break;
//                             }
//                         default:

//                             {
//                                 cout << "Prova ancora l'inserimento, non lo hai fatto correttamente" << endl;
//                                 break;
//                             }
//                     }
//             }
//         return esistente;
//     }


void format_data(char *p, int size)
    {
        char buffer;
        int i = 0;
        for(i=0; i<size; i++)
            {
                buffer = *(p+i);
                if(buffer=='/')
                    {
                        *(p+i)='-';
                    }
            }
    }
//creo una funzione che legge un file dentro un array di stringhe e lo restituisce al chiamante
vector<string> leggi_file()
    {
        ifstream in (PERCORSO_FILE_CLIENTI);
        string buffer;
        vector<string> lettura;
        while (getline(in,buffer))
            {
                lettura.push_back(buffer);
            }
        in.clear();
        in.close();
        return lettura;
    }

void stampa_su_file(vector<string> a, string path)
    {
        size_t index = 0;
        int j = 0;
        ofstream o;
        o.open(path, ios_base::out);
        for (size_t i = 0; i < a.size(); ++i)
            {
                j = (int) i;
                o<< a[j] << endl;
            }
        o.flush();
        o.clear();
        o.close();
        return;
    }
