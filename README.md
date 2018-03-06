# Monkey
Arduino Macro Library  in order to facilitate the learning of Arduino programmation

Monkey è una libreria C++ per Arduino, nata con l’intento di facilitare la programmazione di Arduino, grazie ai comandi presenti nella libreria che combinati tra loro consentono di programmare Arduino con un linguaggio molto vicino a quello naturale, limitando al massimo l’uso del C, spesso molto ostico da imparare, specie per chi non ha dimestichezza con la programmazione. 

I comandi presenti in Monkey essendo macro e funzioni in C, possono comunque essere usati all’interno dei normali programmi in C/C++ agevolando la programmazione di Arduino, sostituendo ripetitivi blocchi di codice come ad esempio quando occorre impostare o cambiare stato logico a più pins, che monkey permette di fare con una singola istruzione, oppure usare dei temporizzatori per compiere particolari azioni che non interrompano l’elaborazione come il comando delay.

La libreria scritta in C++ si compone prevalentemente di macro del preprocessore C, una classe che serve per gestire dei temporizzatori, una per gestire i pulsanti o interruttori ed alcune funzioni per inizializzare ed impostare i pins della scheda Arduino. 

Si declina ogni responsabilità sull'uso della presente libreria, nata con intento didattico e quindi adatta all'uso in questo ambito. Se poi volte usarla per controllare il sistema di raffreddamento di un reattore nucleare, lo fate a vostro rischio e pericolo.

INSTALLAZIONE:
si installa come una qualsiasi libreria di arduino, 
 1) crea una directory chiamata monkey dentro Arduino\libreries 
 2) scarica e copia  i file monkey.h e monkey.cpp dentro la directory monkey 
 3) dall'ambiete di sviluppo di arduino : vai sul menu Sketch poi #include libreria e gestione libreria. 
 4) inserire nella finestra "filtra la tua ricerca" la parola monkey, dovrebeb apaprire la libreria appena copiata, selezionarla e cliccare sul pulsnate in basso a destra. 
 
 Per l'elenco dei comandi e il loro uso ed esempi guardare nel wiki. 
 grazie 


