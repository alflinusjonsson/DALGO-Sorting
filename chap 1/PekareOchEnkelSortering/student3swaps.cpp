#include "student3swaps.h"
#include <stdio.h>


const char* nameOfTheStudent3(){
    return "Linus Jönsson";  // Byt ut denna sträng mot ditt eget namn!
}


// ################ Implementera swap med pekar- och referensanrop #################



// ANROP:   swap(a,b); eller swap( (&a), (&b) );
// UPPGIFT: Byter värden mellan a och b.
void swap(float* pa, float* pb){

    float temp = *pa;
    *pa = *pb;
    *pb = temp;
}

// ANROP:   swap(a,b); eller swap((a), (b));
// UPPGIFT: Byter värden mellan a och b.
void swap(float &a, float &b){

    float temp = a;
    a = b;
    b = temp;
}

void studentsTest3(){

  float a = 44;
  float b = 16;

  printf("Innan swap | A har vardet %.1lf och B vardet %.1lf\n", a,b);

  swap((a), (b));
  printf("Efter swap | A har vardet %.1lf och B vardet %.1lf\n", a,b);
}

void testingCode3(){

  printf("\n\n\n testingCode3  \n\n");

    studentsTest3();
}
