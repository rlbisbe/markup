#include "testwordcounter.h"
#include <wordcounter.h>

void TestWordCounter::singleSentence(){
    int output = WordCounter().count("Hello world, these should be 7 words");
    QCOMPARE(output, 7);
}

void TestWordCounter::singleWord()
{
    int output = WordCounter().count("Hello");
    QCOMPARE(output, 1);
}

void TestWordCounter::multipleSpacesDontMakeAWord()
{
    int output = WordCounter().count("Only    three    words    ");
    QCOMPARE(output, 3);
}

