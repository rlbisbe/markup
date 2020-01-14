#ifndef AUTOSAVEDDOCUMENT_H
#define AUTOSAVEDDOCUMENT_H

#include "document.h"

class AutosavedDocument : public Document
{
public:
    AutosavedDocument();
    AutosavedDocument(QString path);
    void setContent(QString content);
};

#endif // AUTOSAVEDDOCUMENT_H
