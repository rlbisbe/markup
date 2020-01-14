#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <QString>

class Document
{
public:
    Document();
    Document(QString path);

    void save();
    void setContent(QString content);
    void setPath(QString path);

    QString getPath();
    QString getPathWithChanges();
    QString getContent();
private:
    QString m_path;
    QString m_content;
    bool m_unsaved;
};


#endif // DOCUMENT_H
