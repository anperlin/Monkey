# Monkey
Libreria Monkey per Arduino – Una Macro Library per facilitare l’apprendimento della programmazione

Monkey è una libreria scritta in C++ per Arduino, pensata per semplificare l’apprendimento e l’uso della programmazione su questa piattaforma. Grazie ai comandi forniti dalla libreria, è possibile scrivere codice in uno stile molto simile al linguaggio naturale, riducendo al minimo l’utilizzo del linguaggio C, spesso considerato difficile da padroneggiare, soprattutto per chi è alle prime armi con la programmazione.

I comandi offerti da Monkey sono realizzati come macro e funzioni in C e possono essere facilmente integrati in qualsiasi programma C/C++, rendendo più rapida e semplice la scrittura del codice. Ad esempio, è possibile controllare più pin contemporaneamente con una sola istruzione oppure usare temporizzatori non bloccanti per eseguire azioni periodiche, evitando l’uso del comando delay() che interrompe l’elaborazione.

La libreria è composta principalmente da macro del preprocessore C, una classe per la gestione dei temporizzatori, una per la gestione di pulsanti o interruttori, e alcune funzioni per inizializzare e configurare i pin della scheda Arduino.

Questa libreria è stata sviluppata con finalità didattiche e si declina ogni responsabilità per un suo utilizzo in contesti critici. Se decidete di usarla, ad esempio, per controllare il sistema di raffreddamento di un reattore nucleare… lo fate a vostro rischio e pericolo.


L’installazione è identica a quella di qualsiasi altra libreria Arduino:

Crea una directory chiamata monkey dentro la cartella Arduino\libraries.

Scarica e copia al suo interno i file: monkey.h, monkey.cpp, keywords.txt e COPYING.LESSER.

Apri l’ambiente di sviluppo Arduino, vai su Sketch > #include libreria > Gestione librerie.

Nella barra "Filtra la tua ricerca", digita monkey: la libreria dovrebbe comparire.

Selezionala e clicca sul pulsante in basso a destra per completare l’installazione.

Per l’elenco completo dei comandi e i relativi esempi di utilizzo, consulta il wiki del progetto.
