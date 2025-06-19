# Libreria Monkey per Arduino

## Introduzione

Monkey è una libreria scritta in C++ per Arduino, pensata per semplificare l’apprendimento e l’uso della programmazione su questa piattaforma. Grazie ai comandi forniti dalla libreria, è possibile scrivere codice in uno stile molto simile al linguaggio naturale, riducendo al minimo l’utilizzo del linguaggio C, spesso considerato difficile da padroneggiare, soprattutto per chi è alle prime armi con la programmazione.

## Funzionalità

I comandi offerti da Monkey sono realizzati come macro e funzioni in C e possono essere facilmente integrati in qualsiasi programma C/C++, rendendo più rapida e semplice la scrittura del codice.  
Esempi:
- Controllare più pin contemporaneamente con una sola istruzione.
- Usare temporizzatori non bloccanti al posto del comando `delay()`.

## Struttura

La libreria include:
- Macro del preprocessore C.
- Una classe per la gestione dei temporizzatori.
- Una classe per la gestione di pulsanti e interruttori.
- Funzioni per inizializzare e configurare i pin Arduino.

## Avvertenza

Questa libreria è stata sviluppata con finalità didattiche. L'autore declina ogni responsabilità per un suo utilizzo in contesti critici.  
**Se decidete di usarla per controllare un reattore nucleare, lo fate a vostro rischio e pericolo.**

## Installazione

1. Crea una directory chiamata `monkey` dentro `Arduino/libraries`.
2. Copia al suo interno i file: `monkey.h`, `monkey.cpp`, `keywords.txt`, `COPYING.LESSER`.
3. Apri l'IDE di Arduino e vai su **Sketch > #include libreria > Gestione librerie**.
4. Nella barra di ricerca digita `monkey`, seleziona la libreria e clicca su **Installa**.

## Documentazione

Consulta il wiki del progetto per l’elenco dei comandi disponibili e per esempi pratici.
