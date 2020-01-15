#ifndef MARKDOWNPARSER_H
#define MARKDOWNPARSER_H

#include <QString>

class MarkdownParser
{
public:
    MarkdownParser();
    QString convertToHtml(QString input);

private:
    QString processRow(QString row, QString source, QString htmlElement);
    QString processIndividualWords(QString row);
};

#endif // MARKDOWNPARSER_H
