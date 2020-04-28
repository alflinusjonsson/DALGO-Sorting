#include "student4thoughtreading.h"
#include <stdio.h>



// ################ MAGI! Förklara hur tankeläsningen fungerar! #################

void tankPaEttTal(){
    int x = 108;
    printf( "Denna funktion tanker pa ett hemligt tal (%d)\n", x);
}

void tankelasning(){
    int  hemligheten;
    printf( "Denna funktion tror att den andra funktionens hemlighet ar %d!\n", hemligheten);
}

void experimentMedTankeoverforing(){
    printf("Experiment med tankeoverforing!\n");
    printf("(studera utskrifterna sa att du kan forklara dem i kommentaren)\n");
    tankPaEttTal();
    tankelasning();


    /*
       Förklaring:

       Använde debugging consolen för att få fram adressen till int x och int hemligheten.
       Visade sig att de ligger på samma adress, skulle de kunna ha något med heap och stack att göra?
       T.ex om ett värde läggs på stacken och inte tas bort så hämtar funktionen efter detta värdet.

    */
}




void testingCode4(){

    printf("\n\n\n testingCode4  \n\n");

    experimentMedTankeoverforing();

}

