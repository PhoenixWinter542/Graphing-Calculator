#include "mainwindow.h"
#include "./ui_mainwindow.h"

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


void MainWindow::on_DrawButton_clicked()
{
    ui->EquationList->addItem(ui->EnterEquation->text());

    std::cout << ui->EnterEquation->text().toStdString();
}

void MainWindow::on_EquationList_currentIndexChanged(const QString &arg1)
{
    // generate points and graph
    Interpreter III(ui->EnterEquation->text().toStdString());
    std::vector<double> temp;
    std::vector<double> temp2;
    temp.push_back(3.2);
    temp.push_back(43.55);
    temp.push_back(300);
    temp2.push_back(40);
    temp2.push_back(100);
    temp2.push_back(90);

    ui->graph->drawGraph(temp, temp2);
}
