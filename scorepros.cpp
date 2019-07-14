#include "scorepros.h"

scorePros::scorePros(QObject *parent) : QObject(parent)
{

}

scorePros * scorePros::num1=new scorePros;

scorePros * scorePros::getNum1()
{
    return num1;
}

void scorePros::changePtimer1()
{
    emit beatNum1();
}
