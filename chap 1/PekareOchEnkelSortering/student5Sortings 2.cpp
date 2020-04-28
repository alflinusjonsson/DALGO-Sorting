#include "student5Sortings.h"
#include "student1.h"
#include "student3swaps.h"

#include "ragnarstest5.h"
#include <stdio.h> // printf


// Läs detta.
// Nedan finns version I och P av bubble- respektive insert-sort.

// Själv har jag implementerat I-versionerna.
// Det som återstår är P-versionerna!



// ************************************************************
// ANROP:   char* namn = nameOfStudent5();
// UPPGIFT: Returnerar ditt namn!
// ************************************************************
const char* nameOfTheStudent5(){
    return "Linus Jönsson";  // Byt ut denna sträng mot ditt eget namn!
}



/**********************************************************************************
 * ANROP:   bubbleSortI( pBegin, pEnd);
 * UPPGIFT: pBegin och pEnd definierar en array av element (pBegin pekar på det
 *          första elementet och pEnd EFTER det sista).
 *          Funktionen sorterar arrayen så att det minsta elementet hamnar först.
 *
 *          Algoritmen som används måste vara den version av bubbleSort som
 *          beskrivs i uppdragshäftet!!
 * ********************************************************************************/
void bubbleSortI(float *pBegin, float *pEnd){
    int size = pEnd - pBegin;

    for (int maxIndex = size-1 ; maxIndex>0 ; maxIndex -= 1)
        for (int i=0 ; i<maxIndex ; i+=1)
            if (pBegin[i]>pBegin[i+1])
                swap( (pBegin[i]), (pBegin[i+1]));
}


/**********************************************************************************
 * ANROP:   insertSortI( pBegin, pEnd);
 * UPPGIFT: pBegin och pEnd definierar en array av element (pBegin pekar på det
 *          första elementet och pEnd EFTER det sista).
 *          Funktionen sorterar arrayen så att det minsta elementet hamnar först.
 *
 *          Algoritmen som används måste vara den version av insertSort som
 *          beskrivs i uppdragshäftet!!
 * ********************************************************************************/
void insertSortI(float *pBegin, float *pEnd){

    int size = pEnd - (pBegin);

    for (int i = 1; i < size; i+=1)
    {
        float x = pBegin[i];
        int j = i-1;
        for ( ; j >=0 && pBegin[j] > x; j-=1)
              pBegin[j+1] = pBegin[j];
              pBegin[j+1] = x;
    }
}

void bubbleSortP(float *pBegin, float *pEnd){

    for (float *ptrMax = (pEnd-1) ; ptrMax>pBegin ; ptrMax-=1)
        for (float *ptr=pBegin; ptr<ptrMax; ptr+=1)
            if (*ptr>*(ptr+1))
                swap(*(ptr), *(ptr+1));
}


void insertSortP(float *pBegin, float *pEnd){

    for (float *pLastInOrder=pBegin; pLastInOrder<pEnd-1 ; pLastInOrder+=1){
        float x = *(pLastInOrder+1);
        float *p = pLastInOrder;
        for ( ; p>=pBegin && *p>x ; p-=1)
            *(p+1) = *p;
        *(p+1) = x;

    }
}

void studentsTest5(){

    // testa själv bubble- och insert- sort här!

    printf("dina egna tester borde komma har!\n");

    float arr[10] = {41,2,5,13,19,33,28,4,9,17};



}

void testingCode5(){

    printf("\n\n\n testingCode5  \n\n");

    studentsTest5();

}
