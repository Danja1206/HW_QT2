#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parsetext.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_plainTextEdit_textChanged()
{
    QString txt = ui->plainTextEdit->toPlainText();
    qint32 pos = 0;
    while(1)
    {
        qint32 find = txt.indexOf("#@",pos);
        if(find == -1) return;
        pos = find + 1;
        int secondSymbol = txt.indexOf("@", find+2);
        if(secondSymbol != -1)
        {
            ParseText parseText;
            ui->plainTextEdit->setPlainText(parseText.getText(txt.mid(find + 2, secondSymbol - 2)));
        }


    }
}
