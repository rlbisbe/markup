#include "wordcounter.h"

#include <QRegularExpression>
#include <QString>

int WordCounter::count(QString text)
{
    //We define words by the number of spaces.
    return text.split(QRegularExpression(" "), QString::SplitBehavior::SkipEmptyParts).size();
}
