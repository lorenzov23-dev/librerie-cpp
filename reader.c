#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define command "NETSTAT"
#define percorso_salvataggio "C:/Users/lorenzo.vannini/Documents/librerie-cpp/netstat.txt"
#define soglia1 0.30
#define soglia2 0.70
#define soglia3 0.90

const char *tipo_socket = "TCP";

const char *stato_socket = "TIME_WAIT";



int contain_substr(char *a)
  {
    int trovato = 0;
    char *found;

    found = strstr(a, tipo_socket); 
    if(found!=NULL)
      {
        printf("\n\nContiene %s", tipo_socket);
        trovato = 1;
      }
    else 
      {
        printf("\n\nNon contiene %s", tipo_socket);
        trovato = 0;
      }
    return trovato;

  }

  int contain_substr_stato_socket(char *a) 
    {
      int trovato = 0;
      char *found;

      found = strstr(a, stato_socket); 
      if(found!=NULL)
        {
          printf("\n\nContiene %s", stato_socket);
          trovato = 1;
        }
      else 
        {
          printf("\n\nNon contiene %s", stato_socket);
          trovato = 0;
        }
      return trovato;
    }



float trova_percentuale_in_time_wait(FILE *file, int contatore)
  {
    float percentuale = 0.00;
    float numero_socket_bloccati = 0;
    char *p;
    char path[1035];
    p = path;
    if(file==NULL)
      {
        exit(1);
      }
    while (fgets(path, sizeof(path), file) != NULL)
        {
          if(contain_substr_stato_socket(p)==1)
            {
              numero_socket_bloccati++;
            }
        }

    percentuale = numero_socket_bloccati/contatore;

    return percentuale;
  }

int main(int argc, char *argv[])
  {
    FILE *fp,*fp2;
    char *p;
    char path[1035];
    p = path;
    int contalinee = 0;
    float percentuale = 0;
    while(1)
    {
      fp2 = fopen(percorso_salvataggio, "w+");
      if (fp2 == NULL)
        {
          printf("Failed to run command\n");
          exit(1);
        }
      /* Open the command for reading. */
      fp = popen("NETSTAT", "r");
      if (fp == NULL)
        {
          printf("Failed to run command\n", 0);
          exit(1);
        }
      sleep(5);
      /* Read the output a line at a time - output it. */
      while (fgets(path, sizeof(path), fp) != NULL)
        {
          if(contain_substr(p)==1)
            {
              contalinee++;
              fprintf(fp2, p);
            }
        }
      printf("\n\n ------------------ File letto correttamente ---------------- \n\n");
      percentuale = trova_percentuale_in_time_wait(fp2, contalinee);
      printf("\n ------------------ Percentuale di socket in time wait = %f ----------------", &percentuale);
      /* close */

      pclose(fp);
      pclose(fp2);
    }
    return 0;
  }