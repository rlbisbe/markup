#include <QtTest/QtTest>
#include "testmarkdownparser.h"
#include "testwordcounter.h"

int main(int argc, char *argv[])
{
    QTest::qExec(new TestMarkdownParser, argc, argv);
    QTest::qExec(new TestWordCounter, argc, argv);

    return 0;
}
