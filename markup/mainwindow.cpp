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
    connect(ui->actionToggle_preview, SIGNAL(triggered()), this, SLOT(togglePreview()));

    connect(ui->editor, SIGNAL(textChanged()), this, SLOT(refreshRenderer()));

    QCoreApplication::setOrganizationName("Rlbisbe");
    QCoreApplication::setOrganizationDomain("rlbisbe.net");
    QCoreApplication::setApplicationName("MarkUp");

    this->updatePreview();
}

void MainWindow::reloadBuffer(){

    if(m_settings.contains("currentFile")){
        openFile(m_settings.value("currentFile").toString());
    }
}

void MainWindow::newFile(){

    m_settings.remove("currentFile");

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

        m_settings.setValue("currentFile", fileName);
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

void MainWindow::togglePreview(){
    m_settings.setValue("previewEnabled", !m_settings.value("previewEnabled", false).toBool());
    this->updatePreview();
}

void MainWindow::updatePreview(){
    bool previewEnabled = m_settings.value("previewEnabled", false).toBool();
    ui->preview->setVisible(previewEnabled);
}

void MainWindow::updateWindowTitle(){
    setWindowTitle(this->m_document->getPathWithChanges() +" - " + "MarkUp text editor");
}

MainWindow::~MainWindow()
{
    delete ui;
}

