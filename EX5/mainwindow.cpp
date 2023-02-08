#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    strModel = new QStringListModel(this);
    QStringList list;
    list << "Строка 1" << "Строка 2" << "Строка 3" << "Строка 4";
    strModel->setStringList(list);
    ui->listView->setModel(strModel);
    model = new QStandardItemModel(this);
    ui->listView->setModel(model);
    model->appendRow(new QStandardItem(QIcon("../src/Cplus.png"),"C++"));
    model->appendRow(new QStandardItem(QIcon("../src/Py.png"),"Python"));
    model->appendRow(new QStandardItem(QIcon("../src/java.png"),"Java"));
    model->appendRow(new QStandardItem(QIcon("../src/C.png"),"C#"));
    model->appendRow(new QStandardItem(QIcon("../src/Php.png"),"PHP"));
    model->appendRow(new QStandardItem(QIcon("../src/Js.png"),"JavaScript"));
    ui->listView->setDragDropMode(QAbstractItemView::DragDrop);
    ui->listView->setDefaultDropAction(Qt::MoveAction);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
            ui->listView->setViewMode(QListView::IconMode);
    else
            ui->listView->setViewMode(QListView::ListMode);
}

void MainWindow::on_del_button_clicked()
{
    int row = ui->listView->currentIndex().row();
    model->removeRow(row);
}

void MainWindow::on_pushButton_clicked()
{
    model->appendRow(new QStandardItem(QIcon("../src/X.png"),ui->lineEdit->text()));
}
