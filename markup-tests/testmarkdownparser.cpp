#include "testmarkdownparser.h"

#include <markdownparser.h>

void TestMarkdownParser::h1(){
    QString output = MarkdownParser().convertToHtml("#Hello");
    QCOMPARE(output, QString("<h1>Hello</h1>"));
}

void TestMarkdownParser::h2(){
    QString output = MarkdownParser().convertToHtml("##Hello");
    QCOMPARE(output, QString("<h2>Hello</h2>"));
}

void TestMarkdownParser::h3(){
    QString output = MarkdownParser().convertToHtml("###Hello");
    QCOMPARE(output, QString("<h3>Hello</h3>"));
}

void TestMarkdownParser::ul(){
    QString output = MarkdownParser().convertToHtml("* Hello\n");
    QCOMPARE(output, QString("<ul><li>Hello</li></ul><p></p>"));
}

void TestMarkdownParser::code(){
    QString output = MarkdownParser().convertToHtml("`tmux`");
    QCOMPARE(output, QString("<p><pre>tmux</pre></p>"));
}

