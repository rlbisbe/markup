#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "markdownparser.h"
#include "document.h"

#include <QFileDialog>
#include <QTextStream>
#include <QSettings>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));

    connect(ui->actionSave_file, SIGNAL(triggered()), this, SLOT(saveFile()));

    connect(ui->editor, SIGNAL(textChanged()), this, SLOT(refreshRenderer()));

    QCoreApplication::setOrganizationName("Rlbisbe");
    QCoreApplication::setOrganizationDomain("rlbisbe.net");
    QCoreApplication::setApplicationName("MarkUp");
}

void MainWindow::reloadBuffer(){

    QSettings settings;
    if(settings.contains("currentFile")){
        openFile(settings.value("currentFile").toString());
    }
}

void MainWindow::newFile(){

    QSettings settings;
    settings.remove("currentFile");

    this->m_document = new Document();
    ui->editor->setPlainText(m_document->getContent());
}

void MainWindow::openFile(){

    //Get the new file name
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), nullptr, tr("Text files (*.md)"));

    openFile(fileName);
}

void MainWindow::openFile(QString fileName){

    this->m_document = new Document(fileName);

    if(m_document->getContent() != nullptr){
        ui->editor->setPlainText(m_document->getContent());

        QSettings settings;
        settings.setValue("currentFile", fileName);
        this->updateWindowTitle();
    }
}

void MainWindow::refreshRenderer(){
    m_document->setContent(ui->editor->toPlainText());
    QString htmlContent = MarkdownParser().convertToHtml(m_document->getContent());
    ui->preview->setText(htmlContent);
    this->updateWindowTitle();
}

void MainWindow::saveFile(){

    if(this->m_document->getPath() == nullptr){
        this->m_document->setPath(QFileDialog::getSaveFileName(this,
            tr("Save File"), nullptr, tr("Text files (*.md)")));
    }

    this->m_document->save();
    this->updateWindowTitle();
}

void MainWindow::updateWindowTitle(){
    setWindowTitle(this->m_document->getPathWithChanges() +" - " + "MarkUp text editor");
}

MainWindow::~MainWindow()
{
    delete ui;
}

