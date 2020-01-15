#include "markdownparser.h"
#include <QTextStream>
#include <QRegularExpression>

static const char* HEADER_1 = "#";
static const char* HEADER_2 = "##";
static const char* HEADER_3 = "###";

static const char* LIST_ITEM = "* ";

MarkdownParser::MarkdownParser()
{
}

QString MarkdownParser::convertToHtml(QString input){

    QString newText = QString("");
    QStringList rows = input.split(QRegExp("[\r\n]"));

    bool inList = false;
    QStringList::iterator i;
    for (i = rows.begin(); i != rows.end(); ++i){

        if(i->startsWith(LIST_ITEM)){
            if(!inList){
                newText.append("<ul>");
            }

            newText.append(processRow(i->toHtmlEscaped(), LIST_ITEM, "li"));
            inList = true;
        } else {
            if(inList){
                newText.append("</ul>");
                inList = false;
            }

            if(i->startsWith(HEADER_3)){
                newText.append(processRow(i->toHtmlEscaped(), HEADER_3, "h3"));
            }

            else if(i->startsWith(HEADER_2)){
                newText.append(processRow(i->toHtmlEscaped(), HEADER_2, "h2"));
            }

            else if(i->startsWith(HEADER_1)){
                newText.append(processRow(i->toHtmlEscaped(), HEADER_1, "h1"));
            }

            else {
                newText.append(processRow(i->toHtmlEscaped(), "", "p"));
            }

        }
    }

    return newText;
}

QString MarkdownParser::processRow(QString row, QString source, QString htmlElement){

    QString newText = QString("");
    newText.append("<" + htmlElement + ">");
    row.replace(source, "");
    newText.append(processIndividualWords(row));
    newText.append("</" + htmlElement + ">");

    return newText;
}

QString MarkdownParser::processIndividualWords(QString row)
{
    //Regexp for a Markdown link
    QRegularExpression link("\\[(.*)\\]\\((.*)\\)");
    QRegularExpressionMatchIterator j = link.globalMatch(row);

    while (j.hasNext()) {
        QRegularExpressionMatch match = j.next();
        QString all = match.captured(0);
        QString name = match.captured(1);
        QString link = match.captured(2);
        row.replace(all, " <a href=\"" + link + "\">" + name + "</a>");
    }


    //Regexp for a markdown preformatted inline
    QRegularExpression code("`([^`]*)`");
    QRegularExpressionMatchIterator i = code.globalMatch(row);

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString all = match.captured(0);
        QString minor = match.captured(1);
        row.replace(all, " <code>" + minor + "</code> ");
    }

    return row;
}
