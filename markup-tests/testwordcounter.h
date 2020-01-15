#ifndef TESTWORDCOUNTER_H
#define TESTWORDCOUNTER_H

#include <QtTest/QtTest>


class TestWordCounter  : public QObject
{
    Q_OBJECT

private slots:
    void singleSentence();
    void singleWord();
    void multipleSpacesDontMakeAWord();
};

#endif // TESTWORDCOUNTER_H
