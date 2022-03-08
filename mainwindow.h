#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QList>
#include <math.h>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

private:
    Ui::MainWindow *ui;

    int xShift, yShift, scale, buttonSize;

    float angleUnit;

    QList<QPushButton *> buttonList;

    void buttonAnimation();

   int randomColor();
};
#endif // MAINWINDOW_H
