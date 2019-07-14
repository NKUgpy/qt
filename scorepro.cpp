#include "scorepro.h"

scorePro::scorePro(QObject *parent) : QObject(parent)
{

}

scorePro * scorePro::num=new scorePro;

scorePro * scorePro::getNum()
{
    return num;
}

void scorePro::changePtimer()
{
    emit beatNum();
}


