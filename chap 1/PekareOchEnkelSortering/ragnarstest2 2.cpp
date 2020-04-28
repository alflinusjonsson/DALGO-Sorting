#include "ragnarstest2.h"
#include "student2reference.h"
#include <QThread>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;


bool okName2(){
    string name = nameOfTheStudent2();

    if (name=="Homer Simpson"){
        cout << "nameOfStudent2() returnerar inte DITT namn!" << endl;
        assert( false );
    }
    return true;
}


bool ragnarsTest2(){
    cout << endl << "Nu kör vi Ragnars test 2! Om du får assert failure har du en bug. " << endl << endl ;
    QThread::msleep(100);
    bool ok = okName2();
    return ok;
}
