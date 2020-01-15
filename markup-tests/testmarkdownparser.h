#ifndef MARKDOWNPARSERTESTS_H
#define MARKDOWNPARSERTESTS_H

#include <QtTest/QtTest>

class TestMarkdownParser : public QObject
{
    Q_OBJECT

private slots:
    void h1();
    void h2();
    void h3();
    void ul();
    void code();
};

#endif // MARKDOWNPARSERTESTS_H
