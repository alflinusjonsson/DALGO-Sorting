#include "ragnarstest1.h"
#include "student1.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <QThread>
#include <assert.h>

using namespace std;

float absolute(float x){
    return x<0 ? -x : x;
}

bool okName1(){
    string name = nameOfTheStudent1();

    if (name=="Homer Simpson"){
        cout << "nameOfStudent1() returnerar inte DITT namn!" << endl;
        assert(false);
    }
    return true;
}



bool testIandP(){
    cout << "Testar I och P!" << endl;
    QThread::msleep(100);

    float arr[100];
    float mustRemain = 101112;
    arr[0] = arr[99] = mustRemain;

    float *pBegin = &arr[1];
    float *pEnd   = &arr[99];

    fillWithRandomI(pBegin, pEnd);
    assert(arr[0]==mustRemain && arr[99]==mustRemain);
    fillWithRandomP(pBegin, pEnd);
    assert(arr[0]==mustRemain && arr[99]==mustRemain);

    assert(minimumElementI(pBegin, pEnd) < maximumElementI(pBegin,pEnd));
    assert(averageElementI(pBegin,pEnd) != int(averageElementI(pBegin,pEnd)));

    assert(averageElementI(pBegin,pEnd) > minimumElementI(pBegin,pEnd));
    assert(averageElementI(pBegin,pEnd) < maximumElementI(pBegin,pEnd));

    assert( minimumElementI(pBegin, pEnd) == minimumElementP(pBegin, pEnd) );
    assert( maximumElementI(pBegin, pEnd) == maximumElementP(pBegin, pEnd) );
    assert( absolute(averageElementI(pBegin,pEnd) - averageElementP(pBegin,pEnd)) < 0.001 );

    float newMin = minimumElementI(pBegin, pEnd) - 0.5;
    float newMax = maximumElementI(pBegin, pEnd) + 0.5;

    arr[10] = newMin;
    arr[20] = newMax;

    assert( minimumElementI(pBegin,pEnd) == newMin );
    assert( minimumElementP(pBegin,pEnd) == newMin );
    assert( maximumElementI(pBegin,pEnd) == newMax );
    assert( maximumElementP(pBegin,pEnd) == newMax );

    for (float* p=pBegin ; p!=pEnd; p+=1){
        assert( containedInArrayI(*p, pBegin, pEnd) );
        assert( containedInArrayP(*p, pBegin, pEnd) );
    }

    assert( !containedInArrayI(newMin-1, pBegin,pEnd) );
    assert( !containedInArrayP(newMin-1, pBegin,pEnd) );

    *pBegin = *(pEnd-1);
    assert( numberOfValuesEqualToI(*pBegin, pBegin,pEnd) >=2 );
    assert( numberOfValuesEqualToP(*pBegin, pBegin,pEnd) >=2 );



    fillWithRandomSortedI(pBegin, pEnd);
    assert(arr[0]==mustRemain && arr[99]==mustRemain);
    for (float* p=pBegin+1 ; p!=pEnd; p+=1)
        assert( *p>=*(p-1));
    fillWithRandomSortedP(pBegin, pEnd);
    assert(arr[0]==mustRemain && arr[99]==mustRemain);
    for (float* p=pBegin+1 ; p!=pEnd; p+=1)
        assert( *p>=*(p-1));

    return true;
}


bool ragnarsTest1(){

   cout << endl << "Nu kör vi Ragnars test 1! Om du får assert failure har du en bug. " << endl << endl ;
   QThread::msleep(100);
   bool ok = okName1()
           && testIandP();


   if (!ok)
       cout << endl << "Ragnars test MISSLYCKADES! \7" << endl;
   else cout << endl << "Grattis, Ragnars test 1 lyckades! " << endl << endl;
   return ok;
}
