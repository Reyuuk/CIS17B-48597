#ifndef TAGREADER_H
#define TAGREADER_H

#include <QMainWindow>

namespace Ui {
class tagreader;
}

class tagreader : public QMainWindow
{
    Q_OBJECT

public:
    explicit tagreader(QWidget *parent = 0);
    ~tagreader();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tagreader *ui;
};

#endif // TAGREADER_H
