#include "musicorganizer.h"
#include "ui_musicorganizer.h"


MusicOrganizer::MusicOrganizer(QWidget *parent) : QMainWindow(parent), ui(new Ui::MusicOrganizer){
    ui->setupUi(this);
    createMenu();
    createToolBar();
    createStatusBar();
    setupTreeView();
}

MusicOrganizer::~MusicOrganizer(){
    delete ui;
}

void MusicOrganizer::createToolBar(){
    ui->mainToolBar->addAction(openAction);
    ui->mainToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
}

void MusicOrganizer::createStatusBar(){
    ui->statusBar->showMessage(tr("Ready"));
}


void MusicOrganizer::createMenu(){

    openAction = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the document to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setShortcuts(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));


    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    //exitAction = fileMenu->addAction(tr("E&xit"));
    //menuBar()->addMenu(fileMenu);
    //connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));


    cutAction = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
    cutAction->setShortcuts(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    //connect(cutAction, SIGNAL(triggered()), textEdit, SLOT(cut()));

    copyAction = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
    copyAction->setShortcuts(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    //connect(copyAction, SIGNAL(triggered()), textEdit, SLOT(copy()));

    pasteAction = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
    pasteAction->setShortcuts(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    //connect(pasteAction, SIGNAL(triggered()), textEdit, SLOT(paste()));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));


    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    fileMenu = ui->menuBar->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = ui->menuBar->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    ui->menuBar->addSeparator();

    helpMenu = ui->menuBar->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    //cutAction->setEnabled(false);

    //copyAction->setEnabled(false);
    //connect(textEdit, SIGNAL(copyAvailable(bool)),
    //        cutAction, SLOT(setEnabled(bool)));
    //connect(textEdit, SIGNAL(copyAvailable(bool)),
    //        copyAction, SLOT(setEnabled(bool)));
}

void MusicOrganizer::setupTreeView(){
    model = new QFileSystemModel(this);
    model->setReadOnly(false);
    model->setRootPath("C:\\");
    //model->setFilter(QDir::DirsFirst);


    ui->docTree->setModel(model);
    QModelIndex index = model->index(curFile);

    //ui->docTree->expand(index);
    ui->docTree->scrollTo(index);
    ui->docTree->setCurrentIndex(index);
    ui->docTree->resizeColumnToContents(0);

}

void MusicOrganizer::closeEvent(QCloseEvent *event){
    if (maybeSave()){
        //writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void MusicOrganizer::open(){
    //ID3_Tag tag("song.mp3");

    //tag.get


    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }

}

void MusicOrganizer::loadFile(const QString &fileName){
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    setCurrentFile(fileName);
    ID3_Tag tag(curFile.toStdString().c_str());
    ID3_Frame *frame = tag.Find(ID3FID_TITLE);
    //ID3_Field *title = frame->GetField(ID3FID_TITLE);
    char *title[1024] = frame->Field(ID3FN_TEXT).Get(title,1024);



    statusBar()->showMessage(( "File loaded"), 2000);
}

void MusicOrganizer::setCurrentFile(const QString &fileName){
    curFile = fileName;
    //textEdit->document()->setModified(false);
    //setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    setWindowFilePath(shownName);
}

bool MusicOrganizer::save(){
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}



bool MusicOrganizer::maybeSave(){
    //if (/*changes to files not saved*/) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Application"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return true;//save();
        else if (ret == QMessageBox::Cancel)
            return false;
    //}
    return true;
}



bool MusicOrganizer::saveFile(const QString &fileName){
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }



    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

QString MusicOrganizer::strippedName(const QString &fullFileName){
    return QFileInfo(fullFileName).fileName();
}

void MusicOrganizer::about(){
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}



void MusicOrganizer::on_copyToID3v2_clicked(){

}



void MusicOrganizer::on_titleEdit2_textEdited(const QString &arg1){

}
