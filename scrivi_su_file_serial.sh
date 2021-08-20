#!/bin/bash
#variabile contenente il percorso dove si trova il txt relativo ai clienti
cod="codice-fiscale"
nom="nome"
cogn="cognome"
indi="indirizzo"
cap="CAP"
com="comune"
prov="provincia"
emai="email"

percorso="test.txt"
i=1
echo -e "*Totale: 200\n\n\n" | tee -a $percorso
for (( i=1; i<201; i++ ))
do
    echo -e "\n\n\n--------------------------------\n\n\n$cod: codi$i\n$nom: Mario$i\n$cogn: Rossi$i\n$indi: via del campo $i\n$cap: 1234$i\n$com: comun$i\n$prov: provincia$i\n$emai: email@email.$i\n\n\n---------------------------------------" | tee -a $percorso
done
