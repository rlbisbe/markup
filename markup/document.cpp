#include "document.h"

#include <QFile>
#include <QTextStream>

Document::Document()
{
    //Do Nothing
}

Document::Document(QString path)
{
    this->m_path = path;
    // Load document from path and into content;

    QFile file(path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QTextStream in(&file);
       while(!in.atEnd())
       {
            m_content.append(in.readLine() + '\n');
       }
    }
}

QString Document::getPath()
{
    return m_path;
}

QString Document::getPathWithChanges(){
    if(this->m_unsaved){
        return m_path + "*";
    }
    return m_path;
}

QString Document::getContent()
{
    return m_content;
}

void Document::setContent(QString content)
{
    m_content = content;
    m_unsaved = true;
}

void Document::setPath(QString path)
{
    m_path = path;
}

void Document::save()
{
    if(m_path == nullptr)
    {
        throw "Null file name";
    }

    QFile file(m_path);
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << m_content;
        m_unsaved = false;
    }
}
