#include "tagreader.h"
#include "ui_tagreader.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

tagreader::tagreader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tagreader)
{
    ui->setupUi(this);
}

tagreader::~tagreader()
{
    delete ui;
}

void tagreader::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open mp3 file"),"C://","MP3 Files (*.mp3)");
    QMessageBox::information(this, tr("MP3 File"), filename);

    //QDir::rename(filename, newFileName);
}
