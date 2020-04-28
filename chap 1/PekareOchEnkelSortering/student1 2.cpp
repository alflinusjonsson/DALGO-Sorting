#include "student1.h"
#include <stdio.h> // printf
#include <assert.h>
#include "ragnarstest1.h"


// Läs Detta!

// Pekaruppdragen går ut på att implementera nedastående funktioner
// Många funktioner skall implementeras på två olika sätt (I och P):
// Version I: Räkna ut size och använd arraynotation med hakparanteser och heltalsindex.
// Version P: Använd istället pekarnotation, dvs  *p,  p+=1,  etc.



// ************************************************************
// ANROP:   char* namn = nameOfStudent1();
// UPPGIFT: Returnerar ditt namn!
// ************************************************************
const char* nameOfTheStudent1(){
    return "Linus Jönsson";  // Byt ut denna sträng mot ditt eget namn!
}




// ################ version I, löses med [ ]  och indexnotation #############



// ************************************************************
// ANROP:   float value = minimumElement(&arr[0], &arr[size]);
// UPPGIFT: Returnerar arrayens minsta värde
// ************************************************************

float minimumElementI(const float *pBegin, const float *pEnd){

    // Jag låter min egen lösning ligga kvar.
    // Förstå denna! Lös de andra uppgifterna själv.

    assert( pBegin < pEnd );

    int size = pEnd - pBegin;
    float extreme = pBegin[0];
    for (int i=0; i<size ; i+=1)
        if (pBegin[i]<extreme)
            extreme = pBegin[i];
    return extreme;
}

// ************************************************************
// ANROP:   float value = maximumElement( &arr[0], &arr[size] );
// UPPGIFT: Returnerar arrayens största värde
// ************************************************************

float maximumElementI(const float *pBegin, const float *pEnd){

    assert( pBegin < pEnd );

    int size = pEnd - pBegin;
    float extreme = pBegin[0];
    for (int i=0; i<size; i+=1)
        if (pBegin[i] > extreme)
            extreme = pBegin[i];
     return extreme;
}

// ************************************************************
// ANROP:   float value = averageElement( &arr[0], &arr[size] );
// UPPGIFT: Returnerar arrayens medelvärde
// ************************************************************

float averageElementI(const float *pBegin, const float *pEnd){

      assert( pBegin < pEnd );

      int size = pEnd - pBegin;
      float sum = 0.0;

      for (int i = 0; i < size; i+=1)
      {
          sum = sum + pBegin[i];
      }

      return sum / size;
}

// ************************************************************
// ANROP:   fillWithRandomI( &arr[0], &arr[size] );
// UPPGIFT: Fyller arrayen med oberoende slumpdata
// ************************************************************
void fillWithRandomI(float *pBegin, float *pEnd){

    const int size = pEnd - pBegin;

    for (int i=0; i<size; i+=1)
    {
      pBegin[i] = rand();
    }

}

// ************************************************************
// ANROP:   fillWithRandomI( &arr[0], &arr[size] );
// UPPGIFT: Fyller arrayen med sorterat slumpdata. Minst först
// ************************************************************
void fillWithRandomSortedI(float *pBegin, float *pEnd) {

    int size = pEnd - pBegin;
    pBegin[0] = (rand() % 10);
    for (int i=1; i<size; i+=1)
    {
        pBegin[i] = pBegin[i-1] + (rand() % 10);
    }

}

// ************************************************************
// ANROP:   bool contains = containedInArrayI(value,  &arr[0], &arr[size] );
// UPPGIFT: Returnerar true om arrayen innehåller angivet värde
// ************************************************************

bool  containedInArrayI(float value, const float *pBegin, const float *pEnd){

    assert( pBegin < pEnd );
    int size = pEnd - pBegin;

    for (int i = 0; i < size; i+=1)
      {
        if (pBegin[i] == value)
            return true;
      }

    return false;
}

// ************************************************************
// ANROP:   int number = numberOfValuesEqualToI(value,  &arr[0], &arr[size] );
// UPPGIFT: Returnerar antalet värden som är lika med angivet värde
// ************************************************************

int numberOfValuesEqualToI(float value, const float *pBegin, const float *pEnd){

    assert( pBegin < pEnd );

    int size = pEnd - pBegin, sum = 0;


    for (int i = 0; i < size; i+=1)
        if (pBegin[i] == value)
            sum++;

     return sum;
}




// ################ version P, samma uppgifter löses nu med pekarnotation  ###############






float minimumElementP(const float *pBegin, const float *pEnd){
    // Jag låter min egen lösning ligga kvar.
    // Förstå denna! Lös de andra uppgifterna själv.

    assert( pBegin < pEnd );
    float extreme = *pBegin;
    for (const float *p=pBegin ; p<pEnd; p+=1)
        if (*p<extreme)
            extreme = *p;

    return extreme;
}


float maximumElementP(const float *pBegin, const float *pEnd){

    assert( pBegin < pEnd );

    float extreme = *pBegin;
    for (const float *p=pBegin ; p<pEnd; p+=1)
        if (*p>extreme)
            extreme = *p;

    return extreme;

}

float averageElementP(const float *pBegin, const float *pEnd){

    assert( pBegin < pEnd );

    int size = pEnd - pBegin;
    float sum = 0.0;

    for (const float *p=pBegin; p < pEnd; p+=1)
        sum = sum + *p;

    return sum / size;


}

void fillWithRandomP(float *pBegin, float *pEnd){


    for (float *p=pBegin; p<pEnd; p+=1)
    {
        *p = (rand() % 10);
    }

}

void fillWithRandomSortedP(float *pBegin, float *pEnd){

    pBegin[0] = (rand() % 10);
    for (float *p=pBegin; p<pEnd; p+=1)
    {
       *p = *(p-1) + (rand() % 10);
    }


}

bool containedInArrayP(float value, const float *pBegin, const float *pEnd){

    assert( pBegin < pEnd );
    int size = pEnd - pBegin;

    for (const float *p=pBegin; p<pEnd; p+=1)
        if (*p == value)
            return true;


    return false;

}


int  numberOfValuesEqualToP(float value, const float *pBegin, const float *pEnd){

    assert( pBegin < pEnd );

    int size = pEnd - pBegin, sum = 0;

    for (const float *p=pBegin; p<pEnd; p+=1)
        if (*p == value)
            sum++;

     return sum;



}




// ################ Skriv din egen testkod här! #################


void studentsTest1(){

    printf("(dina egna tester borde komma har!)\n\n");

    float arr[10] = {10,5,3,12,5,5,8,7,4,9};

    printf("Array: {10,5,3,12,5,5,8,7,4,9}\n\n");

    printf("I | Minsta elementet ar = %.1lf \n", minimumElementI(&arr[0], &arr[10]) );

    printf("I | Storsta elementet ar = %.1lf \n", maximumElementI(&arr[0], &arr[10]) );

    printf("I | Medelvardet av arrayn ar = %.1lf \n", averageElementI(&arr[0], &arr[10]) );

    printf("P | Minsta elementet ar = %.1lf \n", minimumElementP(&arr[0], &arr[10]) );

    printf("P | Storsta elementet ar = %.1lf \n", maximumElementP(&arr[0], &arr[10]) );

    printf("P | Medelvardet av arrayn ar = %.1lf \n", averageElementP(&arr[0], &arr[10]) );





}




void testingCode1(){

   printf("\n\n\n testingCode1  \n\n");

   studentsTest1();


}

