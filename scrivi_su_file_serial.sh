#!/bin/bash
#variabile contenente il percorso dove si trova il txt relativo ai clienti
percorso="test.txt"
i=1
echo -e "*Totale: 200\n\n\n" | tee -a $percorso
for (( i=1; i<201; i++ ))
do
    echo -e "\n\n\n--------------------------------\n\n\nCliente-id: "$i"\nNome: Mario"$i"\nCognome: Rossi"$i"\nCodice-Fiscale: mario"$i"\nIndirizzo: mario"$i"\nComune: iojiiojio"$i"\nProvincia: province"$i"\n\n\n---------------------------------------" | tee -a $percorso
done
