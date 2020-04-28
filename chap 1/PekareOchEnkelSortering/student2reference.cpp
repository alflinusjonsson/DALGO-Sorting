#include "student2reference.h"
#include <stdio.h>

const char* nameOfTheStudent2(){
    return "Linus Jönsson";  // Byt ut denna sträng mot ditt eget namn!
}




// ################ experiment med värde- pekar- och referensanrop #################



struct AnExampleStruct{
    int _intValue1;
    int _intValue2;
    float _array[1000];
};


// call by value, theStruct kommer att kopieras (även arrayen)
void printAddresses1(AnExampleStruct theStruct){
    printf("\n\n printAddress1\n");

    printf("&theStruct  = %lu\n",   (unsigned long) &theStruct);
    printf("&theStruct._intValue1  = %lu\n",  (unsigned long) &theStruct._intValue1);
    printf("&theStruct._intValue2  = %lu\n",  (unsigned long) &theStruct._intValue2);
    printf("&theStruct._array  = %lu\n",   (unsigned long) &theStruct._array);
}


// call by reference, theStruct är identisk med anroparens s.
void printAddresses2(const AnExampleStruct &theStruct){
    printf("\n\n printAddress2\n");

    printf("&theStruct  = %lu\n",  (unsigned long)&theStruct);
    printf("&theStruct._intValue1  = %lu\n",  (unsigned long)&theStruct._intValue1);
    printf("&theStruct._intValue2  = %lu\n",  (unsigned long)&theStruct._intValue2);
    printf("&theStruct._array  = %lu\n",  (unsigned long)&theStruct._array);
}


// call by pointer. Nu är (*pThestruct) identisk med anroparens s.
void printAddresses3(const AnExampleStruct *pTheStruct){
    printf("\n\n printAddress3\n");
    printf("pTheStruct  = %lu\n",  (unsigned long) pTheStruct);
    printf("&(*pTheStruct)._intValue1  = %lu\n",  (unsigned long) &(*pTheStruct)._intValue1);
    printf("&(*pTheStruct)._intValue2  = %lu\n",  (unsigned long) &(*pTheStruct)._intValue2);
    printf("&(*pTheStruct)._array  = %lu\n",   (unsigned long)&(*pTheStruct)._array);
}


// Experimentkoden är färdigskriven med betrakta utskrifterna!!
void experimentMedParameteroverforing(){

    printf("Experiment med parameteröverföring!\n");
    printf("(studera utskrifterna så att du kan förklara dem i nedanstående kommentar)\n");

    AnExampleStruct s;

    printAddresses1(s);
    printAddresses2(s);
    printAddresses3(&s);

    /* Förklaring:

    Första funktionen använder sig av call by value, vid anropet av funktionen stoppas argumenetens värden in i funktionen
    och deras värden kopieras till motsvarande parametrar.
    Call by value innebär alltså att argumentens värden kopieras till lokala kopior inne i funktionen, därav ändras
    här de ursprungliga värdena(dock endast i kopian).


    Andra använder sig av call by referens vilket betyder att funktionen använder samma minnesarea för värderna som skickas
    till funktionen som det som används inne i funktionen. Det ursprunliga värdena ändras ej.


    Tredje använder sig av call by pointer där utskriften blir identisk med anroparens s, dvs samma utskrift som
    printaddresses 2. *pTheStruct pekar alltså på s vilket gör att adressen till s skrivs ut eftersom "&" finns med.
    Det ursprunliga värdena ändras ej.

    */
}




void testingCode2(){

    printf("\n\n\n testingCode2  \n\n");

    experimentMedParameteroverforing();
}
