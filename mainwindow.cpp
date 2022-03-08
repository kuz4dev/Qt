#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Button Animation");

    ui->pushButton_plus->setStyleSheet("background-color: rgba(" + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%)");
    ui->pushButton_minus->setStyleSheet("background-color: rgba(" + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%)");

    srand(time(0));

    buttonSize = 50;
    scale = 150; xShift = 200; yShift = 200;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_plus_clicked()
{
    ui->pushButton_minus->setEnabled(true);

    ui->pushButton_plus->setStyleSheet("background-color: rgba(" + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%)");

    QPushButton* button = new QPushButton(this);
    button->setText(QString::number(buttonList.size() + 1));
    button->setGeometry(ui->pushButton_plus->geometry());
    button->setStyleSheet("background-color: rgba(" + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%)");
    button->show();
    buttonList.append(button);

    buttonAnimation();
}


void MainWindow::on_pushButton_minus_clicked()
{
    ui->pushButton_minus->setStyleSheet("background-color: rgba(" + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%, " + QString::number(randomColor()) + "%)");

    QPushButton* button = buttonList.last();
    buttonList.removeLast();

    delete button;

    buttonAnimation();

    if (buttonList.isEmpty())
    {
        QMessageBox::information(this, "Ошибка!", "Кнопок больше нет!");
        ui->pushButton_minus->setEnabled(false);
    }
}

void MainWindow::buttonAnimation()
{
    int buttonCount = buttonList.size();
    angleUnit = 6.28 / buttonCount;

    for (int i = 0; i < buttonCount; i++)
    {
        QPushButton* button = buttonList.at(i);
        QPropertyAnimation* animation = new QPropertyAnimation(button,"geometry");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::Linear);
        animation->setEndValue(QRectF(cos(angleUnit * i) * scale + xShift, sin(angleUnit * i) * scale + yShift, buttonSize, buttonSize));
        animation->start();
    }
}

int MainWindow::randomColor()
{
    return (1 + rand() % (100 - 1));
}


