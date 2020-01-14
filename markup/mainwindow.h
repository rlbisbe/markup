#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include "document.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reloadBuffer();

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void refreshRenderer();
    void togglePreview();
    void updatePreview();

private:
    Ui::MainWindow *ui;
    Document *m_document;

    void openFile(QString filename);
    void updateWindowTitle();
    QSettings m_settings;
};
#endif // MAINWINDOW_H
