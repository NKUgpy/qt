#include "score.h"

score::score(QObject *parent) : QObject(parent)
{

}

score *score::scor=new score;

score * score::getInstance()
{
    return scor;
}

void score::addScore()
{
    emit beatMouse();
}
