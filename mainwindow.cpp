#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "qstring.h"
#include "qtransform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(analyzeNumber()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::analyzeNumber()
{
    int number = ui->lineEdit->text().toInt();
    QString description;

    if (number < 0)
        description =
QString::fromUtf8("отрицательное ");
    else if (number > 0)
        description =
QString::fromUtf8("положительное ");
    else
        description =
QString::fromUtf8("ноль");

    if (number >= -9 && number <= 9)
        description +=
QString::fromUtf8(" однозначное число");
    else if (number >= -99 && number <= 99)
        description +=
QString::fromUtf8(" двузначное число");
    else if (number >= -999 && number <= 999)
        description +=
QString::fromUtf8(" трехзначное число");

    qDebug() << "Вывод в QLabel: " << description;

    ui->label->setText(QString::fromUtf8(description.toUtf8()));
}
