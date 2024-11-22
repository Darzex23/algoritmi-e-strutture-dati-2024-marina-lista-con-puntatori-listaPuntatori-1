#include <iostream>
#include "ListaPuntatori.h"  // Assumendo che tu abbia messo la classe in un file separato

int main() {
    // Crea una lista
    ListaPuntatori<int> lista;

    // Chiedi all'utente quanti elementi vuole inserire
    int n;
    std::cout << "Quanti elementi vuoi inserire nella lista? ";
    std::cin >> n;

    // Chiedi di inserire gli elementi
    for (int i = 1; i <= n; ++i) {
        int valore;
        std::cout << "Inserisci il valore per l'elemento " << i << ": ";
        std::cin >> valore;
        lista.inslista(valore, i);  // Inserisce l'elemento in posizione i
    }

    // Mostra la lunghezza 
    std::cout << "Lunghezza della lista: " << lista.lunghezza() << std::endl;
    
        // Stampa tutti gli elementi della lista
    std::cout << "Gli elementi della lista sono: ";
    for (int i = 1; i <= lista.lunghezza(); ++i) {
        std::cout << lista.getElemento(i) << " ";  
    }
    std::cout << std::endl;


    // Controlla se è presente nella lista
    int valore_da_controllare;
    std::cout << "Inserisci il valore da cercare nella lista: ";
    std::cin >> valore_da_controllare;
    if (lista.contiene(valore_da_controllare)) {
        std::cout << "La lista contiene il valore " << valore_da_controllare << "." << std::endl;
    } else {
        std::cout << "La lista non contiene il valore " << valore_da_controllare << "." << std::endl;
    }

    // Conta le occorrenze di un valore
    int occorrenze;
    std::cout << "Inserisci il valore di cui vuoi contare le occorrenze: ";
    std::cin >> occorrenze;
    int occorrenze_nel_lista = lista.contaOccorrenze(occorrenze);
    std::cout << "Il valore " << occorrenze << " appare " << occorrenze_nel_lista << " volta/e nella lista." << std::endl;

    // Trova il massimo e il minimo nella lista
    std::cout << "Il valore massimo nella lista è: " << lista.massimo() << std::endl;
    std::cout << "Il valore minimo nella lista è: " << lista.minimo() << std::endl;

    // Calcola la somma di tutti gli elementi nella lista
    std::cout << "La somma di tutti gli elementi nella lista è: " << lista.somma() << std::endl;

    // Richiedi aggiornamento di un elemento
    int posizione_aggiornare, nuovo_valore;
    std::cout << "Vuoi aggiornare un elemento? (1 per sì, 0 per no): ";
    int scelta;
    std::cin >> scelta;

    if (scelta == 1) {
        std::cout << "Inserisci la posizione dell'elemento da aggiornare (1-based): ";
        std::cin >> posizione_aggiornare;
        if (posizione_aggiornare > 0 && posizione_aggiornare <= lista.lunghezza()) {
            std::cout << "Inserisci il nuovo valore: ";
            std::cin >> nuovo_valore;
            lista.aggiornaElemento(posizione_aggiornare, nuovo_valore);  // Aggiorna l'elemento
            std::cout << "Elemento aggiornato." << std::endl;
        } else {
            std::cout << "Posizione non valida." << std::endl;
        }
    }

    // Richiedi rimozione di un elemento per posizione
    int posizione_rimuovere;
    std::cout << "Vuoi rimuovere un elemento per posizione? (1 per sì, 0 per no): ";
    std::cin >> scelta;

    if (scelta == 1) {
        std::cout << "Inserisci la posizione dell'elemento da rimuovere (1-based): ";
        std::cin >> posizione_rimuovere;
        if (posizione_rimuovere > 0 && posizione_rimuovere <= lista.lunghezza()) {
            lista.rimuoviElemento(posizione_rimuovere);  // Rimuove l'elemento alla posizione
            std::cout << "Elemento rimosso." << std::endl;
        } else {
            std::cout << "Posizione non valida." << std::endl;
        }
    }

    // Richiedi rimozione di un elemento per valore
    int valore_rimuovere;
    std::cout << "Vuoi rimuovere un elemento per valore? (1 per sì, 0 per no): ";
    std::cin >> scelta;

    if (scelta == 1) {
        std::cout << "Inserisci il valore dell'elemento da rimuovere: ";
        std::cin >> valore_rimuovere;
        if (lista.rimuoviElementoPerValore(valore_rimuovere)) {  // Rimuove l'elemento per valore
            std::cout << "Elemento con valore " << valore_rimuovere << " rimosso." << std::endl;
        } else {
            std::cout << "Elemento con valore " << valore_rimuovere << " non trovato." << std::endl;
        }
    }

    // Stampa gli elementi dopo le operazioni
    std::cout << "Gli elementi della lista dopo le operazioni sono: ";
    for (int i = 1; i <= lista.lunghezza(); ++i) {
        std::cout << lista.getElemento(i) << " ";  
    }
    std::cout << std::endl;

    return 0;
}
