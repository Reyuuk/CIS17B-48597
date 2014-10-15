#ifndef MUSICORGANIZER_H
#define MUSICORGANIZER_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog> //To open single file
#include <QFileSystemModel>
#define ID3LIB_LINKOPTION LINKOPTION_STATIC
#include <id3.h>
#include <id3/tag.h>

namespace Ui {
class MusicOrganizer;
}

class MusicOrganizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MusicOrganizer(QWidget *parent = 0);
    ~MusicOrganizer();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void open();
    bool save();
    void about();
    void on_copyToID3v2_clicked();
    void on_titleEdit2_textEdited(const QString &arg1);

private:
    Ui::MusicOrganizer *ui;
    void createMenu();
    bool maybeSave();
    void createToolBar();
    void createStatusBar();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    void setupTreeView();

    QFileSystemModel *model;
    QString curFile;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *editToolBar;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
};

#endif // MUSICORGANIZER_H
