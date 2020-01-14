#include "autosaveddocument.h"

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QStandardPaths>


AutosavedDocument::AutosavedDocument()
{

}

AutosavedDocument::AutosavedDocument(QString path) : Document(path)
{
    QString fileName = QString(QCryptographicHash::hash(this->getPath().toLocal8Bit(),QCryptographicHash::Md5).toHex());
    QString fullPath = QStandardPaths::standardLocations(QStandardPaths::TempLocation).last() + "/" + fileName;

    QFile file(path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QTextStream in(&file);
       QString content;
       while(!in.atEnd())
       {
            content.append(in.readLine() + '\n');
       }

       this->setContent(content);
    }
}

void AutosavedDocument::setContent(QString content)
{
    Document::setContent(content);

    QString fileName = QString(QCryptographicHash::hash(this->getPath().toLocal8Bit(),QCryptographicHash::Md5).toHex());
    QString fullPath = QStandardPaths::standardLocations(QStandardPaths::TempLocation).last() + "/" + fileName;

    QFile file(this->getPath());
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << content;
    }
}
